//
// Created by daria on 05/05/2021.
//

#include "setFileGUI.h"
#include "qlayout.h"
#include "UserGUI.h"
#include "QLabel"

setFileGUI::setFileGUI(UserService &userService1, QWidget *parent): userService{userService1}, QDialog{parent} {
    this->initGUI();
    this->connectSignalsAndSlots();
}

void setFileGUI::initGUI() {
    QVBoxLayout *mainLayout = new QVBoxLayout{this};
    QLabel *chooseFileLabel = new QLabel{QString::fromStdString("Please select the type of file:")};
    chooseFileLabel->setAlignment(Qt::AlignCenter);
    QFont font("Courier", 20, 10, true);
    chooseFileLabel->setFont(font);

    mainLayout->addWidget(chooseFileLabel);


    QHBoxLayout *buttonsLayout = new QHBoxLayout{this};
    this->CSVButton = new QPushButton{"CSV file"};
    this->HTMLButton = new QPushButton{"HTML file"};
    buttonsLayout->addWidget(this->CSVButton);
    buttonsLayout->addWidget(this->HTMLButton);
    QFont buttonsFont{"Courier", 12 };
    CSVButton->setFont(buttonsFont);
    HTMLButton->setFont(buttonsFont);

    mainLayout->addLayout(buttonsLayout);
    this->setWindowTitle("User mode");
}

void setFileGUI::connectSignalsAndSlots() {
    QObject::connect(this->CSVButton, &QPushButton::clicked, this, &setFileGUI::setCSVFile);
    QObject::connect(this->HTMLButton, &QPushButton::clicked, this, &setFileGUI::setHTMLFile);
}

void setFileGUI::setCSVFile() {
    this->close();

    this->userService.setCSVFile();
    this->setCursor(Qt::WaitCursor);
    UserGUI *userGui = new UserGUI{userService};
    userGui->show();
    this->setCursor(Qt::ArrowCursor);
}

void setFileGUI::setHTMLFile() {
    this->close();

    this->userService.setHTMLFile();
    this->setCursor(Qt::WaitCursor);
    UserGUI *userGui = new UserGUI{userService};
    userGui->show();
    this->setCursor(Qt::ArrowCursor);
}

