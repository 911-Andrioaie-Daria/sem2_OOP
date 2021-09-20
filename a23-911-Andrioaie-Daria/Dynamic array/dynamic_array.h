//
// Created by daria on 15/03/2021.
//

#ifndef A23_911_ANDRIOAIE_DARIA_DYNAMIC_ARRAY_H
#define A23_911_ANDRIOAIE_DARIA_DYNAMIC_ARRAY_H

#endif //A23_911_ANDRIOAIE_DARIA_DYNAMIC_ARRAY_H
#include "Domain/offer.h"
typedef offer TElem;


/// The structure holds:
/// an array of pointers to offer instances.
/// the length of this collection.
/// the maximum capacity.
typedef struct{
    TElem ** data;
    int length;
    int capacity;
} dynamic_array;

dynamic_array* create_dynamic_array();

void add(dynamic_array* current_list, TElem* new_element);

void delete_(dynamic_array* array, int position);

void update(dynamic_array* current_offers, int position, TElem* updated_element);

//void update_offer_type(dynamic_array* current_offers, int position, char* new_type);

void resize(dynamic_array* array, int new_capacity);

void deallocate_array(dynamic_array* array);