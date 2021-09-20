//
// Created by daria on 04/05/2021.
//

#include "AdminGUI.h"
#include "qlayout.h"
#include "qformlayout.h"
#include "qmessagebox.h"
#include <QtWidgets/QApplication>
#include <QtCore/QRandomGenerator>
#include <QStringListModel>


QT_CHARTS_USE_NAMESPACE


AdminGUI::AdminGUI(AdminService &adminService1, QWidget *parent) : adminService{adminService1}, QDialog{parent}{
    this->initGUI();
    this->populateList();
    this->connectSignalsAndSlots();
}

void AdminGUI::initGUI() {
    this->dogsListView = new QListWidget{};
    this->nameLineEdit = new QLineEdit{};
    this->breedLineEdit = new QLineEdit{};
    this->ageLineEdit = new QLineEdit{};
    this->photoLineEdit = new QLineEdit{};
    this->addButton = new QPushButton{"Add"};
    this->deleteButton = new QPushButton{"Delete"};
    this->updateAgeButton = new QPushButton{"Update age"};
    this->updatePhotographButton = new QPushButton{"Update photograph"};
    this->statisticsButton = new QPushButton{"See statistics"};

    QVBoxLayout* mainLayout = new QVBoxLayout{this};
    mainLayout->addWidget(this->dogsListView);

    QFormLayout *dogDetailsLayout = new QFormLayout{};
    dogDetailsLayout->addRow("Name:", this->nameLineEdit);
    dogDetailsLayout->addRow("Breed:", this->breedLineEdit);
    dogDetailsLayout->addRow("Age:", this->ageLineEdit);
    dogDetailsLayout->addRow("Photo:", this->photoLineEdit);

    mainLayout->addLayout(dogDetailsLayout);


    QGridLayout *buttonsLayout = new QGridLayout{};
    buttonsLayout->addWidget(this->addButton, 0, 0);
    buttonsLayout->addWidget(this->deleteButton, 0, 1);
    buttonsLayout->addWidget(this->updateAgeButton, 0, 2);
    buttonsLayout->addWidget(this->updatePhotographButton, 0, 3);
    buttonsLayout->addWidget(this->statisticsButton, 1, 1, 1, 2);

    this->setWindowTitle("Admin mode");
    mainLayout->addLayout(buttonsLayout);
}

void AdminGUI::populateList() {
    this->dogsListView->clear();
    vector<Dog> allDogs = this->adminService.get_dog_array();

    for(Dog& dog : allDogs){
        this->dogsListView->addItem(QString::fromStdString(dog.get_dog_name() + " - " + dog.get_dog_breed() + " - " +
                                                           to_string(dog.get_dog_age()) + " - " + dog.get_dog_photograph()));
    }

//    // build a predefined model: QStringListModel
//    QStringListModel* model = new QStringListModel{};
//    QStringList list;
//    for (Dog& dog : this->adminService.get_dog_array())
//        list.append(QString::fromStdString(dog.get_dog_name() + " - " + dog.get_dog_breed() + " - " +
//        to_string(dog.get_dog_age()) + " - " + dog.get_dog_photograph()));
//
//    model->setStringList(list);
//    this->dogsListView->setModel(model);
}

void AdminGUI::addDog() {
    string name = this->nameLineEdit->text().toStdString();
    string breed = this->breedLineEdit->text().toStdString();
    string age = this->ageLineEdit->text().toStdString();
    string photo = this->photoLineEdit->text().toStdString();
    try{
        this->adminService.add_dog(breed, age, name, photo);

        this->populateList();

        int lastElement = this->adminService.get_dog_array().size() - 1;
        this->dogsListView->setCurrentRow(lastElement);
    }
    catch(const CustomException& operation_exception){
        QMessageBox::critical(this, "Error", operation_exception.what());
    }
}

void AdminGUI::deleteDog() {
    int selectedIndex = this->getSelectedIndex();
    if(selectedIndex < 0){
        QMessageBox::critical(this, "Error", "No dog was selected!");
        return;
    }
    Dog dog = this->adminService.get_dog_array()[selectedIndex];
    string breed = dog.get_dog_breed();
    string name = dog.get_dog_name();
    try{
        this->adminService.delete_dog(breed, name);
        this->populateList();
    }
    catch(const CustomException& operation_exception){
        QMessageBox::critical(this, "Error", operation_exception.what());
    }
}

