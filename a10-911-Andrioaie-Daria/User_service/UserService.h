//
// Created by daria on 24/03/2021.
//

#ifndef A45_911_ANDRIOAIE_DARIA_USERSERVICE_H
#define A45_911_ANDRIOAIE_DARIA_USERSERVICE_H

#include <fstream>
#include <windows.h>
#include <shellapi.h>

#include "DogRepository.h"
#include "AbstractAdoptionList.h"
#include <memory>
#include "stack"
#include "Action.h"
typedef stack<std::shared_ptr<Action>> action_stack_t;

class UserService {
private:
    DogRepository& repository;
    AbstractAdoptionList* adopted_dogs{};
    vector<Dog> dogs_filtered_by_breed{};
    int dog_index_in_show_list;
    action_stack_t undoStack;
    action_stack_t redoStack;

public:

    /// parameter constructor
    explicit UserService(DogRepository& dog_repository);

    void setCSVFile();

    void setHTMLFile();

    /// The function filters the dogs in the database by a given breed,
    /// always storing the result of the filtering in this->dogs_filtered_by_breed;
    /// \param dog_breed: can be either a specific breed or an empty string,
    /// case in which all the dogs in the database will be stored in the filtered list.
    void filter_dogs_by_breed(const string& dog_breed);

    /// The function adds a dog to the list of adopted dogs and calls the method which
    /// removes the adopted dog from the repository.
    /// \param lucky_dog: the instance of the class Dog that is adopted.
    void adopt_dog(const Dog& lucky_dog);

    void open_adoption_list();

    /// Getter function for the repository under the service.
    DogRepository& get_repository();

    /// Getter function for the list of adopted dogs.
    vector<Dog>& get_adopted_dogs();

    /// Getter function for the list of dogs filtered by breed.
    vector<Dog>& get_dogs_filtered();

    AbstractAdoptionList* getAdoptionList();

    /// Getter function for the current dog inside the list of dogs filtered by breed.
    Dog get_current_dog();

    /// Getter function for the index of the current dog inside the list of dogs filtered by breed.
    int get_dog_index() const;

    /// Function that increments the index of the current dog inside the list of dogs filtered by breed
    void increment_dog_index();

    void undoAdoption();

    void redoAdoption();

    /// destructor
    ~UserService();

};



#endif //A45_911_ANDRIOAIE_DARIA_USERSERVICE_H
