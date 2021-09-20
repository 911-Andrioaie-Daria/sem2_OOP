//
// Created by daria on 25/03/2021.
//

#include "ValidatorTests.h"
#include "DogValidator.h"
#include <assert.h>

void test_validate_breed(){
    DogValidator* validator = new DogValidator();

    string dog_breed = "Husky";
    assert(validator->validate_breed(dog_breed) == true);

    dog_breed = "1234$£!";
    assert(validator->validate_breed(dog_breed) == false);

    delete validator;
}

void test_validate_age(){
    DogValidator* validator = new DogValidator();
    string dog_age = "12345";
    assert(validator->validate_age(dog_age) == true);

    dog_age = "ss hbs";
    assert(validator->validate_age(dog_age) == false);

    delete validator;
}


void test_validate_name(){
    DogValidator* validator = new DogValidator();

    string dog_name = "Max Boo";
    assert(validator->validate_name(dog_name) == true);

    dog_name = "1234$£!";
    assert(validator->validate_name(dog_name) == false);

    delete validator;
}

void test_validate_photograph(){
    DogValidator* validator = new DogValidator();

    string dog_photograph = "123";
    assert(validator->validate_photograph(dog_photograph) == false);

    dog_photograph = "123https://asdsd.ro";
    assert(validator->validate_photograph(dog_photograph) == false);

    dog_photograph = "https://asdsd.ro.com";
    assert(validator->validate_photograph(dog_photograph) == false);

    dog_photograph = "https://maxthehusky.ro";
    assert(validator->validate_photograph(dog_photograph) == true);
    delete validator;
}

void run_all_validator_tests(){
    test_validate_breed();
    test_validate_age();
    test_validate_name();
    test_validate_photograph();
}