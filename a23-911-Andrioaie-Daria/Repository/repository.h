//
// Created by daria on 04/03/2021.
//

#ifndef A23_911_ANDRIOAIE_DARIA_REPOSITORY_H
#define A23_911_ANDRIOAIE_DARIA_REPOSITORY_H

#endif //A23_911_ANDRIOAIE_DARIA_REPOSITORY_H

#include "Dynamic array/dynamic_array.h"

/// The structure holds:
/// all the previous lists of offers
/// the length of this collection
/// the index of the current list inside the history.
typedef struct{
    dynamic_array** past_lists;
    int index_of_current_list;
    int length_of_history;
}history_array;


typedef struct {
    dynamic_array* list_of_offers;
    history_array history_of_states;
}repo;

/// the function initialises an instance of the repo struct with 10 offer objects inside the current list.
/// params: none.
/// return: a pointer to the created repository.
repo* create_offer_repository();

/// Getter function for the current list of offers inside a repository.
/// param: a pointer to an offer repo.
/// return: an array of pointers to offer instances, containing the current offers.
offer** get_data(repo* offer_repository);

/// Getter function for the length of the current list of offers inside a repository.
/// param: a pointer to an offer repo.
/// return: a pointer to an integer representing the current length of the list of offers.
int* get_offer_count(repo* offer_repository);

/// Getter function for the capacity of the current list of offers inside a repository.
/// param: a pointer to an offer repo.
/// return: a pointer to an integer representing the current capacity of the list of offers.
int* get_capacity(repo* offer_repository);

/// Getter function for the dynamic array which holds the current list of offers inside a repository.
/// param: a pointer to an offer repo.
/// return: a pointer to a dynamic array holding the current list of offers.
dynamic_array* get_list_of_offers(repo* offer_repository);

/// Getter function for the history array which holds all the previous lists of offers inside a repository.
/// param: a pointer to an offer repo.
/// return: a pointer to a history array holding the all the previous lists of offers.
history_array* get_archive(repo* offer_repository);

/// Getter function for the length of the history array which holds all the previous lists of offers inside a repository.
/// param: a pointer to an offer repo.
/// return: a pointer to an integer representing the number of lists in the history.
int* get_length_of_archive(repo* offer_repository);

/// Getter function for the index of the current list of offers inside the history array.
/// param: a pointer to an offer repo.
/// return: a pointer to an integer representing the number of lists in the history.
int* get_index_of_current_list_in_archive(repo* offer_repository);

/// The function adds a new offer to the current list of offers.
/// params: a pointer to an offer repo, a pointer to an instance of the Offer struct.
void add_offer_to_repo(repo* offer_repository, offer* new_offer);

/// The function deletes the offer at the given position from the current list of offers.
/// params: a pointer to an offer repo, the position inside the current list of the Offer that is to be deleted.
void delete_offer_from_repo(repo* offer_repository, int position);

/// The function updates the type of the offer at the given position inside the current list of offers.
/// params: a pointer to an offer repo, the position inside the current list of the Offer that is to be updated,
/// a char pointer to the new_type of the offer.
void update_type_of_offer_in_repo(repo* offer_repository, int position, char* new_type);

/// The function updates the price of the offer at the given position inside the current list of offers.
/// params: a pointer to an offer repo, the position inside the current list of the Offer that is to be updated,
/// an integer value representing the new price of the offer.
void update_price_of_offer_in_repo(repo* offer_repository, int position, int new_price);

/// The function adds the current list of offers to the history.
/// \param offer_repository: a pointer to an offer repo.
void add_current_list_to_history(repo* offer_repository);

/// The function resizes to current list of offers inside the repository to the given capacity
/// \param offer_repository: a pointer to an offer repo.
/// \param new_capacity: an integer representing the new maximum capacity of a dynamic array.
void resize_repository(repo* offer_repository, int new_capacity);

/// The function frees up all the memory allocated inside the repository.
/// \param offer_repository: a pointer to an offer repo.
void deallocate_repository(repo* offer_repository);

/// The function frees up the memory allocated for a dynamic array.
/// \param offer_array a pointer to a dynamic array.
void deallocate_dynamic_array(dynamic_array* offer_array);