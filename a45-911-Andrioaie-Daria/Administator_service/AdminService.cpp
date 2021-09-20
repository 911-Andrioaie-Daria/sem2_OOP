//
// Created by daria on 20/03/2021.
//

#include "AdminService.h"

//default constructor
//AdminService::AdminService(){
//
//}

//parameter constructor
AdminService::AdminService(DogRepository *repository, DogValidator* validator) {
    this->repository = repository;
    this->validator = validator;
}

bool AdminService::add_dog_service(string dog_breed, string dog_age, string dog_name, string dog_photograph){
    DogValidator* dogValidator = this->get_dog_validator();
    DogRepository* dogRepository = this->get_repository();

    if(dogValidator->validate_age(dog_age) && dogValidator->validate_breed(dog_breed) &&
    dogValidator->validate_name(dog_name) && dogValidator->validate_photograph(dog_photograph)){
        int dog_age_as_int = stoi(dog_age);
        Dog new_dog(dog_breed, dog_age_as_int, dog_name, dog_photograph);
        if(dogRepository->add_dog_to_repository(new_dog))
            return true;
        return false;
    }
    return false;
}

bool AdminService::delete_dog_service(string dog_breed, string dog_name){
    DogValidator* dogValidator = this->get_dog_validator();
    DogRepository* dogRepository = this->get_repository();

    if(dogValidator->validate_breed(dog_breed) && dogValidator->validate_name(dog_name)){
        if(dogRepository->delete_dog_from_repository(dog_breed, dog_name))
            return true;
        return false;
    }
    return false;
}

bool AdminService::update_dog_age(string dog_breed, string dog_name, string new_dog_age){
    DogValidator* dogValidator = this->get_dog_validator();
    DogRepository* dogRepository = this->get_repository();

    if(dogValidator->validate_age(new_dog_age) && dogValidator->validate_breed(dog_breed) &&
       dogValidator->validate_name(dog_name)){
        int new_dog_age_as_int = stoi(new_dog_age);
        if(dogRepository->update_dog_age_in_repo(dog_breed, dog_name, new_dog_age_as_int))
            return true;
        return false;
    }
    return false;
}

bool AdminService::update_dog_photograph(string dog_breed, string dog_name, string new_dog_photograph){
    DogValidator* dogValidator = this->get_dog_validator();
    DogRepository* dogRepository = this->get_repository();

    if(dogValidator->validate_breed(dog_breed) && dogValidator->validate_name(dog_name) &&
    dogValidator->validate_photograph(new_dog_photograph)){
        if(dogRepository->update_dog_photograph_in_repo(dog_breed, dog_name, new_dog_photograph))
            return true;
        return false;
    }
    return false;
}


DogRepository* AdminService::get_repository(){
    return this->repository;
}

DynamicArray<Dog>* AdminService::get_dynamic_array(){
    return this->repository->get_dynamic_array();
}

DogValidator* AdminService::get_dog_validator(){
    return this->validator;
}

// destructor
AdminService::~AdminService(){
    delete this->repository;
    delete this->validator;
}