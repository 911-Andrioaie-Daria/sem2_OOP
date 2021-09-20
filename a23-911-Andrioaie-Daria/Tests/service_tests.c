//
// Created by daria on 14/03/2021.
//

#include "service_tests.h"
#include "Controller/controller.h"
#include <assert.h>

void test_create_offer_service(){
    repo* offer_repository = create_offer_repository();
    service* offer_service = create_offer_service(offer_repository);
    assert(offer_service != NULL);

    int* offer_count =get_offer_count_from_service(offer_service);
    assert(*offer_count == 10);

    deallocate_service(offer_service);
}

void test_add_offer(){
    repo* offer_repository = create_offer_repository();
    service* offer_service = create_offer_service(offer_repository);

    char* type = "mountain";
    char* destination = "Bucegi";
    int departure_year = 2021;
    int departure_month = 11;
    int departure_day = 5;
    int price = 1000;

    add_offer_to_service(offer_service, type, destination, departure_year, departure_month, departure_day, price);
    int* offer_count =get_offer_count_from_service(offer_service);
    assert(*offer_count == 11);

    deallocate_service(offer_service);
}

void test_delete_offer(){
    repo* offer_repository = create_offer_repository();
    service* offer_service = create_offer_service(offer_repository);

    char* destination = "Wien";
    int departure_year = 2022;
    int departure_month = 3;
    int departure_day = 24;
    bool deletion_result = delete_offer_from_service(offer_service, destination, departure_year, departure_month, departure_day);
    assert(deletion_result == true);

    int* offer_count =get_offer_count_from_service(offer_service);
    assert(*offer_count == 9);

    destination = "Hawaii";
    departure_year = 2022;
    departure_month = 3;
    departure_day = 24;
    deletion_result = delete_offer_from_service(offer_service, destination, departure_year, departure_month, departure_day);
    assert(deletion_result == false);

    deallocate_service(offer_service);
}

void test_update_offer(){
    repo* offer_repository = create_offer_repository();
    service* offer_service = create_offer_service(offer_repository);
    char* destination = "Wien";
    int departure_year = 2022;
    int departure_month = 3;
    int departure_day = 24;
    int new_price = 1000;
    bool update_result = update_price_of_offer(offer_service, destination, departure_year, departure_month, departure_day, new_price);
    assert(update_result == true);

    destination = "Hawaii";
    departure_year = 2022;
    departure_month = 3;
    departure_day = 24;
    char* new_type = "lalala";
    update_result = update_type_of_offer(offer_service, destination, departure_year, departure_month, departure_day, new_type);
    assert(update_result == false);

    deallocate_service(offer_service);
}

void test_search_offer(){
    repo* offer_repository = create_offer_repository();
    service* offer_service = create_offer_service(offer_repository);
    char* destination = "Wien";
    date departure_date;
    departure_date.year = 2022;
    departure_date.month = 3;
    departure_date.day = 24;
    int search_result = search_for_offer(offer_service, destination, departure_date);
    assert(search_result != -1);

    destination = "Hawaii";
    search_result = search_for_offer(offer_service, destination, departure_date);
    assert(search_result == -1);
    deallocate_service(offer_service);
}

void test_search_by_destination(){
    repo* offer_repository = create_offer_repository();
    service* offer_service = create_offer_service(offer_repository);

    char* search_string = "on";
    char sorting_option = 'a';
    dynamic_array* resulted_offers = search_by_destination_service(offer_service, search_string, sorting_option);
    assert(resulted_offers->length == 3);
    deallocate_dynamic_array(resulted_offers);

    search_string = "\n";
    sorting_option = 'b';
    resulted_offers = search_by_destination_service(offer_service, search_string, sorting_option);
    assert(resulted_offers->length == 10);

    deallocate_dynamic_array(resulted_offers);
    deallocate_service(offer_service);
}

void test_search_by_type(){
    repo* offer_repository = create_offer_repository();
    service* offer_service = create_offer_service(offer_repository);
    int type = 0;
    int departure_year = 2020;
    int departure_month = 11;
    int departure_day = 5;

    dynamic_array* resulted_offers = search_by_type_after_date_service(offer_service, type, departure_year, departure_month, departure_day);
    assert(resulted_offers->length == 4);
    deallocate_dynamic_array(resulted_offers);


    type = 1;
    departure_year = 2025;
    departure_month = 11;
    departure_day = 5;

    resulted_offers = search_by_type_after_date_service(offer_service, type, departure_year, departure_month, departure_day);
    assert(resulted_offers->length == 0);
    deallocate_dynamic_array(resulted_offers);


    type = 2;
    departure_year = 2020;
    departure_month = 11;
    departure_day = 5;

    resulted_offers = search_by_type_after_date_service(offer_service, type, departure_year, departure_month, departure_day);
    assert(resulted_offers->length == 3);

    deallocate_dynamic_array(resulted_offers);
    deallocate_service(offer_service);
}

void test_sort(){
    repo* offer_repository = create_offer_repository();
    service* offer_service = create_offer_service(offer_repository);

    dynamic_array* current_list = get_list_of_offers_from_service(offer_service);
    sort_ascending_by_price(current_list);
    assert(current_list->data[0]->price < current_list->data[1]->price);

    sort_ascending_by_departure_date(current_list);
    assert(is_date_before(current_list->data[0]->departure_date, current_list->data[1]->departure_date));

    deallocate_service(offer_service);
}

void test_undo_redo(){
    repo* offer_repository = create_offer_repository();
    service* offer_service = create_offer_service(offer_repository);

    char* type = "mountain";
    char* destination = "Bucegi";
    int departure_year = 2021;
    int departure_month = 11;
    int departure_day = 5;
    int price = 1000;

    add_offer_to_service(offer_service, type, destination, departure_year, departure_month, departure_day, price);
    int* offer_count =get_offer_count_from_service(offer_service);
    assert(*offer_count == 11);

    undo_service(offer_service);
    assert(*offer_count == 10);

    redo_service(offer_service);
    assert(*offer_count == 11);

    deallocate_service(offer_service);
}

void run_service_tests(){
    test_create_offer_service();
    test_add_offer();
    test_delete_offer();
    test_update_offer();
    test_search_offer();
    test_search_by_destination();
    test_search_by_type();
    test_sort();
    test_undo_redo();
}
