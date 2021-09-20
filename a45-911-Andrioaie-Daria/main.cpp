//
// Created by daria on 21/03/2021.
//

#include "Tests/TestAll.h"
#include "Dog.h"
#include "DynamicArray.h"
#include "DogRepository.h"
#include "DogValidator.h"
#include "AdminService.h"
#include "UserService.h"
#include "ConsoleUI.h"
#include <crtdbg.h>


int main() {

    run_all_tests();

    DynamicArray<Dog>* dynamic_array = new DynamicArray<Dog>(100);
    DogRepository* repository = new DogRepository(dynamic_array);
    repository->initialise_repository();

    DogValidator* validator = new DogValidator();

    AdminService* adminService = new AdminService(repository, validator);
    UserService* userService = new UserService(repository);

    UserInterface* userInterface = new UserInterface(adminService, userService);

    userInterface->start_program();

    delete userInterface;

    _CrtDumpMemoryLeaks();

    return 0;
}
