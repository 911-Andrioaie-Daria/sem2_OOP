//
// Created by daria on 04/05/2021.
//

#include "GUI.h"
#include "qlayout.h"
#include "QLabel"
#include "AdminGUI.h"
#include "UserGUI.h"
#include "setFileGUI.h"
#include <QtCharts/QBarSeries>

GUI::GUI(AdminService &adminService1, UserService &userService1, QWidget *parent)
        : QMainWindow(parent) ,adminService{adminService1}, userService{userService1} {

    this->initGUI();
    this->connectSignalsAndSlots();
}

void GUI::initGUI() {
    QWidget *widget = new QWidget{};
    QVBoxLayout* mainLayout = new QVBoxLayout{this};

    QLabel *welcomeLabel = new QLabel{QString::fromStdString("Welcome to the Happy Pets Shelter!")};
    welcomeLabel->setAlignment(Qt::AlignCenter);
    QFont font("Courier", 20, 10, true);
    welcomeLabel->setFont(font);

    QLabel *chooseModeLabel = new QLabel{QString::fromStdString("Please choose the mode:")};
    chooseModeLabel->setAlignment(Qt::AlignCenter);
    chooseModeLabel->setFont(font);

    mainLayout->addWidget(welcomeLabel);
    mainLayout->addWidget(chooseModeLabel);

    QHBoxLayout *buttonsLayout = new QHBoxLayout{this};
    this->adminModeButton = new QPushButton{"Admin mode"};
    this->userModeButton = new QPushButton{"User mode"};
    buttonsLayout->addWidget(this->adminModeButton);
    buttonsLayout->addWidget(this->userModeButton);

    QFont buttonsFont{"Courier", 12 };
    adminModeButton->setFont(buttonsFont);
    userModeButton->setFont(buttonsFont);

    mainLayout->addLayout(buttonsLayout);

    widget->setLayout(mainLayout);
    this->setWindowTitle("Happy Pets Shelter");
    setCentralWidget(widget);
}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->adminModeButton, &QPushButton::clicked, this, &GUI::startAdminMode);
    QObject::connect(this->userModeButton, &QPushButton::clicked, this, &GUI::startUserMode);
}

void GUI::startAdminMode() {
    this->close();
    this->setCursor(Qt::WaitCursor);
    AdminGUI *adminGui = new AdminGUI{adminService};
    adminGui->showNormal();
    this->setCursor(Qt::ArrowCursor);
}

void GUI::startUserMode() {
    this->close();
    this->setCursor(Qt::WaitCursor);
    setFileGUI *setFileGui = new setFileGUI{userService};
    setFileGui->showNormal();
    this->setCursor(Qt::ArrowCursor);
}
