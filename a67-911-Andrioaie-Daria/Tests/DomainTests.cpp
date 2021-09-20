//
// Created by daria on 22/03/2021.
//

#include "DomainTests.h"
#include <cassert>
#include <cstring>

void test_getters_domain(){
    Dog dog_1("Corgi", 12, "Mary", "https://vvfvfe.ro");
    assert(dog_1.get_dog_breed() == "Corgi");
    assert(dog_1.get_dog_age() == 12);
    assert(dog_1.get_dog_name() == "Mary");
    assert(dog_1.get_dog_photograph() == "https://vvfvfe.ro");
}

void test_setters_domain(){
    Dog dog_1("Corgi", 12, "Mary", "https://vvfvfe.ro");
    dog_1.set_age(1);
    assert(dog_1.get_dog_age() == 1);

    dog_1.set_photograph("https://abcd.ro");
    assert(dog_1.get_dog_photograph() == "https://abcd.ro");
}



//void test_string_domain(){
//    Dog default_dog;
//    char string[100];
//    default_dog.to_string(string);
//    assert(strcmp(string, "") != 0);
//}

void run_all_domain_tests(){
    test_getters_domain();
    test_setters_domain();
    //test_string_domain();
}