//
// Created by daria on 22/06/2021.
//

#ifndef E2_911_ANDRIOAIE_DARIA_1_MAPWINDOW_H
#define E2_911_ANDRIOAIE_DARIA_1_MAPWINDOW_H

#include "Observer.h"
#include <QWidget>
#include <QPainter>
#include "Service.h"

class MapWindow : public Observer, public QWidget{
private:
    Service& service;
    int x;
    int y;
public:
public:
    MapWindow(Service& service1);
    ~MapWindow();
    void update() override;

    QSize sizeHint() const Q_DECL_OVERRIDE;

    void drawPark();

    void resizeEvent(QResizeEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

};


#endif //E2_911_ANDRIOAIE_DARIA_1_MAPWINDOW_H
