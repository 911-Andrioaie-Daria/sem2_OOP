//
// Created by daria on 28/05/2021.
//

#ifndef A10_911_ANDRIOAIE_DARIA_PICTUREDELEGATE_H
#define A10_911_ANDRIOAIE_DARIA_PICTUREDELEGATE_H

#include <QStyledItemDelegate>

class PictureDelegate : public QStyledItemDelegate{
public:
    PictureDelegate(QWidget *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option,const QModelIndex &index) const override;


};


#endif //A10_911_ANDRIOAIE_DARIA_PICTUREDELEGATE_H
