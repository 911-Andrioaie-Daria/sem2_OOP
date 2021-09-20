//
// Created by daria on 22/03/2021.
//

#include "RepositoryTests.h"
#include "DogRepository.h"
#include <assert.h>

void test_initialise_repository(){
    DynamicArray<Dog>* dynamic_array = new DynamicArray<Dog>(10);
    DogRepository* repository = new DogRepository(dynamic_array);
    repository->initialise_repository();
    int size = repository->get_size();
    assert(size == 10);

    delete repository;
}

void test_add_to_repo(){
    DynamicArray<Dog>* dynamic_array = new DynamicArray<Dog>(10);
    DogRepository* repository = new DogRepository(dynamic_array);
    repository->initialise_repository();
    Dog new_dog("Husky", 2, "Leon", "https://dasa.ro");
    assert(repository->add_dog_to_repository(new_dog) == true);

    Dog already_existing_dog("Australian Shepherd", 5, "Milo", "https://australiansheperd2.ro");
    assert(repository->add_dog_to_repository(already_existing_dog) == false);

    delete repository;
}

void test_delete_from_repo(){
    DynamicArray<Dog>* dynamic_array = new DynamicArray<Dog>(10);
    DogRepository* repository = new DogRepository(dynamic_array);
    repository->initialise_repository();

    string existing_dog_breed = "Australian Shepherd";
    string existing_dog_name = "Milo";
    assert(repository->delete_dog_from_repository(existing_dog_breed, existing_dog_name) == true);

    string non_existent_dog_breed = "Terrier";
    string non_existent_dog_name = "Max";
    assert(repository->delete_dog_from_repository(non_existent_dog_breed, non_existent_dog_name) == false);

    delete repository;
}

void test_update_in_repo(){
    DynamicArray<Dog>* dynamic_array = new DynamicArray<Dog>(10);
    DogRepository* repository = new DogRepository(dynamic_array);
    repository->initialise_repository();

    string existing_dog_breed = "Australian Shepherd";
    string existing_dog_name = "Milo";
    assert(repository->update_dog_age_in_repo(existing_dog_breed, existing_dog_name, 10) == true);
    assert(repository->update_dog_photograph_in_repo(existing_dog_breed, existing_dog_name, "https://ddddxsw.ro") == true);

    string non_existent_dog_breed = "Terrier";
    string non_existent_dog_name = "Max";
    assert(repository->update_dog_age_in_repo(non_existent_dog_breed, non_existent_dog_name, 10) == false);
    assert(repository->update_dog_photograph_in_repo(non_existent_dog_breed, non_existent_dog_name, "https://ddddxsw.ro") == false);

    delete repository;
}

void run_all_repository_tests(){
    test_initialise_repository();
    test_add_to_repo();
    test_delete_from_repo();
    test_update_in_repo();
}