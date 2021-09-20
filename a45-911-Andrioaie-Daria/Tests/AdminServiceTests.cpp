//
// Created by daria on 25/03/2021.
//

#include "AdminServiceTests.h"
#include "AdminService.h"
#include <assert.h>

AdminService* initialise_service(){
    DynamicArray<Dog>* dynamic_array = new DynamicArray<Dog>(100);
    DogRepository* repository = new DogRepository(dynamic_array);
    repository->initialise_repository();

    DogValidator* validator = new DogValidator();

    AdminService* adminService = new AdminService(repository, validator);

    return adminService;
}

void test_getters_service(){
    AdminService* adminService = initialise_service();

    DogRepository* dogRepository = adminService->get_repository();
    assert(dogRepository != nullptr);

    DynamicArray<Dog>* dynamicArray = adminService->get_dynamic_array();
    assert(dynamicArray != nullptr);

    DogValidator* dogValidator = adminService->get_dog_validator();
    assert(dogValidator != nullptr);

    delete adminService;
}

void test_add_dog_service(){
    AdminService* adminService = initialise_service();

    /// valid, non-existing dog
    string dog_breed = "Terrier";
    string dog_age = "3";
    string dog_name = "Max";
    string dog_photograph = "https://max.ro";

    bool result = adminService->add_dog_service(dog_breed, dog_age, dog_name, dog_photograph);
    assert(result == true);

    /// valid, but already existing dog
    dog_breed = "Labrador";
    dog_age = "2";
    dog_name = "Louie";
    dog_photograph = "https://labrador1.ro";

    result = adminService->add_dog_service(dog_breed, dog_age, dog_name, dog_photograph);
    assert(result == false);


    /// non-valid dog
    dog_breed = "123";
    dog_age = "abcd";
    dog_name = "456";
    dog_photograph = "abcd";

    result = adminService->add_dog_service(dog_breed, dog_age, dog_name, dog_photograph);
    assert(result == false);

    delete adminService;
}

void test_delete_dog_service(){
    AdminService* adminService = initialise_service();

    /// valid, non-existing dog
    string dog_breed = "Terrier";
    string dog_name = "Max";

    bool result = adminService->delete_dog_service(dog_breed, dog_name);
    assert(result == false);

    /// valid, existing dog
    dog_breed = "Labrador";
    dog_name = "Louie";

    result = adminService->delete_dog_service(dog_breed, dog_name);
    assert(result == true);

    /// non-valid dog
    dog_breed = "123";
    dog_name = "456";
    result = adminService->delete_dog_service(dog_breed, dog_name);
    assert(result == false);

    delete adminService;
}

void test_update_dog_service(){
    AdminService* adminService = initialise_service();

    /// valid, non-existing dog
    string dog_breed = "Terrier";
    string dog_name = "Max";
    string new_age = "10";
    string new_photograph = "https://max.ro";

    bool result = adminService->update_dog_age(dog_breed, dog_name, new_age);
    assert(result == false);

    result = adminService->update_dog_photograph(dog_breed, dog_name, new_photograph);
    assert(result == false);

    /// valid, existing dog
    dog_breed = "Labrador";
    dog_name = "Louie";
    new_age = "10";
    new_photograph = "https://new_louie.ro";

    result = adminService->update_dog_age(dog_breed, dog_name, new_age);
    assert(result == true);

    result = adminService->update_dog_photograph(dog_breed, dog_name, new_photograph);
    assert(result == true);

    /// non-valid dog
    dog_breed = "123";
    dog_name = "456";
    new_age = "gdd";
    new_photograph = "abcd";

    result = adminService->update_dog_age(dog_breed, dog_name, new_age);
    assert(result == false);

    result = adminService->update_dog_photograph(dog_breed, dog_name, new_photograph);
    assert(result == false);


    delete adminService;
}

void run_all_admin_service_tests(){
    test_getters_service();
    test_add_dog_service();
    test_delete_dog_service();
    test_update_dog_service();
}