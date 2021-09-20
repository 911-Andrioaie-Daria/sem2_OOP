//
// Created by daria on 24/03/2021.
//

#include "UserService.h"

UserService::UserService(DogRepository* dog_repository){
    this->repository = dog_repository;
    int size_of_repo = dog_repository->get_size();
    this->adopted_dogs = new DynamicArray<Dog>(size_of_repo/2);
    this->dogs_filtered_by_breed = new DynamicArray<Dog>(size_of_repo);
    this->dog_index_in_show_list = 0;
}

void UserService::filter_dogs_by_breed(string dog_breed){
    DogRepository* dog_repository = this->get_repository();
    DynamicArray<Dog>* current_list_of_dogs = dog_repository->get_dynamic_array();
    int size_of_repo = dog_repository->get_size();

    DynamicArray<Dog>* filtered_dogs = this->get_dogs_filtered();
    filtered_dogs->empty();
    this->dog_index_in_show_list = 0;

    if(!dog_breed.empty()){
        for(int index=0; index < size_of_repo; index++){
            if((*current_list_of_dogs)[index].get_dog_breed() == dog_breed)
                filtered_dogs->add((*current_list_of_dogs)[index]);
        }
    }
    else{
        for(int index=0; index < size_of_repo; index++)
            filtered_dogs->add((*current_list_of_dogs)[index]);
    }

}

void UserService::adopt_dog(Dog lucky_dog){
    DynamicArray<Dog>* list_of_adopted_dogs = this->get_adopted_dogs();
    DogRepository* dog_repository = this->get_repository();

    list_of_adopted_dogs->add(lucky_dog);
    dog_repository->delete_dog_from_repository(lucky_dog.get_dog_breed(), lucky_dog.get_dog_name());
}


DogRepository* UserService::get_repository(){
    return this->repository;
}

DynamicArray<Dog>* UserService::get_adopted_dogs(){
    return this->adopted_dogs;
}

DynamicArray<Dog>* UserService::get_dogs_filtered(){
    return this->dogs_filtered_by_breed;
}

Dog UserService::get_current_dog(){
    int index = this->dog_index_in_show_list;
    DynamicArray<Dog>* dogs = this->get_dogs_filtered();
    return (*dogs)[index];
}

int UserService::get_dog_index() const {
    return this->dog_index_in_show_list;
}

void UserService::increment_dog_index() {
    this->dog_index_in_show_list++;
}

/// destructor
UserService::~UserService(){
    delete this->adopted_dogs;
    delete this->dogs_filtered_by_breed;
}