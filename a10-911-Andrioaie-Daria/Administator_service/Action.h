//
// Created by daria on 26/05/2021.
//

#ifndef A10_911_ANDRIOAIE_DARIA_ACTION_H
#define A10_911_ANDRIOAIE_DARIA_ACTION_H
#include "DogRepository.h"
#include "AbstractAdoptionList.h"

class Action {
public:
    virtual void undo()=0;
    virtual void redo()=0;
};

class AddAction : public Action{
private:
    DogRepository& currentRepository;
    Dog addedDog;

public:
    AddAction(DogRepository &repository, Dog &dog);
    void undo() override;
    void redo() override;
};

class DeleteAction : public Action{
private:
    DogRepository& currentRepository;
    Dog deletedDog;
public:
    DeleteAction(DogRepository &repository, Dog &dog);
    void undo() override;
    void redo() override;
};

class UpdatePhotoAction : public Action{
private:
    DogRepository& currentRepository;
    Dog oldDog;
    Dog newDog;
public:
    UpdatePhotoAction(DogRepository &repository, Dog &oldDog, Dog &newDog);
    void undo() override;
    void redo() override;
};


class UpdateAgeAction : public Action{
    DogRepository& currentRepository;
    Dog oldDog;
    Dog newDog;
public:
    UpdateAgeAction(DogRepository &repository, Dog &oldDog, Dog &newDog);
    void undo() override;
    void redo() override;
};

class AdoptAction : public Action{
private:
    AbstractAdoptionList* adoptionList;
    DogRepository& currentRepository;
    Dog adoptedDog;

public:
    AdoptAction(DogRepository &repository, AbstractAdoptionList* adoptionList, Dog dog);
    void undo() override;
    void redo() override;
};



#endif //A10_911_ANDRIOAIE_DARIA_ACTION_H
