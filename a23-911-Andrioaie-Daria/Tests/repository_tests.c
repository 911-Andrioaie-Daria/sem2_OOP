//
// Created by daria on 14/03/2021.
//

#include "repository_tests.h"
#include "Repository/repository.h"
#include "assert.h"
#include "string.h"


void test_create_repository(){
    repo* offer_repository = create_offer_repository();
    assert(offer_repository != NULL);

    dynamic_array* current_list_of_offers = get_list_of_offers(offer_repository);
    assert(current_list_of_offers != NULL);

    offer** list_of_offers = get_data(offer_repository);
    assert(list_of_offers!= NULL);

    int* current_number_of_offers = get_offer_count(offer_repository);
    assert(*current_number_of_offers == 10);

    int *current_capacity = get_capacity(offer_repository);
    assert(*current_capacity == 20);

    history_array* history_of_offers = get_archive(offer_repository);
    assert(history_of_offers != NULL);

    int* length_of_archive = get_length_of_archive(offer_repository);
    assert(*length_of_archive == 1);

    int* index_of_current_list_in_history = get_index_of_current_list_in_archive(offer_repository);
    assert(*index_of_current_list_in_history == 0);

    deallocate_repository(offer_repository);
}

void test_add_offer_in_repository(){
    repo* offer_repository = create_offer_repository();
    date departure_date;
    departure_date.year = 2020;
    departure_date.month = 12;
    departure_date.day = 5;
    offer* new_offer = create_offer("mountain", "Annapurna", departure_date, 50);
    add_offer_to_repo(offer_repository, new_offer);

    int* current_number_of_offers = get_offer_count(offer_repository);
    assert(*current_number_of_offers == 11);

    int* index_of_current_list_in_history = get_index_of_current_list_in_archive(offer_repository);
    assert(*index_of_current_list_in_history == 1);

    int* length_of_archive = get_length_of_archive(offer_repository);
    assert(*length_of_archive == 2);

    deallocate_repository(offer_repository);
}

void test_delete_offer_from_repository(){
    repo* offer_repository = create_offer_repository();
    int position = 0;

    delete_offer_from_repo(offer_repository, position);
    int* current_number_of_offers = get_offer_count(offer_repository);
    assert(*current_number_of_offers == 9);

    deallocate_repository(offer_repository);
}

void test_update_offer_in_repository(){
    repo* offer_repository = create_offer_repository();
    int position = 0;
    int new_price = 200;
    update_price_of_offer_in_repo(offer_repository, position, new_price);
    offer** list_of_offers = get_data(offer_repository);
    assert(get_price(list_of_offers[position]) == 200);


    position = 1;
    char* new_type = "mountain";
    update_type_of_offer_in_repo(offer_repository, position, new_type);
    assert(strcmp(get_type(list_of_offers[position]), "mountain") == 0);

    deallocate_repository(offer_repository);
}

void test_add_current_list_to_history(){
    repo* offer_repository = create_offer_repository();
    add_current_list_to_history(offer_repository);
    int* length_of_archive = get_length_of_archive(offer_repository);
    assert(*length_of_archive == 2);

    int* index_of_current_list_in_history = get_index_of_current_list_in_archive(offer_repository);
    assert(*index_of_current_list_in_history == 1);

    deallocate_repository(offer_repository);
}

void test_resize_array(){
    repo* offer_repository = create_offer_repository();

    resize_repository(offer_repository, 100);
    int* current_number_of_offers = get_offer_count(offer_repository);
    assert(*current_number_of_offers == 10);

    int *current_capacity = get_capacity(offer_repository);
    assert(*current_capacity == 100);

    resize_repository(offer_repository, 5);
    assert(*current_number_of_offers == 5);
    assert(*current_capacity == 5);

    deallocate_repository(offer_repository);
}

void run_repository_tests() {
    test_create_repository();
    test_add_offer_in_repository();
    test_delete_offer_from_repository();
    test_update_offer_in_repository();
    test_add_current_list_to_history();
    test_resize_array();
}