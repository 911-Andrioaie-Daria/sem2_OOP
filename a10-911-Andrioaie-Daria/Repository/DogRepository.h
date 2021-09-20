//
// Created by daria on 20/03/2021.
//

#ifndef A45_911_ANDRIOAIE_DARIA_DOGREPOSITORY_H
#define A45_911_ANDRIOAIE_DARIA_DOGREPOSITORY_H
#include "Dog.h"
#include "vector"
#include "CustomException.h"
class DogRepository {
protected:
    vector<Dog> dog_array{};

public:
    ///Constructor
    DogRepository();

    ///Destructor
    virtual ~DogRepository();

    /// Function that initialises the repository with 10 elements of type Dog.
    virtual void init();

    /// Getter function for the size of the repository.
    int get_size();

    /// Getter function for the dynamic array of the repository.
    virtual vector<Dog>& get_dog_array()=0;

    /// Function that adds a dog in the repository.
    /// \param new_dog instance of the class Dog
    /// \return true, if the dog was added successfully, false, if there already exists a dog with the given attributes
    virtual void add_dog(const Dog& new_dog)=0;

    /// Function that deletes a dog from the repository
    /// \param dog_breed: the dog is identified by its breed and name
    /// \param dog_name
    /// \return: true, if the dog was deleted successfully, false, if the dog could not be identified inside the repository.
    virtual void delete_dog(const string& dog_breed, const string& dog_name)=0;

    /// Function that updates the age of a dog inside the repo
    /// \param dog_breed: the dog is identified by its breed and name
    /// \param dog_name
    /// \param new_dog_age: the new age of the dog
    /// \return: true, if the dog was updated successfully, false, if the dog could not be identified inside the repository.
     virtual void update_dog_age(const string& dog_breed, const string& dog_name, int new_dog_age)=0;

     /// Function that updates the photograph of a dog inside the repo
    /// \param dog_breed: the dog is identified by its breed and name
    /// \param dog_name
    /// \param new_dog_photograph: the new photo of the dog
    /// \return: true, if the dog was updated successfully, false, if the dog could not be identified inside the repository.
    virtual void update_dog_photograph(const string& dog_breed, const string& dog_name, const string& new_dog_photograph)=0;

    /// Function that searches for the dog with the given breed and name inside the repo
    /// \return: the index of the dog in the repo or -1, if the dog is not in the repo.
    virtual int search_dog(const string& dog_breed, const string& dog_name)=0;
};


#endif //A45_911_ANDRIOAIE_DARIA_DOGREPOSITORY_H
