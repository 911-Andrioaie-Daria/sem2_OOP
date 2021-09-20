////
//// Created by daria on 25/03/2021.
////
//
//#include "ValidatorTests.h"
//#include "DogValidator.h"
//#include <cassert>
//
//void test_validate_breed() {
//    auto *validator = new DogValidator();
//
//    string dog_breed = "Husky";
//    DogValidator::validate_breed(dog_breed);
//
//    try {
//        dog_breed = "1234$£!";
//        DogValidator::validate_breed(dog_breed);
//        assert(false);
//    }
//    catch(const ValidatorException& exception){
//        assert(true);
//    }
//    delete validator;
//}
//
//void test_validate_age(){
//    auto* validator = new DogValidator();
//    string dog_age = "12345";
//    DogValidator::validate_age(dog_age);
//
//    try{
//        dog_age = "ss hbs";
//        DogValidator::validate_age(dog_age);
//        assert(false);
//    }
//    catch(const ValidatorException& exception){
//        assert(true);
//    }
//
//    delete validator;
//}
//
//
//void test_validate_name(){
//    auto* validator = new DogValidator();
//
//    string dog_name = "Max Boo";
//    DogValidator::validate_name(dog_name);
//
//    try{
//        dog_name = "1234$£!";
//        DogValidator::validate_name(dog_name);
//    }
//    catch(const ValidatorException& exception){
//        assert(true);
//    }
//
//    delete validator;
//}
//
//void test_validate_photograph(){
//    auto* validator = new DogValidator();
//    string dog_photograph;
//    try{
//        dog_photograph = "123";
//        DogValidator::validate_photograph(dog_photograph);
//
//        dog_photograph = "123https://asdsd.ro";
//        DogValidator::validate_photograph(dog_photograph);
//
//        dog_photograph = "https://asdsd.ro.com";
//        DogValidator::validate_photograph(dog_photograph);
//
//        assert(false);
//    }
//    catch(const ValidatorException& exception){
//        assert(true);
//    }
//
//    dog_photograph = "https://maxthehusky.ro";
//    DogValidator::validate_photograph(dog_photograph);
//    delete validator;
//}
//
//void run_all_validator_tests(){
//    test_validate_breed();
//    test_validate_age();
//    test_validate_name();
//    test_validate_photograph();
//}