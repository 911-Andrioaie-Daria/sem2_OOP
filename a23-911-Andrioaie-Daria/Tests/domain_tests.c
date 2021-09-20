//
// Created by daria on 14/03/2021.
//

#include "domain_tests.h"
#include "Domain/offer.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>

void test_create_offer(){
    date departure_date;
    departure_date.year = 2020;
    departure_date.month = 12;
    departure_date.day = 5;
    offer* new_offer = create_offer("mountain", "Annapurna", departure_date, 50);
    assert(new_offer != NULL);
    free(new_offer);
}
void test_getters_of_offer(){
    date departure_date;
    departure_date.year = 2020;
    departure_date.month = 12;
    departure_date.day = 5;
    offer* new_offer = create_offer("mountain", "Annapurna", departure_date, 50);

    char *type_of_offer = get_type(new_offer);
    assert(strcmp(type_of_offer, "mountain")==0);

    char* destination = get_destination(new_offer);
    assert(strcmp(destination, "Annapurna")==0);

    int price = get_price(new_offer);
    assert(price == 50);

    date departure_date_of_offer = get_departure_date(new_offer);
    assert(are_dates_equal(departure_date_of_offer, departure_date)==1);

    int year_of_departure = get_year(departure_date);
    assert(year_of_departure == 2020);

    int month_of_departure = get_month(departure_date);
    assert(month_of_departure == 12);

    int day_of_departure = get_day(departure_date);
    assert(day_of_departure == 5);

    date date2;
    date2.year = 2022;
    date2.month = 10;
    date2.day = 4;
    assert(is_date_before(departure_date_of_offer, date2)==1);

    free(new_offer);
}

void test_setters(){
    date departure_date;
    departure_date.year = 2020;
    departure_date.month = 12;
    departure_date.day = 5;
    offer* new_offer = create_offer("mountain", "Annapurna", departure_date, 50);

    set_price_of_offer(new_offer, 1000);
    int new_price = get_price(new_offer);
    assert(new_price == 1000);

    set_type_of_offer(new_offer, "seaside");
    char* new_type = get_type(new_offer);
    assert(strcmp(new_type, "seaside")==0);

    free(new_offer);
}

void run_domain_tests(){
    test_create_offer();
    test_getters_of_offer();
    test_setters();
}

