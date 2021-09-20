//
// Created by daria on 20/03/2021.
//

#include "DogRepository.h"


///Constructor
DogRepository::DogRepository()=default;

/////Destructor
DogRepository::~DogRepository()=default;

void DogRepository::init(){
    Dog dog_1("Labrador", 2, "Louie", "https://labrador1.ro");
    add_dog(dog_1);

    Dog dog_2("Husky", 3, "Taco", "https://huski1.ro");
    add_dog(dog_2);

    Dog dog_3("Corgi", 1, "Oscar", "https://corgi1.ro");
    add_dog(dog_3);

    Dog dog_4("Beagle", 2, "Pascal", "https://beagle1.ro");
    add_dog(dog_4);

    Dog dog_5("Australian Shepherd", 5, "Muki", "https://australiansheperd1.ro");
    add_dog(dog_5);

    Dog dog_6("Labrador", 4, "Buddy", "https://labrador2.ro");
    add_dog(dog_6);

    Dog dog_7("Husky", 2, "Simba", "https://husky2.ro");
    add_dog(dog_7);

    Dog dog_8("Australian Shepherd", 5, "Milo", "https://australiansheperd2.ro");
    add_dog(dog_8);

    Dog dog_9("Corgi", 1, "Murphy", "https://corgi2.ro");
    add_dog(dog_9);

    Dog dog_10("Beagle", 2, "Chase", "https://beagle2.ro");
    add_dog(dog_10);
}

int DogRepository::get_size(){
    return this->dog_array.size();
}

vector<Dog>& DogRepository::get_dog_array(){
    return this->dog_array;
}

void DogRepository::add_dog(const Dog& new_dog){
    string breed = new_dog.get_dog_breed();
    string name = new_dog.get_dog_name();
    if(search_dog(breed, name) != -1){
        // the dog is already in the repo
        throw RepositoryException("Dog is already in the shelter");
    }
    this->dog_array.push_back(new_dog);

}

void DogRepository::delete_dog(const string& dog_breed, const string& dog_name) {
    vector<Dog>& dogArray = this->get_dog_array();
    int dog_position = search_dog(dog_breed, dog_name);
    if(dog_position == -1){
        throw RepositoryException("Dog cannot be found in the shelter.");
    }
    dogArray.erase(dogArray.begin() + dog_position);
}

void DogRepository::update_dog_age(const string& dog_breed, const string& dog_name, int new_dog_age){
    vector<Dog>& dogArray = this->get_dog_array();
    int dog_position = search_dog(dog_breed, dog_name);
    if(dog_position == -1){
        throw RepositoryException("Dog cannot be found in the shelter.");
    }
    string dog_photograph = dogArray.at(dog_position).get_dog_photograph();
    Dog updated_dog(dog_breed, new_dog_age, dog_name, dog_photograph);
    dogArray.at(dog_position) = updated_dog;
}

void DogRepository::update_dog_photograph(const string& dog_breed, const string& dog_name, const string& new_dog_photograph){
    vector<Dog>& dogArray = this->get_dog_array();
    int dog_position = search_dog(dog_breed, dog_name);
    if(dog_position == -1){
        throw RepositoryException("Dog cannot be found in the shelter.");
    }
    int dog_age = dogArray.at(dog_position).get_dog_age();
    Dog updated_dog(dog_breed, dog_age, dog_name, new_dog_photograph);
    dogArray.at(dog_position) = updated_dog;
}

int DogRepository::search_dog(const string& dog_breed, const string& dog_name){
    vector<Dog>& dogArray = this->get_dog_array();
    int index = 0;
    for(auto& dog: dogArray){
        if(dog.get_dog_breed() == dog_breed && dog.get_dog_name() == dog_name)
            return index;
        index++;
    }
    return -1;

//    for(int i=0; i<this->get_size(); i++)
//        if(dogArray.at(i).get_dog_breed() == dog_breed && dogArray.at(i).get_dog_name() == dog_name)
//            return i;
//    return -1;
//    int index = 0;
//    for(auto& element: this->get_dog_array())
//        if(element.get_dog_breed() == dog_breed && element.get_dog_name() == dog_name)
//            break;
//        else
//            index++;
//    if(index == this->get_dog_array().size())
//        return -1;
//    else
//        return index;
}