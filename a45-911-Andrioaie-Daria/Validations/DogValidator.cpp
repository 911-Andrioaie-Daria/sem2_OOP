//
// Created by daria on 21/03/2021.
//

#include "DogValidator.h"

bool DogValidator::validate_breed(string dog_breed){
    for(char character: dog_breed)
        if(!(isalpha(character) || character == ' '))
            return false;
    return true;
}

bool DogValidator::validate_name(string dog_name){
    for(char character: dog_name)
        if(!(isalpha(character) || character == ' '))
            return false;
    return true;
}

bool DogValidator::validate_age(string dog_age){
    for(char character: dog_age)
        if(!isdigit(character))
            return false;
    return true;
}

bool DogValidator::validate_photograph(string dog_photograph){
    if(dog_photograph.length() < 13)
        return false;
    int position = dog_photograph.find("https://");
    if(position != 0)
        return false;

    int domain_position = dog_photograph.find(".ro");
    if(domain_position != dog_photograph.length() - 3)
        return false;

    return true;
}

DogValidator::~DogValidator(){}
