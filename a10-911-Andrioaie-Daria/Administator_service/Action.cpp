//
// Created by daria on 26/05/2021.
//

#include "Action.h"

AddAction::AddAction(DogRepository &repository, Dog &dog): currentRepository{repository}, addedDog{dog} {

}

void AddAction::undo() {
    string breed = this->addedDog.get_dog_breed();
    string name = this->addedDog.get_dog_name();
    this->currentRepository.delete_dog(breed, name);
}

void AddAction::redo() {
    this->currentRepository.add_dog(addedDog);
}

DeleteAction::DeleteAction(DogRepository &repository, Dog &dog): currentRepository{repository}, deletedDog{dog} {

}

void DeleteAction::undo() {
    this->currentRepository.add_dog(deletedDog);
}

void DeleteAction::redo() {
    this->currentRepository.delete_dog(deletedDog.get_dog_breed(), deletedDog.get_dog_name());
}

UpdatePhotoAction::UpdatePhotoAction(DogRepository &repository, Dog &oldDog, Dog &newDog): currentRepository{repository},
oldDog{oldDog}, newDog{newDog}{

}

void UpdatePhotoAction::undo() {
    this->currentRepository.update_dog_photograph(this->oldDog.get_dog_breed(),
                                                  this->oldDog.get_dog_name(),
                                                  this->oldDog.get_dog_photograph());
}

void UpdatePhotoAction::redo() {
    this->currentRepository.update_dog_photograph(this->newDog.get_dog_breed(),
                                                  this->newDog.get_dog_name(),
                                                  this->newDog.get_dog_photograph());
}

UpdateAgeAction::UpdateAgeAction(DogRepository &repository, Dog &oldDog, Dog &newDog):currentRepository{repository},
oldDog{oldDog}, newDog{newDog}{

}

void UpdateAgeAction::undo() {
    this->currentRepository.update_dog_age(this->oldDog.get_dog_breed(),
                                           this->oldDog.get_dog_name(),
                                           this->oldDog.get_dog_age());
}

void UpdateAgeAction::redo() {
    this->currentRepository.update_dog_age(this->newDog.get_dog_breed(),
                                           this->newDog.get_dog_name(),
                                           this->newDog.get_dog_age());
}

AdoptAction::AdoptAction(DogRepository &repository, AbstractAdoptionList* adoptionList, Dog dog):
currentRepository{repository}, adoptionList{adoptionList},adoptedDog{dog} {
}

void AdoptAction::undo() {
    vector<Dog>& adoptedDogs = this->adoptionList->get_data();
    for(int i=0; i<adoptedDogs.size(); i++){
        if(adoptedDogs[i] == adoptedDog){
            adoptedDogs.erase(adoptedDogs.begin() + i);
            break;
        }
    }

    this->currentRepository.add_dog(adoptedDog);
}

void AdoptAction::redo() {
    vector<Dog>& adoptedDogs = this->adoptionList->get_data();
    adoptedDogs.push_back(adoptedDog);
    string breed = adoptedDog.get_dog_breed();
    string name = adoptedDog.get_dog_name();
    this->currentRepository.delete_dog(breed, name);
}
