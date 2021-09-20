//
// Created by daria on 05/05/2021.
//

#include "UserGUI.h"
#include "qlayout.h"
#include "qmessagebox.h"
#include "qlabel.h"
#include "iostream"
#include "PictureDelegate.h"

UserGUI::UserGUI(UserService &userService1, QWidget* parent): userService{userService1}, QDialog{parent} {
    this->dogsModel = new DogCustomModel{this->userService.getAdoptionList(), this->userService.get_repository()};

    this->initGUI();
    this->connectSignalsAndSlots();
}

void UserGUI::initGUI() {
    this->adoptedDogsTableView = new QTableView();
    this->adoptedDogsTableView->setMinimumSize(600,500);
    this->adoptedDogsTableView->resizeRowsToContents();
    this->adoptedDogsTableView->resizeColumnsToContents();
    this->adoptedDogsTableView->setModel(this->dogsModel);
    this->adoptedDogsTableView->setItemDelegate(new PictureDelegate{});


    this->availableDogsListWidget = new QListWidget{};
    this->adoptedDogsListWidget = new QListWidget{};
    this->breedLineEdit = new QLineEdit{};
    this->seeBreedButton = new QPushButton{"See breed"};
    this->seeAllButton = new QPushButton{"See all dogs"};
    this->adoptButton = new QPushButton{"Adopt"};
    this->openApplicationButton = new QPushButton{"See in app"};
    this->undoButton = new QPushButton{"Undo"};
    this->redoButton = new QPushButton{"Redo"};
    this->undoShortcut = new QShortcut(QKeySequence(Qt::CTRL+ Qt::Key_Z), this);
    this->redoShortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y),this);

    auto* mainLayout = new QVBoxLayout{this};

    auto* listsLayout = new QHBoxLayout{};

    auto* availableDogsLayout = new QVBoxLayout{};
    auto *availableDogsLabel = new QLabel{"Available dogs"};
    availableDogsLayout->addWidget(availableDogsLabel);
    availableDogsLayout->addWidget(this->availableDogsListWidget);

    listsLayout->addLayout(availableDogsLayout);

    auto* adoptedDogsLayout = new QVBoxLayout{};
    auto *adoptedDogsLabel = new QLabel{"Adopted dogs"};
    adoptedDogsLayout->addWidget(adoptedDogsLabel);
    //adoptedDogsLayout->addWidget(this->adoptedDogsListWidget);
    adoptedDogsLayout->addWidget(this->adoptedDogsTableView);
    adoptedDogsLayout->addWidget(this->openApplicationButton);

    listsLayout->addLayout(adoptedDogsLayout);

    mainLayout->addLayout(listsLayout);

    mainLayout->addWidget(this->adoptButton);

    auto* undoRedoLayout = new QHBoxLayout{};
    undoRedoLayout->addWidget(this->undoButton);
    undoRedoLayout->addWidget(this->redoButton);

    mainLayout->addLayout(undoRedoLayout);

    auto *breedSelectionLayout = new QHBoxLayout{};

    auto *breedLabel = new QLabel{"Breed:"};
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
    QObject::connect(this->undoButton, &QPushButton::clicked, this, &UserGUI::undoAdoption);
    QObject::connect(this->undoShortcut, &QShortcut::activated, this, &UserGUI::undoAdoption);
    QObject::connect(this->redoButton, &QPushButton::clicked, this, &UserGUI::redoAdoption);
    QObject::connect(this->redoShortcut, &QShortcut::activated, this, &UserGUI::redoAdoption);

}

void UserGUI::populateAdoptedList() {
    this->adoptedDogsListWidget->clear();
    vector<Dog> adoptedDogs = this->userService.get_adopted_dogs();
    for(Dog& dog : adoptedDogs)
        this->adoptedDogsListWidget->addItem(QString::fromStdString(dog.get_dog_name() + " - " + dog.get_dog_breed() + " - " +
                                                                      to_string(dog.get_dog_age()) + " - " + dog.get_dog_photograph()));
}

void UserGUI::populateAvailableListWithAll() {
    string breed;
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
    this->notifyModel();
    //this->populateAdoptedList();
    //this->adoptedDogsListWidget->addItem(QString::fromStdString(dog.get_dog_name() + " - " + dog.get_dog_breed() + " - " +
    //                                                            to_string(dog.get_dog_age()) + " - " + dog.get_dog_photograph()));
}

void UserGUI::openInApp() {
    this->userService.open_adoption_list();
}

void UserGUI::undoAdoption() {
    try{
        this->userService.undoAdoption();
        this->notifyModel();
        //this->populateAdoptedList();
        this->populateAvailableListWithAll();
    }
    catch(CustomException& exception){
        QMessageBox::information(this, "No undos", "No more available undos.");
    }
}

void UserGUI::redoAdoption() {
    try{
        this->userService.redoAdoption();
        this->notifyModel();
        //this->populateAdoptedList();
        this->populateAvailableListWithAll();
    }
    catch(CustomException& exception){
        QMessageBox::information(this, "No redos", "No more available redos.");
    }
}

void UserGUI::notifyModel() {
    this->dogsModel->updateInternalData();
}