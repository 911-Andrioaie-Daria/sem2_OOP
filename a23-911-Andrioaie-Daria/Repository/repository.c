//
// Created by daria on 05/03/2021.
//

#include "repository.h"
#include <stdlib.h>


repo* create_offer_repository(){
    repo *offer_repository = (repo*)malloc(sizeof(repo));
    offer_repository->list_of_offers = create_dynamic_array();

    //offer_repository->list_of_offers.data = (offer**)malloc(20*sizeof(offer*));
    //offer_repository->list_of_offers.capacity = 20;

    offer_repository->history_of_states.past_lists = (dynamic_array**)malloc(20*sizeof(dynamic_array));
    offer_repository->history_of_states.index_of_current_list = -1;
    offer_repository->history_of_states.length_of_history = 0;

    date departure_date;
    departure_date.year = 2022;
    departure_date.month = 3;
    departure_date.day = 30;
    offer_repository->list_of_offers->data[0] = create_offer("city break", "London", departure_date, rand()%301);

    departure_date.day--;
    offer_repository->list_of_offers->data[1] = create_offer("seaside", "Vama Veche", departure_date, rand()%301);

    departure_date.day--;
    offer_repository->list_of_offers->data[2] = create_offer("mountain", "Mont Blanc", departure_date, rand()%301);

    departure_date.day--;
    offer_repository->list_of_offers->data[3] = create_offer("city break", "Milano", departure_date, rand()%301);

    departure_date.day--;
    offer_repository->list_of_offers->data[4] = create_offer("seaside", "Constanta", departure_date, rand()%301);

    departure_date.day--;
    offer_repository->list_of_offers->data[5] = create_offer("mountain", "Fagaras", departure_date, rand()%301);

    departure_date.day--;
    offer_repository->list_of_offers->data[6] = create_offer("city break", "Wien", departure_date, rand()%301);

    departure_date.day--;
    offer_repository->list_of_offers->data[7] = create_offer("seaside", "Miami Beach", departure_date, rand()%301);

    departure_date.day--;
    offer_repository->list_of_offers->data[8] = create_offer("mountain", "Apuseni", departure_date, rand()%301);

    departure_date.day--;
    offer_repository->list_of_offers->data[9] = create_offer("city break", "Manchester", departure_date, rand()%301);

    int* length = get_offer_count(offer_repository);
    *length = 10;

    add_current_list_to_history(offer_repository);
    //offer_repository->history_of_states.past_lists[0] = &offer_repository->list_of_offers;
    //offer_repository->history_of_states.index_of_current_list = 0;
    //offer_repository->history_of_states.length_of_history = 1;

    return offer_repository;
}


void add_current_list_to_history(repo* offer_repository){
    int *length = get_offer_count(offer_repository);
    int *capacity = get_capacity(offer_repository);
    offer** current_list_of_offers = get_data(offer_repository);
    history_array* archive = get_archive(offer_repository);
    int* length_of_archive = get_length_of_archive(offer_repository);
    int* index_of_current_list = get_index_of_current_list_in_archive(offer_repository);

    dynamic_array* copy_of_current_list = (dynamic_array*)malloc(sizeof(dynamic_array));
    copy_of_current_list->data = (offer**)malloc(offer_repository->list_of_offers->length * sizeof(offer*));
    for(int i=0; i<*length; i++){
        copy_of_current_list->data[i] = (offer*)malloc(sizeof(offer));
        *copy_of_current_list->data[i] = *current_list_of_offers[i];
    }
    copy_of_current_list->length = *length;
    copy_of_current_list->capacity = *capacity;


    //deallocate what comes after the current list
    for(int index = *index_of_current_list + 1; index<*length_of_archive; index++){
        for(int offer=0; offer < archive->past_lists[index]->length;offer++)
            free(archive->past_lists[index]->data[offer]);
        free(archive->past_lists[index]->data);
    }


    // actually add to the history
    archive->past_lists[*index_of_current_list + 1] = copy_of_current_list;
    *index_of_current_list = *index_of_current_list + 1;
    *length_of_archive = *index_of_current_list + 1;
}

dynamic_array* get_list_of_offers(repo* offer_repository){
    return offer_repository->list_of_offers;
}

offer** get_data(repo* offer_repository){
    return offer_repository->list_of_offers->data;
}

int* get_offer_count(repo* offer_repository){
    return &offer_repository->list_of_offers->length;
}

int* get_capacity(repo* offer_repository){
    return &offer_repository->list_of_offers->capacity;
}

history_array* get_archive(repo* offer_repository){
    return &offer_repository->history_of_states;
}

int* get_length_of_archive(repo* offer_repository){
    return &offer_repository->history_of_states.length_of_history;
}

int* get_index_of_current_list_in_archive(repo* offer_repository){
    return &offer_repository->history_of_states.index_of_current_list;
}

void add_offer_to_repo(repo* offer_repository, offer* new_offer){
    dynamic_array* current_list = get_list_of_offers(offer_repository);
    add(current_list, new_offer);
    add_current_list_to_history(offer_repository);
}

void delete_offer_from_repo(repo* offer_repository, int position){
    dynamic_array* current_list = get_list_of_offers(offer_repository);
    delete_(current_list, position);
    add_current_list_to_history(offer_repository);
}

void update_type_of_offer_in_repo(repo* offer_repository, int position, char* new_type){
    dynamic_array* current_list = get_list_of_offers(offer_repository);
    offer* updated_offer = (offer*)malloc(sizeof(offer));;
    *updated_offer = *current_list->data[position];
    set_type_of_offer(updated_offer, new_type);

    update(current_list, position, updated_offer);

    add_current_list_to_history(offer_repository);
}

void update_price_of_offer_in_repo(repo* offer_repository, int position, int new_price){
    dynamic_array* current_list = get_list_of_offers(offer_repository);
    offer* updated_offer = (offer*)malloc(sizeof(offer));
    *updated_offer = *current_list->data[position];
    set_price_of_offer(updated_offer, new_price);

    update(current_list, position, updated_offer);

    add_current_list_to_history(offer_repository);
}

void resize_repository(repo* offer_repository, int new_capacity){
    dynamic_array* current_list_of_offers = get_list_of_offers(offer_repository);
    resize(current_list_of_offers, new_capacity);

}

void deallocate_repository(repo* offer_repository){
    dynamic_array* current_list = get_list_of_offers(offer_repository);
    deallocate_array(current_list);

    //free the history
    history_array* history = get_archive(offer_repository);
    for(int list=0; list<history->length_of_history; list++){
        for(int offer_index=0; offer_index < history->past_lists[list]->length; offer_index++)
            free(history->past_lists[list]->data[offer_index]);
        free(history->past_lists[list]->data);
        free(history->past_lists[list]);
    }
    free(history->past_lists);

    free(offer_repository);

}

void deallocate_dynamic_array(dynamic_array* offer_array){
    free(offer_array->data);
    free(offer_array);
}