//
// Created by daria on 04/03/2021.
//

#include "Domain/offer.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

offer* create_offer(char type[], char destination[], date departure_date, int price){
    offer* holiday_offer = (offer*)malloc(sizeof(offer));

    strcpy(holiday_offer->type, type);
    strcpy(holiday_offer->destination, destination);
    holiday_offer->departure_date = departure_date;
    holiday_offer->price = price;

    return holiday_offer;
}


char* get_type(offer* holiday_offer){
    return holiday_offer->type;
}

char* get_destination(offer* holiday_offer){
    return holiday_offer->destination;
}

int get_price(offer* holiday_offer){
    return holiday_offer->price;
}

date get_departure_date(offer* holiday_offer){
    return holiday_offer->departure_date;
}

void to_string(offer* holiday_offer, char string[]){
    date departure_date = get_departure_date(holiday_offer);
    sprintf(string, "%s trip to %s starts on %d-%d-%d and costs %d.", get_type(holiday_offer),
            get_destination(holiday_offer), get_day(departure_date), get_month(departure_date),
            get_year(departure_date), get_price(holiday_offer));
}

int are_dates_equal(date date1, date date2){
    if(get_year(date1) != get_year(date2))
        return 0;

    if(get_month(date1) != get_month(date2))
        return 0;

    if(get_day(date1) != get_day(date2))
        return 0;

    return 1;
}

int is_date_before(date date1, date date2){
    int year1 = get_year(date1);
    int year2 = get_year(date2);

    int month1 = get_month(date1);
    int month2 = get_month(date2);

    int day1 = get_day(date1);
    int day2 = get_day(date2);


    if(year1 > year2)
        return 0;

    if(year1 < year2)
        return 1;

    if(month1 > month2)
        return 0;

    if(month1 < month2)
        return 1;

    if(day1 < day2)
        return 1;

    if(day1 > day2)
        return 0;

    return 0;
}


int get_year(date departure_date){
    return departure_date.year;
}

int get_month(date departure_date){
    return departure_date.month;
}

int get_day(date departure_date){
    return departure_date.day;
}


void set_price_of_offer(offer* holiday_offer, int new_price){
    holiday_offer->price = new_price;
}

void set_type_of_offer(offer* holiday_offer, char* new_type){
    strcpy(holiday_offer->type, new_type);
}