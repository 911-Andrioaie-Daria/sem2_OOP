//
// Created by daria on 20/03/2021.
//

#include "AdminService.h"

//default constructor
//AdminService::AdminService(){
//
//}

//parameter constructor
AdminService::AdminService(DogRepository& repository, DogValidator& validator): repository{repository}, validator{validator}{
}

void AdminService::add_dog(const string& dog_breed, const string& dog_age, const string& dog_name, const string& dog_photograph){
    DogValidator& dogValidator = this->get_dog_validator();
    DogRepository& dogRepository = this->get_repository();

    DogValidator::validate_age(dog_age);
    DogValidator::validate_breed(dog_breed);
    DogValidator::validate_name(dog_name);
    DogValidator::validate_photograph(dog_photograph);

    int dog_age_as_int = stoi(dog_age);
    Dog new_dog(dog_breed, dog_age_as_int, dog_name, dog_photograph);
    dogRepository.add_dog(new_dog);
}

void AdminService::delete_dog(const string& dog_breed, const string& dog_name){
    DogValidator& dogValidator = this->get_dog_validator();
    DogRepository& dogRepository = this->get_repository();

    DogValidator::validate_breed(dog_breed);
    DogValidator::validate_name(dog_name);

    dogRepository.delete_dog(dog_breed, dog_name);
}

void AdminService::update_dog_age(const string& dog_breed, const string& dog_name, const string& new_dog_age){
    DogValidator& dogValidator = this->get_dog_validator();
    DogRepository& dogRepository = this->get_repository();

    DogValidator::validate_age(new_dog_age);
    DogValidator::validate_breed(dog_breed);
    DogValidator::validate_name(dog_name);

    int new_dog_age_as_int = stoi(new_dog_age);
    dogRepository.update_dog_age(dog_breed, dog_name, new_dog_age_as_int);
}

void AdminService::update_dog_photograph(const string& dog_breed, const string& dog_name, const string& new_dog_photograph){
    DogValidator& dogValidator = this->get_dog_validator();
    DogRepository& dogRepository = this->get_repository();

    DogValidator::validate_breed(dog_breed);
    DogValidator::validate_name(dog_name);
    DogValidator::validate_photograph(new_dog_photograph);

    dogRepository.update_dog_photograph(dog_breed, dog_name, new_dog_photograph);
}


DogRepository& AdminService::get_repository(){
    return this->repository;
}

vector<Dog> AdminService::get_dog_array(){
    return this->repository.get_dog_array();
}

DogValidator& AdminService::get_dog_validator(){
    return this->validator;
}

//// destructor
AdminService::~AdminService()=default;