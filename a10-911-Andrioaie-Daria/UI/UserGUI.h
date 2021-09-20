//
// Created by daria on 05/05/2021.
//

#ifndef A89_911_ANDRIOAIE_DARIA_USERGUI_H
#define A89_911_ANDRIOAIE_DARIA_USERGUI_H
#include "qwidget.h"
#include "qlistwidget.h"
#include "qlineedit.h"
#include "qpushbutton.h"
#include "UserService.h"
#include <QDialog>
#include "qshortcut.h"
#include "qtableview.h"
#include "DogCustomModel.h"

class UserGUI : public QDialog{
private:
    UserService& userService;
    DogCustomModel* dogsModel;
    void initGUI();
    void populateAvailableListWithBreed();
    void populateAvailableListWithAll();
    void populateAdoptedList();
    int getSelectedIndex() const;
    void adoptDog();
    void openInApp();
    void undoAdoption();
    void redoAdoption();
    void notifyModel();

    void connectSignalsAndSlots();
    QListWidget *availableDogsListWidget, *adoptedDogsListWidget;
    QTableView* adoptedDogsTableView;
    QLineEdit *breedLineEdit;
    QPushButton *seeBreedButton, *seeAllButton, *adoptButton, *openApplicationButton, *undoButton, *redoButton;
    QShortcut *undoShortcut, *redoShortcut;

public:
    UserGUI(UserService& userService1, QWidget *parent = nullptr);
//    ~UserGUI();
};


#endif //A89_911_ANDRIOAIE_DARIA_USERGUI_H
