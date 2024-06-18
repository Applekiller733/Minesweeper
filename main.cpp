#include <QApplication>
#include <QPushButton>
#include "Repository/Repository.h"
#include "GUI/GUI.h"
#include <iostream>

int main(int argc, char *argv[]) {
//    QApplication a(argc, argv);
//    a.setStyle("fusion");
//    Repository repo(20, 20, 50);
//    GUI gui{repo};
//    gui.show();
//    return QApplication::exec();
    Repository repo(20, 20, 50);
    while (1) {
        std::cout << repo;
        std::cout << "Input row and col to reveal:\n";
        int row; int col;
        std::cin >> row;
        std::cin >> col;
        repo.revealSquare(row, col);
    }

}
