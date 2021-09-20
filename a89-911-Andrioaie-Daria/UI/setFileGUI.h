//
// Created by daria on 05/05/2021.
//

#ifndef A89_911_ANDRIOAIE_DARIA_SETFILEGUI_H
#define A89_911_ANDRIOAIE_DARIA_SETFILEGUI_H

#include "UserService.h"
#include <QDialog>
#include "qpushbutton.h"

class setFileGUI : public QDialog{
private:
    UserService& userService;
    void initGUI();
    void connectSignalsAndSlots();

    void setCSVFile();
    void setHTMLFile();

    QPushButton *CSVButton, *HTMLButton;

public:
    setFileGUI(UserService& userService1, QWidget *parent = nullptr);
    //~setFileGUI();
};


#endif //A89_911_ANDRIOAIE_DARIA_SETFILEGUI_H
