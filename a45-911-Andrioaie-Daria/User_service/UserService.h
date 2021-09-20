//
// Created by daria on 24/03/2021.
//

#ifndef A45_911_ANDRIOAIE_DARIA_USERSERVICE_H
#define A45_911_ANDRIOAIE_DARIA_USERSERVICE_H
#include "DogRepository.h"

class UserService {
private:
    DogRepository* repository;
    DynamicArray<Dog>* adopted_dogs;
    DynamicArray<Dog>* dogs_filtered_by_breed;
    int dog_index_in_show_list;

public:
    /// default constructor
    UserService()=default;

    /// parameter constructor
    UserService(DogRepository* dog_repository);

    /// The function filters the dogs in the database by a given breed,
    /// always storing the result of the filtering in this->dogs_filtered_by_breed;
    /// \param dog_breed: can be either a specific breed or an empty string,
    /// case in which all the dogs in the database will be stored in the filtered list.
    void filter_dogs_by_breed(string dog_breed);

    /// The function adds a dog to the list of adopted dogs and calls the method which
    /// removes the adopted dog from the repository.
    /// \param lucky_dog: the instance of the class Dog that is adopted.
    void adopt_dog(Dog lucky_dog);

    /// Getter function for the repository under the service.
    DogRepository* get_repository();

    /// Getter function for the list of adopted dogs.
    DynamicArray<Dog>* get_adopted_dogs();

    /// Getter function for the list of dogs filtered by breed.
    DynamicArray<Dog>* get_dogs_filtered();

    /// Getter function for the current dog inside the list of dogs filtered by breed.
    Dog get_current_dog();

    /// Getter function for the index of the current dog inside the list of dogs filtered by breed.
    int get_dog_index() const;

    /// Function that increments the index of the current dog inside the list of dogs filtered by breed
    void increment_dog_index();

    /// destructor
    ~UserService();

};



#endif //A45_911_ANDRIOAIE_DARIA_USERSERVICE_H
