//
// Created by daria on 22/06/2021.
//

#include <iostream>
#include "QApplication"
#include "GUI.h"

int main(int argc, char** argv) {
    QApplication a{argc, argv};

    Repository repository;
    Service service{repository};
    GUI gui{service};

    return a.exec();
}
