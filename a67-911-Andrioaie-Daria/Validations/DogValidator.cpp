//
// Created by daria on 21/03/2021.
//

#include "DogValidator.h"

void DogValidator::validate_breed(const string& dog_breed){
    for(char character: dog_breed)
        if(!(isalpha(character) || character == ' '))
            throw ValidatorException("Breed is not valid.");
}

void DogValidator::validate_name(const string& dog_name){
    for(char character: dog_name)
        if(!(isalpha(character) || character == ' '))
            throw ValidatorException("Name is not valid.");
}

void DogValidator::validate_age(const string& dog_age){
    for(char character: dog_age)
        if(!isdigit(character))
            throw ValidatorException("Age is not valid.");
}

void DogValidator::validate_photograph(const string& dog_photograph){
    if(dog_photograph.length() < 13)
        throw ValidatorException("Photograph is not valid.");
    int position = dog_photograph.find("https://");
    if(position != 0)
        throw ValidatorException("Photograph is not valid.");

//    int domain_position = dog_photograph.find(".ro");
//    if(domain_position != dog_photograph.length() - 3)
//        throw ValidatorException("Photograph is not valid.");
}

DogValidator::~DogValidator()= default;
