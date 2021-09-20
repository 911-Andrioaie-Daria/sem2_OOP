//
// Created by daria on 04/03/2021.
//

#ifndef A23_911_ANDRIOAIE_DARIA_CONTROLLER_H
#define A23_911_ANDRIOAIE_DARIA_CONTROLLER_H

#endif //A23_911_ANDRIOAIE_DARIA_CONTROLLER_H
#include "Repository/repository.h"
#include <stdbool.h>

typedef struct {
    repo *offer_repository;
} service;

/// The function initialises an instance of the service struct.
/// param offer_repository: pointer to an already existing repository.
/// return: a pointer to the new Service instance.
service* create_offer_service(repo *offer_repository);

/// Getter function for the repository inside the service
/// \param offer_service: pointer to the offer service
/// \return a pointer to the corresponding repository.
repo* get_repository(service* offer_service);

/// The function creates a new instance of the Offer struct with the given attributes and
/// passes it to the repository to perform the actual addition.
/// \param offer_service: pointer to the offer service
/// \param type: the type of the new offer
/// \param destination: the destination of the offer
/// \param departure_year: integer value representing the year of the departure.
/// \param departure_month: integer value representing the month of the departure.
/// \param departure_day: integer value representing the day of the departure.
/// \param price: integer value representing the price of the offer.
void add_offer_to_service(service *offer_service, char *type, char *destination, int departure_year, int departure_month, int departure_day, int price);

/// The function searches for the position of the offer identified by the given destination and departure date and
/// passes this position to the repository in order to perform the actual deletion.
/// \param offer_service: pointer to the offer service
/// \param destination: the destination of the offer
/// \param departure_year: integer value representing the year of the departure.
/// \param departure_month: integer value representing the month of the departure.
/// \param departure_day: integer value representing the day of the departure.
/// \return: true, if the deletion was performed successfully, false, if the offer could not be found
bool delete_offer_from_service(service *offer_service, char *destination, int departure_year, int departure_month, int departure_day);

/// The function searches for the position of the offer identified by the given destination and departure date and
///// passes this position to the repository in order to update its type.
/// \param offer_service: pointer to the offer service
/// \param destination: the destination of the offer
/// \param departure_year: integer value representing the year of the departure.
/// \param departure_month: integer value representing the month of the departure.
/// \param departure_day: integer value representing the day of the departure.
/// \param new_type: string containing the new type of the offer
/// \return: true, if the given offer was found in the current list and the update was completed, false, otherwise
bool update_type_of_offer(service *offer_service, char destination[], int departure_year, int departure_month, int departure_day, char new_type[]);

/// The function searches for the position of the offer identified by the given destination and departure date and
///// passes this position to the repository in order to update its price.
/// \param offer_service: pointer to the offer service
/// \param destination: the destination of the offer
/// \param departure_year: integer value representing the year of the departure.
/// \param departure_month: integer value representing the month of the departure.
/// \param departure_day: integer value representing the day of the departure.
/// \param new_price: integer value representing the new price of the offer.
/// \return: true, if the given offer was found in the current list and the update was completed, false, otherwise
bool update_price_of_offer(service *offer_service, char destination[], int departure_year, int departure_month, int departure_day, int new_price);

/// The function parses the current list of offers and searches for the offer identified by the given destination and departure date.
/// \param offer_service: pointer to the offer service
/// \param destination: the destination of the offer
/// \param departure_date: the date of the departure.
/// \return: the position of the offer inside the current list of offers or -1, if the offer was not found.
int search_for_offer(service *offer_service, char* destination, date departure_date);

/// The function searches for all the offers in the current list whose destinations contain a given string.
/// If the string is empty, all destinations are considered.
/// \param offer_service: pointer to the offer service
/// \param string: the string that the destinations of the offers must match.
/// \param sorting_option: 'a', if the resulted offers must be sorted ascending by departure date,
/// 'b', if the resulted offers must be sorted ascending by price.
/// \return: a pointer to a dynamic array containing the results of the search.
dynamic_array* search_by_destination_service(service *offer_service, char* string, int sorting_option);

