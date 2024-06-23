#include <QApplication>
#include <QPushButton>
#include "Repository/Repository.h"
#include "GUI/GUI.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
//    QApplication a(argc, argv);
//    a.setStyle("fusion");
//    Repository repo(20, 20, 50);
//    GUI gui{repo};
//    gui.show();
//    return QApplication::exec();
    Repository repo(5, 5, 4);
    while (1) {
        std::cout << repo;
        std::cout << "Input cmmd, then row and col to reveal:\n";
        int row;
        int col;
        std::string cmmd;
        std::cin.ignore();
        std::getline(std::cin, cmmd);
        std::cin >> row;
        std::cin >> col;
        if (cmmd == "f" || cmmd == "flag") {
            repo.flagSquare(row, col);
        } else {
            repo.revealSquare(row, col);
        }
    }

}
