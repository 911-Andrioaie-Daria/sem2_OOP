//
// Created by daria on 04/03/2021.
// Module contains the Offer structure and all operations that are needed.

#ifndef A23_911_ANDRIOAIE_DARIA_OFFER_H
#define A23_911_ANDRIOAIE_DARIA_OFFER_H

#endif //A23_911_ANDRIOAIE_DARIA_OFFER_H

typedef struct {
    int year;
    int month;
    int day;
} date;

typedef struct {
    char type[11];
    char destination[21];
    date departure_date;
    int price;
} offer;

/// the function initialises an offer with the given attributes.
/// params: the attributes of the structure offer.
/// return: a pointer to the created offer.
offer* create_offer(char type[], char destination[], date departure_date, int price);

/// Getter function for the type of an offer
/// param: a pointer to a holiday offer
/// return: a pointer to a char containing the type
char* get_type(offer* holiday_offer);

/// Getter function for the destination of an offer
/// param: a pointer to a holiday offer
/// return: a pointer to a char containing the destination
char* get_destination(offer* holiday_offer);

/// Getter function for the price of an offer
/// param: a pointer to a holiday offer
/// return: an integer value representing the type
int get_price(offer* holiday_offer);

/// Getter function for the departure date of an offer
/// param: a pointer to a holiday offer
/// return: a date struct representing the departure date
date get_departure_date(offer* holiday_offer);

///Function will copy in param char string[] a string containing
/// all attributes of an offer in readable form.
void to_string(offer* holiday_offer, char string[]);

/// Getter function for the year of a date
/// param: a date struct
/// return: an integer value representing the year
int get_year(date departure_date);

/// Getter function for the month of a date
/// param: a date struct
/// return: an integer value representing the month
int get_month(date departure_date);

/// Getter function for the day of a date
/// param: a date struct
/// return: an integer value representing the day
int get_day(date departure_date);

/// Function that checks if two date structs are equal
/// param: two date structures
/// return: 1, if the dates are equal, 0, if they are not
int are_dates_equal(date date1, date date2);

/// Function that checks if a date if before another one
/// param: two date structures
/// return: 1, if date1 is before date2, 0, otherwise
int is_date_before(date date1, date date2);

/// Setter function for the price of an offer.
/// param: a pointer to a holiday offer, an integer representing the new
/// value of the price
/// return: nothing, it just modifies the price
void set_price_of_offer(offer* holiday_offer, int new_price);

/// Setter function for the type of an offer.
/// param: a pointer to a holiday offer, a pointer to a char containing
/// the new type
/// return: nothing, it just modifies the type
void set_type_of_offer(offer* holiday_offer, char* new_type);
