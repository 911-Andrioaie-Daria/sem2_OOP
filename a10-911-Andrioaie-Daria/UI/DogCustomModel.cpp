//
// Created by daria on 27/05/2021.
//

#include "DogCustomModel.h"
#include <QFont>

DogCustomModel::~DogCustomModel() {

}

DogCustomModel::DogCustomModel(AbstractAdoptionList *adoptedDogs, DogRepository &repository1, QObject *parent):
adoptedDogs{adoptedDogs}, repository{repository1}, QAbstractTableModel{parent}{

}

int DogCustomModel::rowCount(const QModelIndex &parent) const {
    return this->adoptedDogs->get_data().size();
}

int DogCustomModel::columnCount(const QModelIndex &parent) const {
    return 4;
}

QVariant DogCustomModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();
    if( role == Qt::DisplayRole || role == Qt::EditRole)
    {
        vector<Dog> adoptedDogsArray = this->adoptedDogs->get_data();
        if(!adoptedDogsArray.empty()){
            Dog dog = adoptedDogsArray.at(row);
            switch(column)
            {
                case 0:
                    return QString::fromStdString(dog.get_dog_name());

                case 1:
                    return QString::fromStdString(dog.get_dog_breed());

                case 2:
                    return QString::fromStdString(to_string(dog.get_dog_age()));

                case 3:
                    return QString::fromStdString(dog.get_dog_photograph());

                default:
                    break;
            }
        }
    }
    if(role == Qt::FontRole){

        QFont font("Times", 15, 10, true);
        font.setItalic(false);
        return font;
    }
    return QVariant{};
}

QVariant DogCustomModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            switch(section){
                case 0:
                    return QString{"Name"};

                case 1:
                    return QString{"Breed"};

                case 2:
                    return QString{"Age"};

                case 3:
                    return QString{"Photograph"};

                default:
                    break;
            }
        }
    }
    if(role == Qt::FontRole)
    {
        QFont font("Times", 10, 10, true);
        return font;
    }
    return QVariant{};
}

Qt::ItemFlags DogCustomModel::flags(const QModelIndex &index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void DogCustomModel::updateInternalData() {
    endResetModel();
}
