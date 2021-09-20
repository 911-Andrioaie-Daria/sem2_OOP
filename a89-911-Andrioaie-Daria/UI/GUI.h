//
// Created by daria on 04/05/2021.
//

#ifndef A89_911_ANDRIOAIE_DARIA_GUI_H
#define A89_911_ANDRIOAIE_DARIA_GUI_H
#include "qdialog.h"
#include "qmainwindow.h"
#include "AdminService.h"
#include "UserService.h"
#include "qpushbutton.h"
#include "AdminGUI.h"

class GUI : public QMainWindow{
    Q_OBJECT
private:
    AdminService& adminService;
    UserService& userService;
    void initGUI();
    void connectSignalsAndSlots();
    void startAdminMode();
    void startUserMode();

    /// graphical elements
    QPushButton *adminModeButton, *userModeButton;

public:
    GUI(AdminService &adminService1, UserService &userService1, QWidget *parent = nullptr);
    //~GUI();
};


#endif //A89_911_ANDRIOAIE_DARIA_GUI_H
