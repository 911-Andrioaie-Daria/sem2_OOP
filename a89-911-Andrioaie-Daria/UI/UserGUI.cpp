//
// Created by daria on 05/05/2021.
//

#include "UserGUI.h"
#include "qlayout.h"
#include "qmessagebox.h"
#include "qlabel.h"
#include "iostream"

UserGUI::UserGUI(UserService &userService1, QWidget* parent): userService{userService1}, QDialog{parent} {
    this->initGUI();
    this->connectSignalsAndSlots();
}

void UserGUI::initGUI() {
    this->availableDogsListWidget = new QListWidget{};
    this->adoptedDogsListWidget = new QListWidget{};
    this->breedLineEdit = new QLineEdit{};
    this->seeBreedButton = new QPushButton{"See breed"};
    this->seeAllButton = new QPushButton{"See all dogs"};
    this->adoptButton = new QPushButton{"Adopt"};
    this->openApplicationButton = new QPushButton{"See in app"};

    QVBoxLayout* mainLayout = new QVBoxLayout{this};

    QHBoxLayout* listsLayout = new QHBoxLayout{};

    QVBoxLayout* availableDogsLayout = new QVBoxLayout{};
    QLabel *availableDogsLabel = new QLabel{"Available dogs"};
    availableDogsLayout->addWidget(availableDogsLabel);
    availableDogsLayout->addWidget(this->availableDogsListWidget);

    listsLayout->addLayout(availableDogsLayout);

    QVBoxLayout* adoptedDogsLayout = new QVBoxLayout{};
    QLabel *adoptedDogsLabel = new QLabel{"Adopted dogs"};
    adoptedDogsLayout->addWidget(adoptedDogsLabel);
    adoptedDogsLayout->addWidget(this->adoptedDogsListWidget);
    adoptedDogsLayout->addWidget(this->openApplicationButton);

    listsLayout->addLayout(adoptedDogsLayout);

    mainLayout->addLayout(listsLayout);

    mainLayout->addWidget(this->adoptButton);

    QHBoxLayout *breedSelectionLayout = new QHBoxLayout{};

    QLabel *breedLabel = new QLabel{"Breed:"};
    breedLabel->setBuddy(this->breedLineEdit);

    breedSelectionLayout->addWidget(breedLabel);
    breedSelectionLayout->addWidget(this->breedLineEdit);
    breedSelectionLayout->addWidget(this->seeBreedButton);
    breedSelectionLayout->addWidget(this->seeAllButton);

    this->setWindowTitle("User mode");
    mainLayout->addLayout(breedSelectionLayout);
}

void UserGUI::populateAvailableListWithBreed() {
    string breed = this->breedLineEdit->text().toStdString();
    this->availableDogsListWidget->clear();

    this->userService.filter_dogs_by_breed(breed);
    vector<Dog> filteredDogs = this->userService.get_dogs_filtered();
    for(Dog& dog : filteredDogs)
        this->availableDogsListWidget->addItem(QString::fromStdString(dog.get_dog_name() + " - " + dog.get_dog_breed() + " - " +
                                                             to_string(dog.get_dog_age()) + " - " + dog.get_dog_photograph()));
}

void UserGUI::connectSignalsAndSlots() {
    QObject::connect(this->seeBreedButton, &QPushButton::clicked, this, &UserGUI::populateAvailableListWithBreed);
    QObject::connect(this->seeAllButton, &QPushButton::clicked, this, &UserGUI::populateAvailableListWithAll);
    QObject::connect(this->adoptButton, &QPushButton::clicked, this, &UserGUI::adoptDog);
    QObject::connect(this->openApplicationButton, &QPushButton::clicked, this, &UserGUI::openInApp);
}

void UserGUI::populateAdoptedList() {
    this->adoptedDogsListWidget->clear();
    vector<Dog> adoptedDogs = this->userService.get_adopted_dogs();
    for(Dog& dog : adoptedDogs)
        this->availableDogsListWidget->addItem(QString::fromStdString(dog.get_dog_name() + " - " + dog.get_dog_breed() + " - " +
                                                                      to_string(dog.get_dog_age()) + " - " + dog.get_dog_photograph()));
}

void UserGUI::populateAvailableListWithAll() {
    string breed = "";
    this->availableDogsListWidget->clear();

    this->userService.filter_dogs_by_breed(breed);
    vector<Dog> filteredDogs = this->userService.get_dogs_filtered();
    for(Dog& dog : filteredDogs)
        this->availableDogsListWidget->addItem(QString::fromStdString(dog.get_dog_name() + " - " + dog.get_dog_breed() + " - " +
                                                                      to_string(dog.get_dog_age()) + " - " + dog.get_dog_photograph()));
}

int UserGUI::getSelectedIndex() const {
    QModelIndexList selectedIndexes = this->availableDogsListWidget->selectionModel()->selectedIndexes();
    if(selectedIndexes.empty()){
        return -1;
    }

    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void UserGUI::adoptDog(){
    int selectedIndex = this->getSelectedIndex();
    if(selectedIndex < 0){
        QMessageBox::critical(this, "Error", "No dog was selected!");
        return;
    }
    vector<Dog> filteredDogs = this->userService.get_dogs_filtered();
    Dog dog = filteredDogs[selectedIndex];
    this->userService.adopt_dog(dog);
    this->populateAvailableListWithBreed();
    //this->populateAdoptedList();
    this->adoptedDogsListWidget->addItem(QString::fromStdString(dog.get_dog_name() + " - " + dog.get_dog_breed() + " - " +
                                                                to_string(dog.get_dog_age()) + " - " + dog.get_dog_photograph()));
}

void UserGUI::openInApp() {
    this->userService.open_adoption_list();
}
