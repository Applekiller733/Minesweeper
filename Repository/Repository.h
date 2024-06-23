//
// Created by ANDREI on 18-Jun-24.
//

#ifndef MINESWEEPER_REPOSITORY_H
#define MINESWEEPER_REPOSITORY_H
#include "../Domain/Square.h"
#include <vector>
#include <iostream>

class Repository {
private:
    bool firstclick = true;
    int rowcnt = 9;
    int colcnt = 9;
    int minecnt = 0;
    bool firstreveal = true;
    int revealed = 0;
    std::vector<std::vector<Square>> board;
public:
    Repository(int rowcnt, int colcnt, int minecnt);
    void generateMines();
    void generateCounts();
    void parseNeighborsCnt(int row, int col);
    void addSquare(int row, int col);
    void mineSquare(int row, int col);
    bool validRow(int row);
    bool validCol(int col);
    bool checkMine(int row, int col);
    bool checkFlagged(int row, int col);

    void blankifyArea(int row, int col);
    void revealBlanks(int row, int col);
    void parseNeighborsRev(int row, int col);
    void revealSquare(int row, int col);
    void flagSquare(int row, int col);

    bool checkWinCond();

    friend std::ostream& operator<<(std::ostream& os, Repository repo){

        for(int i = 0; i < repo.rowcnt; i++) {
            for (int j = 0; j < repo.colcnt; j++) {
                if (repo.board[i][j].getReveal()) {
                    if (!repo.board[i][j].getMine())
                        if (repo.board[i][j].getCount() > 0)
                            os << repo.board[i][j].getCount() << " ";
                        else
                            os << "." << " ";
                    else
                        os << "M" << " ";
                }
                else if (!repo.checkFlagged(i, j))
                    os << "?" << " ";
                else
                    os << "F" << " ";
            }
            os << "\n";
        }
        return os;
    };

};


#endif //MINESWEEPER_REPOSITORY_H
