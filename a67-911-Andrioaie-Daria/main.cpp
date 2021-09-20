//
// Created by daria on 21/03/2021.
//

#include "Tests/TestAll.h"
#include "FileRepository.h"
#include "DogValidator.h"
#include "AdminService.h"
#include "UserService.h"
#include "ConsoleUI.h"
#include <crtdbg.h>


int main() {

    //run_all_tests();

    FileRepository repository(R"(C:\Users\daria\Documents\study\facultate\anul 1\semestrul 2\OOP\a67-911-Andrioaie-Daria\dogs.txt)");
    //DogRepository repository;
    //repository.init();

    DogValidator validator;

    AdminService adminService{repository, validator};
    UserService userService{repository};

    UserInterface userInterface{adminService, userService};

    userInterface.start_program();

    //delete userInterface;

    _CrtDumpMemoryLeaks();

    return 0;
}
