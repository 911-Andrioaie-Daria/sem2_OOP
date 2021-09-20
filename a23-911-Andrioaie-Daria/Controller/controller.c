//
// Created by daria on 05/03/2021.
//

#include "controller.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool compare_prices(offer* offer1, offer* offer2){
    return (get_price(offer1)<get_price(offer2));
}

bool compare_departure_dates(offer* offer1, offer* offer2){
    return is_date_before(get_departure_date(offer1), get_departure_date(offer2));
}

bool compare_destinations(offer* offer1, offer* offer2){
    if (strcmp(get_destination(offer1), get_destination(offer2)) <= 0)
        return true;
    return false;
}

bool is_city_break_offer(offer* offer1){
    if(strcmp(get_type(offer1), "city break") == 0)
        return true;
    return false;
}

bool is_mountain_offer(offer* offer1){
    if(strcmp(get_type(offer1), "mountain") == 0)
        return true;
    return false;
}

bool is_seaside_offer(offer* offer1){
    if(strcmp(get_type(offer1), "seaside") == 0)
        return true;
    return false;
}

service* create_offer_service(repo *offer_repository){
    service *offer_service = (service*) malloc(sizeof(service));
    offer_service->offer_repository = offer_repository;
    return offer_service;
}

repo* get_repository(service* offer_service){
    return offer_service->offer_repository;
}

int search_for_offer(service *offer_service, char* destination, date departure_date){
    repo *offer_repository = get_repository(offer_service);
    offer** offer_data = get_data(offer_repository);
    int* offer_count = get_offer_count(offer_repository);

    for(int i=0; i<*offer_count; i++){
        char* current_offer_destination = get_destination(offer_data[i]);
        date current_offer_date = get_departure_date(offer_data[i]);
        if(strcmp(current_offer_destination, destination)==0 && are_dates_equal(departure_date, current_offer_date))
            return i;
    }
    return -1;
}

void add_offer_to_service(service *offer_service, char *type, char *destination, int departure_year, int departure_month,
                          int departure_day, int price){

    date departure_date;
    departure_date.year = departure_year;
    departure_date.month = departure_month;
    departure_date.day = departure_day;
    offer* new_offer = create_offer(type, destination, departure_date, price);
    add_offer_to_repo(offer_service->offer_repository, new_offer);
}

bool delete_offer_from_service(service *offer_service, char *destination, int departure_year, int departure_month, int departure_day){
    date departure_date;
    departure_date.year = departure_year;
    departure_date.month = departure_month;
    departure_date.day = departure_day;

    int position = search_for_offer(offer_service, destination, departure_date);

    if(position == -1){
        return false;
    }
    else{
        delete_offer_from_repo(offer_service->offer_repository, position);
        return true;
    }
}

bool update_type_of_offer(service *offer_service, char destination[], int departure_year, int departure_month, int departure_day, char* new_type){
    date departure_date;
    departure_date.year = departure_year;
    departure_date.month = departure_month;
    departure_date.day = departure_day;

    int position = search_for_offer(offer_service, destination, departure_date);

    if(position == -1){
        return false;
    }
    else{
        update_type_of_offer_in_repo(offer_service->offer_repository, position, new_type);
        return true;
    }

}


bool update_price_of_offer(service *offer_service, char destination[], int departure_year, int departure_month, int departure_day, int new_price){
    date departure_date;
    departure_date.year = departure_year;
    departure_date.month = departure_month;
    departure_date.day = departure_day;

    int position = search_for_offer(offer_service, destination, departure_date);

    if(position == -1){
        return false;
    }
    else{
        update_price_of_offer_in_repo(offer_service->offer_repository, position, new_price);
        return true;
    }
}

void sort_ascending(dynamic_array* offer_data, bool (*compare_function)(offer*, offer*)){

    int length = offer_data->length;
    for(int i=0;i<length-1;i++)
        for(int j=i+1; j<length;j++){
            if(compare_function(offer_data->data[i], offer_data->data[j])== false)
            {
                offer* auxiliary = offer_data->data[i];
                offer_data->data[i] = offer_data->data[j];
                offer_data->data[j] = auxiliary;
            }
        }
}

