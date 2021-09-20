//
// Created by daria on 27/05/2021.
//

#ifndef A10_911_ANDRIOAIE_DARIA_DOGCUSTOMMODEL_H
#define A10_911_ANDRIOAIE_DARIA_DOGCUSTOMMODEL_H
#include <QAbstractTableModel>
#include "DogRepository.h"
#include "AbstractAdoptionList.h"

class DogCustomModel :public QAbstractTableModel{
private:
    AbstractAdoptionList* adoptedDogs;
    DogRepository& repository;

public:
    DogCustomModel(AbstractAdoptionList* adoptedDogs, DogRepository& repository1, QObject* parent = nullptr);
    ~DogCustomModel();

    // number of rows
    int rowCount(const QModelIndex &parent = QModelIndex{}) const override;

    // number of columns
    int columnCount(const QModelIndex &parent = QModelIndex{}) const override;

    // Value at a given position
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // add header data
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // will be called when a cell is edited
//    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;

    // used to set certain properties of a cell
    Qt::ItemFlags flags(const QModelIndex & index) const override;

    void updateInternalData();
};


#endif //A10_911_ANDRIOAIE_DARIA_DOGCUSTOMMODEL_H