/// The function filters the current list of offers by their type, having the departure after the given date.
/// \param offer_service: pointer to the offer service
/// \param type_option: 'a', filters the city break offers, 'b' filters the seaside offers, 'c' filters the mountain offers.
/// \param departure_year: integer value representing the year of the date.
/// \param departure_month: integer value representing the month of the date.
/// \param departure_day: integer value representing the day of the date.
/// \return: a pointer to a dynamic array containing the results of the filtering.
dynamic_array* search_by_type_after_date_service(service *offer_service, int type_option, int departure_year, int departure_month, int departure_day);

dynamic_array* filter_offers_with_given_property(service *offer_service, bool (*property)(offer*), date departure_date);

/// The function filters all the city break offers in the current list of offers, having the departure after the given date.
/// \param offer_service: pointer to the offer service
/// \param departure_date: the date after which the departure dates of the resulted offer must be.
/// \return: a pointer to a dynamic array containing the results of the filtering.
dynamic_array* search_city_break_offers(service *offer_service, date departure_date);

/// The function filters all the seaside offers in the current list of offers, having the departure after the given date.
/// \param offer_service: pointer to the offer service
/// \param departure_date: the date after which the departure dates of the resulted offer must be.
/// \return: a pointer to a dynamic array containing the results of the filtering.
dynamic_array* search_seaside_offers(service *offer_service, date departure_date);

/// The function filters all the mountain offers in the current list of offers, having the departure after the given date.
/// \param offer_service: pointer to the offer service
/// \param departure_date: the date after which the departure dates of the resulted offer must be.
/// \return: a pointer to a dynamic array containing the results of the filtering.
dynamic_array* search_mountain_offers(service *offer_service, date departure_date);

/// The function sorts the list of offers inside a given array ascending by their price.
/// \param offer_data: pointer to a dynamic array containing a list of offers.
void sort_ascending_by_price(dynamic_array * offer_data);

/// The function sorts the list of offers inside a given array ascending by their departure date.
/// \param offer_data: pointer to a dynamic array containing a list of offers.
void sort_ascending_by_departure_date(dynamic_array * offer_data);

void sort_ascending(dynamic_array* offer_data, bool (*compare)(offer*,offer*));

/// Getter function for the count of offers in the current list of offers.
/// \param offer_service: pointer to the offer service.
/// \return: pointer to an integer representing the offer count.
int* get_offer_count_from_service(service *offer_service);

/// Getter function for the array containing the current list of offers.
/// \param offer_service: pointer to the offer service.
/// \return: an array of pointers to the current offers.
offer** get_data_from_service(service *offer_service);

/// Getter function for the array which holds the current list of offers, together with its length and maximum capacity.
/// \param offer_service: pointer to the offer service.
/// \return: a dynamic array instance containing the current list of offers, together with its length and maximum capacity.
dynamic_array* get_list_of_offers_from_service(service *offer_service);

/// Getter function for the history which holds all previous states of the list of offers.
/// \param offer_service: pointer to the offer service
/// \return: pointer to the history array.
history_array* get_history(service *offer_service);

/// The function undoes the previous operation performed by the user on the current list of offers.
/// \param offer_service: pointer to the offer service
/// \return: true, if the undone was successful, false, if there were no available undos at the moment.
bool undo_service(service *offer_service);

/// The function redoes the previous operation performed by the user on the current list of offers.
/// \param offer_service: pointer to the offer service
/// \return: true, if the redone was successful, false, if there were no available redos at the moment.
bool redo_service(service *offer_service);

/// The function frees up all the memory allocated inside the service.
/// \param offer_repository: a pointer to an offer service.
void deallocate_service(service *offer_service);
