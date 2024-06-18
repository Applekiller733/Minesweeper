//
// Created by ANDREI on 18-Jun-24.
//

#ifndef MINESWEEPER_GUI_H
#define MINESWEEPER_GUI_H
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include "../Repository/Repository.h"

class GUI : public QWidget {
private:
    Repository& repo;

    QGridLayout* maingrid;
    std::vector<std::vector<QWidget>> matrix;

public:
    GUI(Repository& repo);
    void buildGUI();
};


#endif //MINESWEEPER_GUI_H
