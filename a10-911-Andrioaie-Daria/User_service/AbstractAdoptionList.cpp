//
// Created by daria on 19/04/2021.
//

#include "AbstractAdoptionList.h"

AbstractAdoptionList::AbstractAdoptionList() = default;

AbstractAdoptionList::~AbstractAdoptionList() = default;

CSVAdoptionList::CSVAdoptionList(const string& filename) {
    this->file = filename;
}

CSVAdoptionList::~CSVAdoptionList() = default;

HTMLAdoptionList::HTMLAdoptionList(const string& filename) {
    this->file = filename;
}

HTMLAdoptionList::~HTMLAdoptionList() = default;