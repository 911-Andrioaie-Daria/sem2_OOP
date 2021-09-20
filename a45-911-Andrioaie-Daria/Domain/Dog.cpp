//
// Created by daria on 20/03/2021.
//

#include "Dog.h"
#include <string>
#include <cstdio>

// default constructor
Dog::Dog()=default;

// parameter constructor
Dog::Dog(string dog_breed, int dog_age, string dog_name, string dog_photograph):
breed{dog_breed}, age{dog_age}, name{dog_name}, photograph{dog_photograph}{
}

// destructor
Dog::~Dog(){

}

string Dog::get_dog_breed() const{
    return this->breed;
}

int Dog::get_dog_age() const{
    return this->age;
}

string Dog::get_dog_name() const{
    return this->name;
}

string Dog::get_dog_photograph() const{
    return this->photograph;
}

void Dog::set_age(int new_age){
    this->age = new_age;
}

void Dog::set_photograph(string new_photograph){
    this->photograph = new_photograph;
}

void Dog::to_string(char string_buffer[]){
    sprintf(string_buffer, "Name: %s, Breed: %s, Age: %d, Photograph: %s",
            this->get_dog_name().c_str(), this->get_dog_breed().c_str(), this->get_dog_age(), this->get_dog_photograph().c_str());
}