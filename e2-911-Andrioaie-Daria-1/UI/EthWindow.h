//
// Created by daria on 22/06/2021.
//

#ifndef E2_911_ANDRIOAIE_DARIA_1_ETHWINDOW_H
#define E2_911_ANDRIOAIE_DARIA_1_ETHWINDOW_H

#include "Observer.h"
#include <qwidget>
#include "Service.h"
#include "TableModel.h"
#include "QTableView"
#include <QSortFilterProxyModel>
#include "QVBoxLayout"
#include "QPushButton"
#include "QLineEdit"
#include "QFormLayout"
#include "QMessageBox"

class EthWindow : public Observer, public QWidget{
private:
    Ethnologist& ethnologist;
    Service& service;
    void initEthWindow();
    void connectSignalsAndSlots();

    /// graphical
    TableModel* tableModel;
    QTableView* tableView;
    QSortFilterProxyModel* filterModel;
    QVBoxLayout* mainLayout;
    QPushButton *addButton, *updateButton;
    QLineEdit *descriptionLineEdit;
    QLineEdit *locationLineEdit;
    QFormLayout *addBuildingLayout;

public:
    void update() override;
    EthWindow(Service& service1, Ethnologist& ethnologist1);

    void colorYoursBlue();

    void addBuilding();

    int getSelectedIndex();

    void updateBuilding();

    void checkYourArea();

    ~EthWindow();
};


#endif //E2_911_ANDRIOAIE_DARIA_1_ETHWINDOW_H
