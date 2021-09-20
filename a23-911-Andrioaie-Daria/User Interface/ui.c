//
// Created by daria on 05/03/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ui.h"

void print_menu(){
    printf("Available options: \n");
    printf("    1. Add offer.\n");
    printf("    2. Delete offer.\n");
    printf("    3. Update offer.\n");
    printf("    4. Search offers by destination.\n");
    printf("    5. Search offers by type, after a given date.\n");
    printf("    6. Undo.\n");
    printf("    7. Redo.\n");
    printf("    8. Print all.\n");
    printf("    9. Exit.\n");
}

UI* create_ui(service *offer_service){
    UI *user_interface = (UI*)malloc(sizeof(UI));
    user_interface->offer_service = offer_service;
    return user_interface;
}

service* get_service(UI *user_interface){
    return user_interface->offer_service;
}


void print_all(UI *user_interface){

    service* offer_service = get_service(user_interface);
    int* offer_count = get_offer_count_from_service(offer_service);
    offer** offer_data = get_data_from_service(offer_service);

    for(int i=0;i<*offer_count;i++){
        char string[100];
        to_string(offer_data[i], string);
        printf("%s", string);
        printf("\n");
    }
}

void add_offer_ui(UI *user_interface){
    char type[11];
    printf("Type:");

    //fgets (type, 11, stdin);
    //scanf("%[^\n]s", type);
    scanf("%s", type);

    char destination[50];
    printf("Destination:");
    scanf("%s", destination);

    int departure_year;
    printf("Year:");
    scanf("%d", &departure_year);

    int departure_month;
    printf("Month:");
    scanf("%d", &departure_month);

    int departure_day;
    printf("Day:");
    scanf("%d", &departure_day);

    int price;
    printf("Price:");
    scanf("%d", &price);

    add_offer_to_service(user_interface->offer_service, type, destination, departure_year, departure_month, departure_day, price);
    printf("Offer was added successfully.\n");

}

void delete_offer_ui(UI *user_interface){
    char destination[50];
    printf("Destination:");
    scanf("%s", destination);

    int departure_year;
    printf("Year:");
    scanf("%d", &departure_year);

    int departure_month;
    printf("Month:");
    scanf("%d", &departure_month);

    int departure_day;
    printf("Day:");
    scanf("%d", &departure_day);

    bool result = delete_offer_from_service(user_interface->offer_service, destination, departure_year, departure_month, departure_day);
    if(result)
        printf("Offer was deleted successfully.\n");
    else
        printf("There is no such offer.\n");

}

void update_offer_ui(UI *user_interface){
    printf("Identify the offer:\n");
    char destination[50];
    printf("Destination:");
    scanf("%s", destination);

    int departure_year;
    printf("Year:");
    scanf("%d", &departure_year);

    int departure_month;
    printf("Month:");
    scanf("%d", &departure_month);

    int departure_day;
    printf("Day:");
    scanf("%d", &departure_day);


    printf("What do you want to change:\n");
    printf("\ta. Type\n");
    printf("\tb. Price\n");

    char user_option;
    scanf(" %c", &user_option);
    bool operation_result;

    if(user_option == 'a')
    {
        char new_type[11];
        printf("Type:");

        scanf("%s", new_type);
        operation_result = update_type_of_offer(user_interface->offer_service, destination, departure_year, departure_month, departure_day, new_type);
        if(operation_result)
            printf("The offer was updated successfully.\n");
        else
            printf("The given offer does not exist.\n");
    }

    else{
        if(user_option == 'b'){
            int new_price;
            printf("Price: ");
            scanf("%d", &new_price);
            operation_result = update_price_of_offer(user_interface->offer_service, destination, departure_year, departure_month, departure_day, new_price);
            if(operation_result)
                printf("The offer was updated successfully.\n");
            else
                printf("The given offer does not exist.\n");
        }
        else
            printf("Invalid option.\n");
    }

}

void search_by_destination_ui(UI *user_interface) {
    char string[20];
    char empty[20];

    printf("Enter string:");
    gets_s(empty, sizeof(empty));
    fgets(string, sizeof(string), stdin);

    printf("Show the results sorted ascending by:\n");
    printf("\t0. departure date\n");
    printf("\t1. price\n");
    printf("\t2. destination\n");

    int sorting_option;
    scanf("%d", &sorting_option);

    if (sorting_option == 0 || sorting_option == 1 || sorting_option == 2) {

        dynamic_array *resulted_offers = search_by_destination_service(user_interface->offer_service, string, sorting_option);

        if (resulted_offers->length > 0) {
            for (int i = 0; i < resulted_offers->length; i++) {
                char buffer_string[100];
                to_string(resulted_offers->data[i], buffer_string);
                printf("%s", buffer_string);
                printf("%s", "\n");
            }
        } else
            printf("None of the offers match the given string.\n");

        deallocate_dynamic_array(resulted_offers);
    }
    else
        printf("Invalid command.\n");
}


void search_by_type_ui(UI *user_interface){
    int type_option;
    printf("Search by type:\n");
    printf("\t0. city break\n");
    printf("\t1. seaside\n");
    printf("\t2. mountain\n");
    scanf("%d", &type_option);
    if(type_option == 0 || type_option == 1 || type_option == 2){

        // read the departure date
        int departure_year;
        printf("Year:");
        scanf("%d", &departure_year);

        int departure_month;
        printf("Month:");
        scanf("%d", &departure_month);

        int departure_day;
        printf("Day:");
        scanf("%d", &departure_day);

        dynamic_array* resulted_offers = search_by_type_after_date_service(user_interface->offer_service, type_option,
                                                                   departure_year, departure_month, departure_day);
        if(resulted_offers->length > 0)
            for(int i=0; i<resulted_offers->length; i++){
                char buffer_string[100];
                to_string(resulted_offers->data[i], buffer_string);
                printf("%s", buffer_string);
                printf("%s", "\n");
            }
        else
            printf("No offers match the given filters.\n");
        deallocate_dynamic_array(resulted_offers);
    }
    else
        printf("Invalid command.\n");

}

void undo_ui(UI *user_interface){
    bool result = undo_service(user_interface->offer_service);
    if(result==true){
        printf("Undone.\n");
    }
    else
        printf("No more undos available.\n");
}

void redo_ui(UI *user_interface){
    bool result = redo_service(user_interface->offer_service);
    if(result==true){
        printf("Redone.\n");
    }
    else
        printf("No more redos available.\n");
}


void start_program(UI *user_interface) {
    print_menu();

    bool finished = false;
    int user_option = 0;
    while (!finished) {
        //finished = true;
        printf("Enter option:");
        scanf("%d", &user_option);
        switch (user_option) {
            case 1: {
                add_offer_ui(user_interface);
                break;
            }
            case 2: {
                delete_offer_ui(user_interface);
                break;
            }

            case 3: {
                update_offer_ui(user_interface);
                break;
            }

            case 4: {
                search_by_destination_ui(user_interface);
                break;
            }

            case 5: {
                search_by_type_ui(user_interface);
                break;
            }

            case 6: {
                undo_ui(user_interface);
                break;
            }

            case 7: {
                redo_ui(user_interface);
                break;
            }

            case 8: {
                print_all(user_interface);
                break;
            }

            case 9: {
                printf("Bye!\n");
                finished = true;
                break;
            }

            default: {
                printf("Invalid command!\n");
                break;
            }
        }
    }

}

void deallocate_user_interface(UI *user_interface){
    deallocate_service(user_interface->offer_service);
    free(user_interface);
}