void sort_ascending_by_price(dynamic_array* offer_data){
    int length = offer_data->length;
    for(int i=0;i<length-1;i++)
        for(int j=i+1; j<length;j++)
            if(get_price(offer_data->data[i]) > get_price(offer_data->data[j]))
            {
                offer* auxiliary = offer_data->data[i];
                offer_data->data[i] = offer_data->data[j];
                offer_data->data[j] = auxiliary;
            }
}

void sort_ascending_by_departure_date(dynamic_array* offer_data){
    int length = offer_data->length;
    for(int i=0;i<length-1;i++)
        for(int j=i+1; j<length;j++)
            if(is_date_before(get_departure_date(offer_data->data[j]), get_departure_date(offer_data->data[i])))
            {
                offer* auxiliary = offer_data->data[i];
                offer_data->data[i] = offer_data->data[j];
                offer_data->data[j] = auxiliary;
            }
}


dynamic_array* search_by_destination_service(service *offer_service, char* string, int sorting_option){
    offer** offer_data = get_data(offer_service->offer_repository);
    int* offer_count = get_offer_count(offer_service->offer_repository);

    dynamic_array* resulted_offers = (dynamic_array*)malloc(sizeof(dynamic_array));
    resulted_offers->data = (offer**)malloc(*offer_count * sizeof(offer*));
    resulted_offers->length = 0;

    if(strcmp(string, "\n")==0){
        for(int i=0; i<*offer_count; i++)
            resulted_offers->data[i] = offer_data[i];
        resulted_offers->length = *offer_count;
    }
    else {
        for (int i = 0; i < *offer_count; i++) {
            char *offer_destination = get_destination(offer_data[i]);
            if (strstr(offer_destination, string)) {
                resulted_offers->data[resulted_offers->length] = offer_data[i];
                resulted_offers->length++;
            }
        }
    }

    bool (*compare_function)(offer*, offer*);

    if(sorting_option == 0)
        compare_function = compare_departure_dates;
    else
        if(sorting_option == 1)
            compare_function = compare_prices;
        else
            compare_function = compare_destinations;

    sort_ascending(resulted_offers, compare_function);
    return resulted_offers;
}


dynamic_array* search_city_break_offers(service *offer_service, date departure_date){
    offer** offer_data = get_data(offer_service->offer_repository);
    int* offer_count = get_offer_count(offer_service->offer_repository);

    dynamic_array* resulted_offers = (dynamic_array *)malloc(sizeof(dynamic_array));
    resulted_offers->data = (offer**)malloc(*offer_count * sizeof(offer*));
    resulted_offers->length = 0;

    for(int i=0; i<*offer_count; i++){
        char* current_offer_type = get_type(offer_data[i]);
        date current_offer_date = get_departure_date(offer_data[i]);
        if(strcmp(current_offer_type, "city break") == 0 && is_date_before(departure_date, current_offer_date)){
            resulted_offers->data[resulted_offers->length] = offer_data[i];
            resulted_offers->length++;
        }
    }
    return resulted_offers;
}

dynamic_array* search_seaside_offers(service *offer_service, date departure_date){
    offer** offer_data = get_data(offer_service->offer_repository);
    int* offer_count = get_offer_count(offer_service->offer_repository);

    dynamic_array* resulted_offers = (dynamic_array *)malloc(sizeof(dynamic_array));
    resulted_offers->data = (offer**)malloc(*offer_count * sizeof(offer*));
    resulted_offers->length = 0;

    for(int i=0; i<*offer_count; i++){
        char* current_offer_type = get_type(offer_data[i]);
        date current_offer_date = get_departure_date(offer_data[i]);
        if(strcmp(current_offer_type, "seaside") == 0 && is_date_before(departure_date, current_offer_date)){
            resulted_offers->data[resulted_offers->length] = offer_data[i];
            resulted_offers->length++;
        }
    }
    return resulted_offers;
}

dynamic_array* search_mountain_offers(service *offer_service, date departure_date){
    offer** offer_data = get_data(offer_service->offer_repository);
    int* offer_count = get_offer_count(offer_service->offer_repository);

    dynamic_array* resulted_offers = (dynamic_array *)malloc(sizeof(dynamic_array));
    resulted_offers->data = (offer**)malloc(*offer_count * sizeof(offer*));
    resulted_offers->length = 0;

    for(int i=0; i<*offer_count; i++){
        char* current_offer_type = get_type(offer_data[i]);
        date current_offer_date = get_departure_date(offer_data[i]);
        if(strcmp(current_offer_type, "mountain") == 0 && is_date_before(departure_date, current_offer_date)){
            resulted_offers->data[resulted_offers->length] = offer_data[i];
            resulted_offers->length++;
        }
    }
    return resulted_offers;
}


