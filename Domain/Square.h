//
// Created by ANDREI on 18-Jun-24.
//

#ifndef MINESWEEPER_SQUARE_H
#define MINESWEEPER_SQUARE_H


class Square {
private:
    int nearbymines = 0;
    bool isMine;
    bool isFlagged;
    bool isRevealed;
    int row;
    int col;
public:
    Square();
    Square(int row, int col);
    void incrementCount(){this->nearbymines++;};
    void decrementCount(){this->nearbymines--;};
    int getCount(){return this->nearbymines;};
    void setMine(){this->isMine = true;};
    void removeMine(){this->isMine = false;}
    bool getMine(){return this->isMine;};
    void setFlag();
    bool getFlag();
    void setReveal(){this->isRevealed = true;};
    bool getReveal(){return this->isRevealed;};
};


#endif //MINESWEEPER_SQUARE_H
