//
// Created by daria on 08/04/2021.
//

#ifndef A67_911_ANDRIOAIE_DARIA_CUSTOMEXCEPTION_H
#define A67_911_ANDRIOAIE_DARIA_CUSTOMEXCEPTION_H
#include <exception>
#include <string>
using namespace std;

class CustomException : public exception{
protected:
    string message;
public:
    explicit CustomException(string exceptionMessage);

    const char* what() const noexcept override;
};

class ValidatorException : public CustomException {
public:

    explicit ValidatorException(string exceptionMessage);
};

class RepositoryException : public CustomException {
public:

    explicit RepositoryException(string exceptionMessage);
};


#endif //A67_911_ANDRIOAIE_DARIA_CUSTOMEXCEPTION_H
