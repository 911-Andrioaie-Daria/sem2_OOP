//
// Created by daria on 20/03/2021.
//

#include "DogRepository.h"

///Constructor
DogRepository::DogRepository(DynamicArray<Dog>* dog_dynamic_array){
    this->dynamic_array = dog_dynamic_array;
}

///Destructor
DogRepository::~DogRepository(){
    delete this->dynamic_array;
}

void DogRepository::initialise_repository(){
    Dog dog_1("Labrador", 2, "Louie", "https://labrador1.ro");
    add_dog_to_repository(dog_1);

    Dog dog_2("Husky", 3, "Taco", "https://huski1.ro");
    add_dog_to_repository(dog_2);

    Dog dog_3("Corgi", 1, "Oscar", "https://corgi1.ro");
    add_dog_to_repository(dog_3);

    Dog dog_4("Beagle", 2, "Pascal", "https://beagle1.ro");
    add_dog_to_repository(dog_4);

    Dog dog_5("Australian Shepherd", 5, "Muki", "https://australiansheperd1.ro");
    add_dog_to_repository(dog_5);

    Dog dog_6("Labrador", 4, "Buddy", "https://labrador2.ro");
    add_dog_to_repository(dog_6);

    Dog dog_7("Husky", 2, "Simba", "https://husky2.ro");
    add_dog_to_repository(dog_7);

    Dog dog_8("Australian Shepherd", 5, "Milo", "https://australiansheperd2.ro");
    add_dog_to_repository(dog_8);

    Dog dog_9("Corgi", 1, "Murphy", "https://corgi2.ro");
    add_dog_to_repository(dog_9);

    Dog dog_10("Beagle", 2, "Chase", "https://beagle2.ro");
    add_dog_to_repository(dog_10);
}

int DogRepository::get_size(){
    return this->dynamic_array->getSize();
}

DynamicArray<Dog>* DogRepository::get_dynamic_array(){
    return this->dynamic_array;
}

bool DogRepository::add_dog_to_repository(Dog new_dog){
    if(search_dog_in_repository(new_dog.get_dog_breed(), new_dog.get_dog_name()) == -1){
        this->dynamic_array->add(new_dog);
        return true;
    }
    // the dog is already in the repo
    return false;
}

bool DogRepository::delete_dog_from_repository(string dog_breed, string dog_name) {
    int dog_position = search_dog_in_repository(dog_breed, dog_name);
    if(dog_position != -1){
        this->dynamic_array->remove(dog_position);
        return true;
    }
    return false;
}

bool DogRepository::update_dog_age_in_repo(string dog_breed, string dog_name, int new_dog_age){
    DynamicArray<Dog>* dog_array = this->get_dynamic_array();
    int dog_position = search_dog_in_repository(dog_breed, dog_name);
    if(dog_position != -1){
        string dog_photograph = dog_array->get_elements()[dog_position].get_dog_photograph();
        Dog updated_dog(dog_breed, new_dog_age, dog_name, dog_photograph);
        this->dynamic_array->update(updated_dog, dog_position);
        return true;
    }
    return false;
}

bool DogRepository::update_dog_photograph_in_repo(string dog_breed, string dog_name, string new_dog_photograph){
    DynamicArray<Dog>* dog_array = this->get_dynamic_array();
    int dog_position = search_dog_in_repository(dog_breed, dog_name);
    if(dog_position != -1){
        int dog_age = dog_array->get_elements()[dog_position].get_dog_age();
        Dog updated_dog(dog_breed, dog_age, dog_name, new_dog_photograph);
        this->dynamic_array->update(updated_dog, dog_position);
        return true;
    }
    return false;
}

int DogRepository::search_dog_in_repository(string dog_breed, string dog_name){
    for(int i=0; i<this->get_size(); i++)
        if((*this->dynamic_array)[i].get_dog_breed() == dog_breed && (*this->dynamic_array)[i].get_dog_name() == dog_name)
            return i;
    return -1;
}