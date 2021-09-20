//
// Created by daria on 28/05/2021.
//

#include "PictureDelegate.h"
#include <QPixmap>
#include <QPainter>

PictureDelegate::PictureDelegate(QWidget *parent): QStyledItemDelegate(parent) {

}

void PictureDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QString photograph = index.model()->data(index, Qt::EditRole).toString();

    if (index.column() != 3)
    {
        QStyledItemDelegate::paint(painter, option, index);
        return;
    }

    if (photograph.contains("Labrador"))
    {
        QPixmap pixMap("../Resources/Labrador.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else if (photograph.contains("Husky"))
    {
        QPixmap pixMap("../Resources/Husky.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else if (photograph.contains("Corgi"))
    {
        QPixmap pixMap("../Resources/Corgi.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else if (photograph.contains("Beagle"))
    {
        QPixmap pixMap("../Resources/Beagle.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
    else if (photograph.contains("Shepherd"))
    {
        QPixmap pixMap("../Resources/Shepherd.jpg");
        painter->drawPixmap(option.rect, pixMap);
    }
}

QSize PictureDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    if (index.column() == 3)
    {
        return QSize(32, 300);
    }
    return QStyledItemDelegate::sizeHint(option, index);
}
