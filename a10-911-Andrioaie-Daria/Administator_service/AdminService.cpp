//
// Created by daria on 20/03/2021.
//

#include "AdminService.h"

//default constructor
//AdminService::AdminService(){
//
//}

//parameter constructor
AdminService::AdminService(DogRepository& repository, DogValidator& validator): repository{repository}, validator{validator}{
}

void AdminService::add_dog(const string& dog_breed, const string& dog_age, const string& dog_name, const string& dog_photograph){
    DogValidator& dogValidator = this->get_dog_validator();
    DogRepository& dogRepository = this->get_repository();

    DogValidator::validate_name(dog_name);
    DogValidator::validate_breed(dog_breed);
    DogValidator::validate_age(dog_age);
    DogValidator::validate_photograph(dog_photograph);

    int dog_age_as_int = stoi(dog_age);
    Dog new_dog(dog_breed, dog_age_as_int, dog_name, dog_photograph);
    dogRepository.add_dog(new_dog);

    shared_ptr<Action> newAction(new AddAction(this->repository, new_dog));
    this->undo_stack.push(newAction);
    this->redo_stack = action_stack_t();

}

void AdminService::delete_dog(const string& dog_breed, const string& dog_name){
    DogValidator& dogValidator = this->get_dog_validator();
    DogRepository& dogRepository = this->get_repository();

    DogValidator::validate_name(dog_name);
    DogValidator::validate_breed(dog_breed);

    Dog deleted_dog = this->searchDog(dog_breed, dog_name);
    dogRepository.delete_dog(dog_breed, dog_name);

    shared_ptr<Action> newAction(new DeleteAction(this->repository, deleted_dog));
    this->undo_stack.push(newAction);
    this->redo_stack = action_stack_t();

}

void AdminService::update_dog_age(const string& dog_breed, const string& dog_name, const string& new_dog_age){
    DogValidator& dogValidator = this->get_dog_validator();
    DogRepository& dogRepository = this->get_repository();

    DogValidator::validate_name(dog_name);
    DogValidator::validate_breed(dog_breed);
    DogValidator::validate_age(new_dog_age);

    int new_dog_age_as_int = stoi(new_dog_age);
    Dog oldDog = this->searchDog(dog_breed, dog_name);
    dogRepository.update_dog_age(dog_breed, dog_name, new_dog_age_as_int);
    Dog newDog = oldDog;
    newDog.set_age(new_dog_age_as_int);

    std::shared_ptr<Action> newAction(new UpdateAgeAction(this->repository, oldDog, newDog));
    this->undo_stack.push(newAction);
    this->redo_stack = action_stack_t();

}

void AdminService::update_dog_photograph(const string& dog_breed, const string& dog_name, const string& new_dog_photograph){
    DogValidator& dogValidator = this->get_dog_validator();
    DogRepository& dogRepository = this->get_repository();

    DogValidator::validate_name(dog_name);
    DogValidator::validate_breed(dog_breed);
    DogValidator::validate_photograph(new_dog_photograph);

    Dog oldDog = this->searchDog(dog_breed, dog_name);
    dogRepository.update_dog_photograph(dog_breed, dog_name, new_dog_photograph);
    Dog newDog = oldDog;
    newDog.set_photograph(new_dog_photograph);


    std::shared_ptr<Action> newAction(new UpdatePhotoAction(this->repository, oldDog, newDog));
    this->undo_stack.push(newAction);
    this->redo_stack = action_stack_t();
}


DogRepository& AdminService::get_repository(){
    return this->repository;
}

vector<Dog> AdminService::get_dog_array(){
    return this->repository.get_dog_array();
}

DogValidator& AdminService::get_dog_validator(){
    return this->validator;
}

void AdminService::undo() {
    if(this->undo_stack.empty())
        throw UndoRedoException("No more undos");

    this->undo_stack.top()->undo();
    this->redo_stack.push(this->undo_stack.top());
    this->undo_stack.pop();

}

void AdminService::redo() {
    if(this->redo_stack.empty())
        throw UndoRedoException("No more redos");

    this->redo_stack.top()->redo();
    this->undo_stack.push(this->redo_stack.top());
    this->redo_stack.pop();
}

Dog AdminService::searchDog(string dog_breed, string dog_name) {
    for(auto &dog : this->get_dog_array()){
        if(dog.get_dog_breed() == dog_breed && dog.get_dog_name() == dog_name)
            return dog;
    }
    Dog null_dog = Dog();
    return null_dog;
}

//// destructor
AdminService::~AdminService()=default;