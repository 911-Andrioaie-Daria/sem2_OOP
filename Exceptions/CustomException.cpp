//
// Created by daria on 08/04/2021.
//

#include "CustomException.h"

#include <utility>

CustomException::CustomException(string exceptionMessage): message{std::move(exceptionMessage)} {

}

const char* CustomException::what() const noexcept{
    return this->message.c_str();
}

ValidatorException::ValidatorException(string exceptionMessage): CustomException(std::move(exceptionMessage)) {

}

RepositoryException::RepositoryException(string exceptionMessage) : CustomException(std::move(exceptionMessage)) {

}

UndoRedoException::UndoRedoException(string exceptionMessage) : CustomException(std::move(exceptionMessage)) {

}
