//
// Created by daria on 04/05/2021.
//

#ifndef A89_911_ANDRIOAIE_DARIA_ADMINGUI_H
#define A89_911_ANDRIOAIE_DARIA_ADMINGUI_H
#include "qwidget.h"
#include "qlistwidget.h"
#include "qlineedit.h"
#include "qpushbutton.h"
#include "AdminService.h"
#include "UserService.h"
#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>

class AdminGUI : public QDialog{
private:
    AdminService& adminService;
    void initGUI();
    void populateList();
    void connectSignalsAndSlots();

    int getSelectedIndex() const;
    void addDog();
    void deleteDog();
    void updateDogAge();
    void updateDogPhotograph();
    void seeStatistics();
    int findPositionOfDogBreed(string dog_breed, vector<string> breeds);
    /// graphical elements
    QListWidget* dogsListView;
    QLineEdit *nameLineEdit, *breedLineEdit, *ageLineEdit, *photoLineEdit;
    QPushButton *addButton, *deleteButton, *updateAgeButton, *updatePhotographButton, *statisticsButton;
    QtCharts::QPieSeries *breedSeries;

public:
    AdminGUI(AdminService &adminService1, QWidget *parent = nullptr);
    //~AdminGUI();
};


#endif //A89_911_ANDRIOAIE_DARIA_ADMINGUI_H