void AdminGUI::updateDogAge() {
    string name = this->nameLineEdit->text().toStdString();
    string breed = this->breedLineEdit->text().toStdString();
    string age = this->ageLineEdit->text().toStdString();
    try{
        this->adminService.update_dog_age(breed, name, age);
        this->populateList();
    }
    catch(const CustomException& operationException){
        QMessageBox::critical(this, "Error", operationException.what());
    }
}

void AdminGUI::updateDogPhotograph() {
    string name = this->nameLineEdit->text().toStdString();
    string breed = this->breedLineEdit->text().toStdString();
    string photograph = this->photoLineEdit->text().toStdString();
    try{
        this->adminService.update_dog_photograph(breed, name, photograph);
        this->populateList();
    }
    catch(const CustomException& operationException){
        QMessageBox::critical(this, "Error", operationException.what());
    }
}



void AdminGUI::connectSignalsAndSlots() {
    QObject::connect(this->dogsListView, &QListWidget::itemSelectionChanged, [this](){
        int selectedIndex = this->getSelectedIndex();
        if(selectedIndex < 0)
            return;

        Dog dog = this->adminService.get_dog_array()[selectedIndex];
        this->nameLineEdit->setText(QString::fromStdString(dog.get_dog_name()));
        this->breedLineEdit->setText(QString::fromStdString(dog.get_dog_breed()));
        this->ageLineEdit->setText(QString::fromStdString(to_string(dog.get_dog_age())));
        this->photoLineEdit->setText(QString::fromStdString(dog.get_dog_photograph()));
    });

    QObject::connect(this->addButton, &QPushButton::clicked, this, &AdminGUI::addDog);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &AdminGUI::deleteDog);
    QObject::connect(this->updateAgeButton, &QPushButton::clicked, this, &AdminGUI::updateDogAge);
    QObject::connect(this->updatePhotographButton, &QPushButton::clicked, this, &AdminGUI::updateDogPhotograph);
    QObject::connect(this->statisticsButton, &QPushButton::clicked, this, &AdminGUI::seeStatistics);
}

int AdminGUI::getSelectedIndex() const {
    QModelIndexList selectedIndexes = this->dogsListView->selectionModel()->selectedIndexes();
    if(selectedIndexes.empty()){
        this->nameLineEdit->clear();
        this->breedLineEdit->clear();
        this->ageLineEdit->clear();
        this->photoLineEdit->clear();
        return -1;
    }

    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

int AdminGUI::findPositionOfDogBreed(string dog_breed, vector<string> breeds) {
    for(int i=0; i<breeds.size(); i++)
        if(breeds[i] == dog_breed)
            return i;
    return -1;
}

void AdminGUI::seeStatistics() {
    QWidget *statisticsWindow = new QWidget{};
    QLayout *mainLayout = new QHBoxLayout{};

    this->breedSeries = new QPieSeries();

    vector<Dog> allDogs = this->adminService.get_dog_array();

    vector<string> breeds;
    vector<int> frequencies;

    for(Dog& dog : allDogs){
        int position = findPositionOfDogBreed(dog.get_dog_breed(), breeds);
        if(position != -1)
            frequencies[position]++;
        else{
            breeds.push_back(dog.get_dog_breed());
            frequencies.push_back(1);
        }
    }

    for(int i = 0; i<breeds.size(); i++){
        QPieSlice *slice = new QPieSlice();
        slice->setValue(frequencies[i]);
        slice->setLabelVisible();
        slice->setLabel(QString::fromStdString(breeds[i]+ " : " + to_string(frequencies[i])));
        slice->setLabelFont(QFont("Arial", 8));
        breedSeries->append(slice);
    }
    breedSeries->slices();

    QChart *chart = new QChart();
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->addSeries(breedSeries);
    chart->setTitle("Breeds of dogs in our shelter");
    chart->setTitleFont(QFont("Arial", 14));
    chart->legend()->show();
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    mainLayout->addWidget(chartView);

    statisticsWindow->setLayout(mainLayout);
    statisticsWindow->setWindowTitle("Statistics");
    statisticsWindow->resize(1200, 800);
    statisticsWindow->show();
}
