//
// Created by ANDREI on 18-Jun-24.
//

#include "Square.h"


Square::Square() {
    this->isFlagged = false;
    this->isRevealed = false;
    this->isMine = false;
}

Square::Square(int row, int col) {
    this->row = row;
    this->col = col;
    this->isFlagged = false;
    this->isRevealed = false;
    this->isMine = false;
}

void Square::setFlag() {
    if (!this->isRevealed) {
        if (!this->isFlagged)
            this->isFlagged = true;
        else
            this->isFlagged = false;

    }
}

bool Square::getFlag() {
    return this->isFlagged;
}