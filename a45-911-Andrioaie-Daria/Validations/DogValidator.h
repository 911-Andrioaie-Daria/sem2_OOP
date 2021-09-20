//
// Created by daria on 21/03/2021.
//

#ifndef A45_911_ANDRIOAIE_DARIA_DOGVALIDATOR_H
#define A45_911_ANDRIOAIE_DARIA_DOGVALIDATOR_H

#include <string>
using namespace std;

class DogValidator {
public:
    /// The function validates the breed of a dog by checking if it contains only letters and spaces. ex: Beagle
    bool validate_breed(string dog_breed);

    /// The function validates the name of a dog by checking if it contains only letters and spaces. ex: Lord Max
    bool validate_name(string dog_name);

    /// The function validates the age of a dog by checking if it contains only digits. ex: 12
    bool validate_age(string dog_age);

    /// The function validates the breed of a dog by checking if it obeys the format "https://blablabla.ro"
    bool validate_photograph(string dog_photograph);

    ~DogValidator();
};


#endif //A45_911_ANDRIOAIE_DARIA_DOGVALIDATOR_H
