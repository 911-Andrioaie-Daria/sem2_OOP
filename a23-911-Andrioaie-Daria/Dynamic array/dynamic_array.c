//
// Created by daria on 15/03/2021.
//

#include "dynamic_array.h"
typedef offer TElem;
#include <stdlib.h>

dynamic_array* create_dynamic_array(){
    dynamic_array* array = malloc(sizeof(dynamic_array));
    array->data = (TElem**)malloc(20 * sizeof(TElem*));
    array->length = 0;
    array->capacity = 20;

    return array;
}

void add(dynamic_array* current_list, TElem * new_element){
    //resize in case its needed
    if(current_list->length == current_list->capacity)
        resize(current_list, current_list->capacity * 2);

    current_list->data[current_list->length] = new_element;
    current_list->length = current_list->length + 1;
}

void delete_(dynamic_array* array, int position){

    *array->data[position] = *array->data[array->length - 1];
    free(array->data[array->length - 1]);
    array->length = array->length - 1;

    // resize in case it s needed.
    if(array->length <= array->capacity / 4)
        resize(array, array->capacity / 2);
}

void update(dynamic_array* current_offers, int position, TElem* new_element){
    free(current_offers->data[position]);
    current_offers->data[position] = new_element;
}


void resize(dynamic_array* array, int new_capacity){

    dynamic_array* new_array = (dynamic_array*)malloc(sizeof(dynamic_array));
    new_array->data = (TElem **)malloc(new_capacity*sizeof(TElem*));
    new_array->capacity = new_capacity;

    int old_capacity = array->capacity;
    int elements_count = array->length;
    if(old_capacity < new_capacity){
        for(int i=0; i < elements_count; i++)
            new_array->data[i] = array->data[i];
        new_array->length = elements_count;
    }
    else{
        for(int i=0; i<new_capacity; i++)
            new_array->data[i] = array->data[i];
        new_array->length = new_capacity;
        for(int i=new_capacity; i < elements_count; i++)
            free(array->data[i]);
    }
    free(array->data);
    *array = *new_array;
    free(new_array);
}

void deallocate_array(dynamic_array* array){
    for(int index = 0; index < array->length; index++)
        free(array->data[index]);

    free(array->data);
    free(array);
}