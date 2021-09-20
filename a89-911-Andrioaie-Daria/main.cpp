//
// Created by daria on 21/03/2021.
//

#include "Tests/TestAll.h"
#include "FileRepository.h"
#include "DogValidator.h"
#include "AdminService.h"
#include "UserService.h"
#include "ConsoleUI.h"
#include "AdminGUI.h"
#include "GUI.h"
#include "UserGUI.h"
#include <crtdbg.h>

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication a{ argc, argv };

    //run_all_tests();

    FileRepository repository(R"(C:\Users\daria\Documents\study\facultate\anul 1\semestrul 2\OOP\a89-911-Andrioaie-Daria\dogs.txt)");

    DogValidator validator;

    AdminService adminService{repository, validator};
    UserService userService{repository};

//    UserInterface userInterface{adminService, userService};
//    userInterface.start_program();

    GUI gui{adminService, userService, nullptr};
    gui.show();
    _CrtDumpMemoryLeaks();
    return a.exec();
}
