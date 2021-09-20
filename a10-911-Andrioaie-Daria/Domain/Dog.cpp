//
// Created by daria on 20/03/2021.
//

#include "Dog.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

//// default constructor
Dog::Dog() = default;

/// parameter constructor
Dog::Dog(const string& dog_breed, int dog_age, const string& dog_name, const string& dog_photograph):
breed{dog_breed}, age{dog_age}, name{dog_name}, photograph{dog_photograph}{

}

// destructor
Dog::~Dog()= default;

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

void Dog::set_photograph(const string& new_photograph){
    this->photograph = new_photograph;
}

//Dog::Dog(const Dog &other_dog): breed{other_dog.breed}, age{other_dog.age}, name{other_dog.name}, photograph{other_dog.photograph}{
//}

Dog& Dog::operator=(const Dog& dog){
    this->breed = dog.breed;
    this->name = dog.name;
    this->age = dog.age;
    this->photograph = dog.photograph;
    return *this;
}

bool Dog::operator==(const Dog& dog) const{
    if(this->breed == dog.breed && this->name == dog.name && this->photograph == dog.photograph && this->age == dog.age)
        return true;
    return false;
}

std::ostream &operator<<(ostream &os, const Dog &dog){
    //buffer << setw(20) << left << this->organism << "|   " << setw(20) << left << this->name << "|   "<< setw(25) << right<< this->sequence;
    os<<dog.name<<" "<<dog.breed<<" "<<" "<<dog.age<<" "<<dog.photograph;
    return os;
}

std::istream& operator>>(std::istream &is, Dog &dog){
    is>>dog.name>>dog.breed>>dog.age>>dog.photograph;
    return is;
}

string Dog::to_string() const{
    stringstream buffer;
    buffer<<"Name: "<<this->get_dog_name()<<", Breed: "<<this->get_dog_breed()<<", Age: "<<this->get_dog_age()<<", Photo: "<<this->get_dog_photograph();
//    sprintf(string_buffer, "Name: %s, Breed: %s, Age: %d, Photograph: %s",
//            this->get_dog_name().c_str(), this->get_dog_breed().c_str(), this->get_dog_age(), this->get_dog_photograph().c_str());
    return buffer.str();
}

string Dog::to_csv_representation() const {
    stringstream buffer;
    buffer<<this->get_dog_name()<<","<<this->get_dog_breed()<<","<<this->get_dog_age()<<","<<this->get_dog_photograph();
    return buffer.str();
}

string Dog::to_HTML_representation() const {
    stringstream buffer;
    buffer<<"\t<tr>\n";
    buffer<<"\t\t<td>"<<this->get_dog_name()<<"</td>\n";
    buffer<<"\t\t<td>"<<this->get_dog_breed()<<"</td>\n";
    buffer<<"\t\t<td>"<<this->get_dog_age()<<"</td>\n";
    buffer<<"\t\t<td><a href=\""<<this->get_dog_photograph()<<"\">Picture</a></td>\n";
    buffer<<"\t</tr>\n";
    return buffer.str();
}

