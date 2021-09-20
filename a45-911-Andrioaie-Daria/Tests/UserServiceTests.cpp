//
// Created by daria on 25/03/2021.
//

#include "UserServiceTests.h"
#include "UserService.h"
#include <assert.h>

UserService* initialise_user_service(){
    DynamicArray<Dog>* dynamic_array = new DynamicArray<Dog>(100);
    DogRepository* repository = new DogRepository(dynamic_array);
    repository->initialise_repository();

    UserService* userService = new UserService(repository);
    return userService;
}

void test_filter_dogs_by_breed(){
    UserService* userService = initialise_user_service();

    string dog_breed = "Labrador";
    userService->filter_dogs_by_breed(dog_breed);
    int filtered_dogs_count = userService->get_dogs_filtered()->getSize();
    assert(filtered_dogs_count == 2);

    dog_breed = "";
    userService->filter_dogs_by_breed(dog_breed);
    filtered_dogs_count = userService->get_dogs_filtered()->getSize();
    assert(filtered_dogs_count == 10);

    delete userService->get_repository();
    delete userService;
}

void test_adopt_dog(){
    UserService* userService = initialise_user_service();
    string dog_breed = "Labrador";
    userService->filter_dogs_by_breed(dog_breed);

    Dog current_dog = userService->get_current_dog();
    userService->adopt_dog(current_dog);

    DynamicArray<Dog>* list_of_adopted_dogs = userService->get_adopted_dogs();
    assert(list_of_adopted_dogs->getSize() == 1);

    DogRepository* dog_repository = userService->get_repository();
    assert(dog_repository->get_size() == 9);

    delete userService->get_repository();
    delete userService;
}

void test_getters_user_service(){
    UserService* userService = initialise_user_service();

    DogRepository* dogRepository = userService->get_repository();
    assert(dogRepository != nullptr);

    DynamicArray<Dog>* adoptedDogs = userService->get_adopted_dogs();
    assert(adoptedDogs != nullptr);

    DynamicArray<Dog>* filteredDogs = userService->get_dogs_filtered();
    assert(filteredDogs != nullptr);

    Dog current_dog = userService->get_current_dog();
    assert(current_dog.get_dog_breed() == "");

    int dog_index = userService->get_dog_index();
    assert(dog_index != -1);

    userService->increment_dog_index();
    int incremented_index = userService->get_dog_index();
    assert(incremented_index - dog_index == 1);

    delete userService->get_repository();
    delete userService;
}

void run_all_user_service_tests(){
    test_getters_user_service();
    test_filter_dogs_by_breed();
    test_adopt_dog();
}