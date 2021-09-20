//
// Created by daria on 04/03/2021.
//

#ifndef A23_911_ANDRIOAIE_DARIA_UI_H
#define A23_911_ANDRIOAIE_DARIA_UI_H

#endif //A23_911_ANDRIOAIE_DARIA_UI_H
#include "Controller/controller.h"

typedef struct
{
    service *offer_service;
}UI;

UI* create_ui(service *offer_service);

void add_offer_ui(UI *user_interface);

void delete_offer_ui(UI *user_interface);

void update_offer_ui(UI *user_interface);

void search_by_destination_ui(UI *user_interface);

void search_by_type_ui(UI *user_interface);

void undo_ui(UI *user_interface);

void redo_ui(UI *user_interface);

void print_menu();

void start_program(UI *user_interface);

service* get_service(UI *user_interface);

void deallocate_user_interface(UI *user_interface);