//
// Created by daria on 24/03/2021.
//

#include "UserService.h"
#include <algorithm>

UserService::UserService(DogRepository& dog_repository): repository{dog_repository}{
    //this->adopted_dogs = vector<Dog>();
    this->dogs_filtered_by_breed = vector<Dog>();
    this->dog_index_in_show_list = 0;
}

void UserService::filter_dogs_by_breed(const string& dog_breed){
    DogRepository& dog_repository = this->get_repository();
    vector<Dog> current_list_of_dogs = dog_repository.get_dog_array();

    vector<Dog>& filtered_dogs = this->get_dogs_filtered();
    filtered_dogs.clear();
    this->dog_index_in_show_list = 0;

    if(!dog_breed.empty()){
//        auto is_breed = [dog_breed](const Dog& dog) {return dog.get_dog_breed() == dog_breed; };
//        copy_if(current_list_of_dogs.begin(), current_list_of_dogs.end(), filtered_dogs.begin(), is_breed);
        for(auto& dog : current_list_of_dogs){
            if(dog.get_dog_breed() == dog_breed)
                filtered_dogs.push_back(dog);
        }
    }
    else{
         //copy(current_list_of_dogs.begin(), current_list_of_dogs.end(), filtered_dogs.end());
        for(auto& dog: current_list_of_dogs)
            filtered_dogs.push_back(dog);
    }
}

void UserService::adopt_dog(const Dog& lucky_dog){
    vector<Dog>& list_of_adopted_dogs = this->get_adopted_dogs();
    DogRepository& dog_repository = this->get_repository();

    list_of_adopted_dogs.push_back(lucky_dog);
    dog_repository.delete_dog(lucky_dog.get_dog_breed(), lucky_dog.get_dog_name());

    std::shared_ptr<Action> newAction(new AdoptAction(this->repository, this->adopted_dogs, lucky_dog));
    this->undoStack.push(newAction);
    this->redoStack = action_stack_t();
}


DogRepository& UserService::get_repository(){
    return this->repository;
}

vector<Dog>& UserService::get_adopted_dogs(){
    return this->adopted_dogs->get_data();
}

vector<Dog>& UserService::get_dogs_filtered(){
    return this->dogs_filtered_by_breed;
}

Dog UserService::get_current_dog(){
    int index = this->dog_index_in_show_list;
    vector<Dog> dogs = this->get_dogs_filtered();
    return (dogs)[index];
}

int UserService::get_dog_index() const {
    return this->dog_index_in_show_list;
}

void UserService::increment_dog_index() {
    this->dog_index_in_show_list++;
}

void UserService::setCSVFile() {
    this->adopted_dogs = new CSVAdoptionList("AdoptionList.csv");
}

void UserService::setHTMLFile() {
    this->adopted_dogs = new HTMLAdoptionList("AdoptionList.html");
}

void UserService::open_adoption_list() {
    this->adopted_dogs->open();
}

void UserService::undoAdoption() {
    if(this->undoStack.empty())
        throw UndoRedoException("No more undos");
    this->undoStack.top()->undo();
    this->redoStack.push(this->undoStack.top());
    this->undoStack.pop();
}

void UserService::redoAdoption() {
    if(this->redoStack.empty())
        throw UndoRedoException("No more redos");

    this->redoStack.top()->redo();
    this->undoStack.push(this->redoStack.top());
    this->redoStack.pop();
}

AbstractAdoptionList *UserService::getAdoptionList() {
    return this->adopted_dogs;
}

/// destructor
UserService::~UserService() = default;
