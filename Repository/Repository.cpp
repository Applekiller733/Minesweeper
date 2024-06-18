//
// Created by ANDREI on 18-Jun-24.
//

#include "Repository.h"
#include <cstdlib>
#include <ctime>


Repository::Repository(int rowcnt, int colcnt, int minecnt) {
    this->rowcnt = rowcnt;
    this->colcnt = colcnt;
    this->minecnt = minecnt;
    srand(std::time(NULL));
    this->board = std::vector<std::vector<Square>>(rowcnt, std::vector<Square>(colcnt));

    for(int i = 0; i < this->rowcnt; i++)
        for(int j = 0; j < this->colcnt; j++){
            this->addSquare(i, j);
        }
    std::cout << "Finished adding squares\n";
    this->generateMines();
    std::cout << "Finished generating mines \n";
    this->generateCounts();
    std::cout << "Finished generating counts \n";
}

void Repository::addSquare(int row, int col) {
    Square newsqr(row, col);
    this->board[row][col] = newsqr;
}

bool Repository::checkMine(int row, int col) {
    if (this->board[row][col].getMine())
        return true;
    return false;
}

bool Repository::validRow(int row) {
    return (row >= 0 && row < this->rowcnt);
}

bool Repository::validCol(int col) {
    return (col >= 0 && col < this->colcnt);
}

void Repository::flagSquare(int row, int col) {
    this->board[row][col].setFlag();
}

void Repository::mineSquare(int row, int col) {
    this->board[row][col].setMine();
}

void Repository::generateMines() {
    /*Randomly generates mine layout*/
    int auxminecnt = this->minecnt;
    while (auxminecnt > 0){
        int row = rand() % this->rowcnt;
        int col = rand() % this->colcnt;
        if (!this->checkMine(row, col))
        {
            std::cout << "Added mine on row " << row <<" and col " << col << "\n";
            this->mineSquare(row, col);
            auxminecnt --;
        }
    }
}

void Repository::parseNeighborsCnt(int row, int col) {
    /*Parses neighbors of square at given row and col, checking if they are mines, and incrementing count if so*/
    for(int r = row - 1; r <= row + 1; r++)
        for (int c = col - 1; c <= col + 1; c++){
            if( this->validRow(r) && this->validCol(c) ){
                if (this->checkMine(r, c)){
                    this->board[row][col].incrementCount();
                }
            }
        }
}

void Repository::generateCounts() {
    /*Generates the mine count of each square close to a mine(/s)*/
    std::cout << "rowcnt: " << this->rowcnt << " colcnt: " << this->colcnt << "\n";
    for(int i = 0; i < this->rowcnt; i++) {
        for (int j = 0; j < this->colcnt; j++) {
            if (!this->checkMine(i, j)) {
                std::cout << "Parsing neighbors of row " << i << " col " << j << "\n";
                this->parseNeighborsCnt(i, j);
            } else
                std::cout << "Encountered mine at row " << i << " col " << j << "\n";
        }
    }
}

void Repository::parseNeighborsRev(int row, int col) {
    /*
     * Parses the neighbors of square at given row and col, revealing them.*/
    for(int r = row - 1; r <= row + 1; r++)
        for (int c = col - 1; c <= col + 1; c++){
            if( this->validRow(r) && this->validCol(c) && (r != row || c != col)) {
                if (this->board[r][c].getCount() == 0) {
                    if (!this->board[r][c].getReveal()) {
                        this->revealSquare(r, c);
                    }
                } else {
                    this->revealSquare(r, c);
                }
            }
        }
}

void Repository::revealBlanks(int row, int col) {
    /*Reveals the neighbors around the blank square*/
    if (this->validRow(row) && this->validCol(col)){
        this->parseNeighborsRev(row, col);
    }
}

void Repository::blankifyArea(int row, int col) {
    /*
     * Function ensures the block clicked and the blocks surrounding it are not going to be mines by
     * deleting them. This is a form of first click safety*/
            if (this->validRow(row) && this->validCol(col)){
                if (this->checkMine(row, col)) {
                    this->board[row][col].removeMine();
                    this->minecnt --;
                    for (int i = row - 1; i <= row + 1; i++)
                        for(int j = col - 1; j <= col + 1; j++){
                            if (this->validRow(i) && this->validCol(j)) {
                                if (this->checkMine(i, j))
                                    blankifyArea(i, j);
                                else if ( i != row || j != col ) {
                                    this->board[i][j].decrementCount();
                                }
                            }
                        }
                }
                this->revealSquare(row, col);
            }
}

void Repository::revealSquare(int row, int col) {
    /*
     * Function reveals the square at a given row and column.
     * If the square is blank, it will call revealBlanks, which will reveal all blanks around it
     * If the square is a mine, game is over
     * If it is the first click, game ensures first clicked square and area around it is not made of mines*/
    if (this->validRow(row) && this->validCol(col)) {
        if (this->firstclick) {
            //set click area blank
            this->firstclick = false;
            this->blankifyArea(row, col);
        } else {
            this->board[row][col].setReveal();
            if (this->checkMine(row, col)){
                std::cout << "Game over!\n";
                exit(0);
            }
            if (this->board[row][col].getCount() == 0){
                this->revealBlanks(row, col);
            }
        }
    }
}

