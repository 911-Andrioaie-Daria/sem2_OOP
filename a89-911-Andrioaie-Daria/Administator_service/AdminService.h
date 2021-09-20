//
// Created by daria on 20/03/2021.
//

#ifndef A45_911_ANDRIOAIE_DARIA_ADMINSERVICE_H
#define A45_911_ANDRIOAIE_DARIA_ADMINSERVICE_H
#include "Dog.h"
#include "DogRepository.h"
#include "DogValidator.h"

class AdminService {

private:
    DogRepository& repository;
    DogValidator& validator;


public:
//    /// Default constructor
//    AdminService();

    /// Parameter constructor
    AdminService(DogRepository& repository, DogValidator& validator);

//    /// Getter function for the size of the repository inside the adminService.
//    int get_size();

    /// Function that adds a dog with the given attributes in the adminService, after validating each attribute.
    /// \return true, if the dog was added, false, if the dog is already in the repo or its attributes are not valid.
    void add_dog(const string& dog_breed, const string& dog_age, const string& dog_name, const string& dog_photograph);

    /// Function that deletes the dog identified by the given name and breed from the repository.
    /// \return true, if the dog was deleted, false, if the dog does not exist or its attributes are not valid.
    void delete_dog(const string& dog_breed, const string& dog_name);

    /// Function that updates the age of the dog identified by the given name and breed from the repository.
    /// \param new_dog_age: the new age of the dog
    /// \return true, if the dog was updated, false, if the dog does not exist or its attributes are not valid.
    void update_dog_age(const string& dog_breed, const string& dog_name, const string& new_dog_age);

    /// Function that updates the photograph of the dog identified by the given name and breed from the repository.
    /// \param new_dog_photograph: the new photograph of the dog
    /// \return true, if the dog was updated, false, if the dog does not exist or its attributes are not valid.
    void update_dog_photograph(const string& dog_breed, const string& dog_name, const string& new_dog_photograph);

    /// Getter function for the repository inside the adminService.
    DogRepository& get_repository();

    /// Getter function for the dynamic array inside the repo.
    vector<Dog> get_dog_array();

    /// Getter function for the validator of a dog
    DogValidator& get_dog_validator();

    /// Destructor
    ~AdminService();

};


#endif //A45_911_ANDRIOAIE_DARIA_ADMINSERVICE_H
