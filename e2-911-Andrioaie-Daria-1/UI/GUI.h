//
// Created by daria on 22/06/2021.
//

#ifndef E2_911_ANDRIOAIE_DARIA_1_GUI_H
#define E2_911_ANDRIOAIE_DARIA_1_GUI_H

#include "Service.h"
#include <qwidget>
#include "EthWindow.h"
#include "MapWindow.h"

class GUI : public QWidget{
private:
    Service service;

    void openEthWindows();
    void openParkMap();

    /// graphical elements
    vector<QWidget*> ethWindows;

public:
    ~GUI();
    explicit GUI(Service& service1);

};


#endif //E2_911_ANDRIOAIE_DARIA_1_GUI_H