dynamic_array* filter_offers_with_given_property(service *offer_service, bool (*property)(offer*), date departure_date){
    offer** offer_data = get_data(offer_service->offer_repository);
    int* offer_count = get_offer_count(offer_service->offer_repository);

    dynamic_array* resulted_offers = (dynamic_array *)malloc(sizeof(dynamic_array));
    resulted_offers->data = (offer**)malloc(*offer_count * sizeof(offer*));
    resulted_offers->length = 0;

    for(int i=0; i<*offer_count; i++){
        date current_offer_date = get_departure_date(offer_data[i]);
        if(property(offer_data[i]) && is_date_before(departure_date, current_offer_date)){
            resulted_offers->data[resulted_offers->length] = offer_data[i];
            resulted_offers->length++;
        }
    }
    return resulted_offers;
}

dynamic_array* search_by_type_after_date_service(service *offer_service, int type_option,
                                          int departure_year, int departure_month, int departure_day){

    dynamic_array* resulted_offers;
    date departure_date;
    departure_date.year = departure_year;
    departure_date.month = departure_month;
    departure_date.day = departure_day;


    bool (*property)(offer*);

    if(type_option == 0)
        property = is_city_break_offer;
    else
        if(type_option == 1)
            property = is_seaside_offer;
        else
            property = is_mountain_offer;

    resulted_offers = filter_offers_with_given_property(offer_service, property, departure_date);
    return resulted_offers;
}


bool undo_service(service *offer_service){
    int* index_of_current_list = get_index_of_current_list_in_archive(offer_service->offer_repository);
    if(*index_of_current_list == 0)
        return false;

    dynamic_array* current_list_of_offers = get_list_of_offers_from_service(offer_service);
    history_array* history_list = get_history(offer_service);
    dynamic_array* previous_list = history_list->past_lists[*index_of_current_list-1];

    if(previous_list->length > current_list_of_offers->capacity)
        resize_repository(offer_service->offer_repository, previous_list->length);

    for(int i=0; i<previous_list->length;i++)
        *current_list_of_offers->data[i] = *previous_list->data[i];
    current_list_of_offers->length = previous_list->length;

    *index_of_current_list = *index_of_current_list-1;

    return true;
}

bool redo_service(service *offer_service){
    int* index_of_current_list = get_index_of_current_list_in_archive(offer_service->offer_repository);
    int* length_of_archive = get_length_of_archive(offer_service->offer_repository);
    if(*index_of_current_list == *length_of_archive-1)
        return false;

    //offer** offer_data = get_data_from_service(offer_service);
    //int* length = get_offer_count_from_service(offer_service);

    dynamic_array* current_list_of_offers = get_list_of_offers_from_service(offer_service);
    history_array* history_list = get_history(offer_service);
    dynamic_array* anterior_list = history_list->past_lists[*index_of_current_list+1];

    if(anterior_list->length > current_list_of_offers->capacity)
        resize_repository(offer_service->offer_repository, anterior_list->length);

    for(int i=0; i<anterior_list->length;i++)
        *current_list_of_offers->data[i] = *anterior_list->data[i];
    current_list_of_offers->length = anterior_list->length;

    *index_of_current_list = *index_of_current_list+1;

    return true;
}


void deallocate_service(service *offer_service){
    deallocate_repository(offer_service->offer_repository);
    free(offer_service);
}

dynamic_array* get_list_of_offers_from_service(service *offer_service){
    repo* offer_repository = get_repository(offer_service);
    return offer_repository->list_of_offers;
}


int* get_offer_count_from_service(service *offer_service){
    repo* offer_repository = get_repository(offer_service);
    return get_offer_count(offer_repository);
}

offer** get_data_from_service(service *offer_service){
    repo* offer_repository = get_repository(offer_service);
    return get_data(offer_repository);
}

history_array* get_history(service *offer_service){
    repo* offer_repository = get_repository(offer_service);
    return get_archive(offer_repository);
}

