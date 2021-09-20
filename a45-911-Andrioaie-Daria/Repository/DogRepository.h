//
// Created by daria on 20/03/2021.
//

#ifndef A45_911_ANDRIOAIE_DARIA_DOGREPOSITORY_H
#define A45_911_ANDRIOAIE_DARIA_DOGREPOSITORY_H
#include "Dog.h"
#include "DynamicArray.h"

class DogRepository {
private:
    DynamicArray<Dog>* dynamic_array;

public:
    ///Constructor
    DogRepository(DynamicArray<Dog>* dog_dynamic_array);

    ///Destructor
    ~DogRepository();

    /// Function that initialises the repository with 10 elements of type Dog.
    void initialise_repository();

    /// Getter function for the size of the repository.
    int get_size();

    /// Getter function for the dynamic array of the repository.
    DynamicArray<Dog>* get_dynamic_array();

    /// Function that adds a dog in the repository.
    /// \param new_dog instance of the class Dog
    /// \return true, if the dog was added successfully, false, if there already exists a dog with the given attributes
    bool add_dog_to_repository(Dog new_dog);

    /// Function that deletes a dog from the repository
    /// \param dog_breed: the dog is identified by its breed and name
    /// \param dog_name
    /// \return: true, if the dog was deleted successfully, false, if the dog could not be identified inside the repository.
    bool delete_dog_from_repository(string dog_breed, string dog_name);

    /// Function that updates the age of a dog inside the repo
    /// \param dog_breed: the dog is identified by its breed and name
    /// \param dog_name
    /// \param new_dog_age: the new age of the dog
    /// \return: true, if the dog was updated successfully, false, if the dog could not be identified inside the repository.
    bool update_dog_age_in_repo(string dog_breed, string dog_name, int new_dog_age);

    /// Function that updates the photograph of a dog inside the repo
    /// \param dog_breed: the dog is identified by its breed and name
    /// \param dog_name
    /// \param new_dog_photograph: the new photo of the dog
    /// \return: true, if the dog was updated successfully, false, if the dog could not be identified inside the repository.
    bool update_dog_photograph_in_repo(string dog_breed, string dog_name, string new_dog_photograph);

    /// Function that searches for the dog with the given breed and name inside the repo
    /// \return: the index of the dog in the repo or -1, if the dog is not in the repo.
    int search_dog_in_repository(string dog_breed, string dog_name);
};


#endif //A45_911_ANDRIOAIE_DARIA_DOGREPOSITORY_H
