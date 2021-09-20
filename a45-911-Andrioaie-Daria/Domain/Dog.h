//
// Created by daria on 20/03/2021.
//

#ifndef A45_911_ANDRIOAIE_DARIA_DOG_H
#define A45_911_ANDRIOAIE_DARIA_DOG_H

#include <string>
using namespace std;

class Dog {
private:
    string breed;
    int age;
    string name;
    string photograph;

public:
    /// default constructor
    Dog();

    /// parameter constructor
    Dog(string dog_breed, int dog_age, string dog_name, string dog_photograph);

    /// destructor
    ~Dog();

    /// getter function for the breed of a dog
    string get_dog_breed() const;

    /// getter function for the age of a dog
    int get_dog_age() const;

    /// getter function for the name of a dog
    string get_dog_name() const;

    /// getter function for the photograph of a dog
    string get_dog_photograph() const;

    /// setter function for the age of a dog
    void set_age(int new_age);

    /// getter function for the photograph of a dog
    void set_photograph(string new_photograph);

    /// function converts the attributes of a dog object into a string.
    void to_string(char string_buffer[]);

};


#endif //A45_911_ANDRIOAIE_DARIA_DOG_H
