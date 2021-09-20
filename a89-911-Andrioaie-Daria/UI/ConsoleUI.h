//
// Created by daria on 20/03/2021.
//

#ifndef A45_911_ANDRIOAIE_DARIA_CONSOLEUI_H
#define A45_911_ANDRIOAIE_DARIA_CONSOLEUI_H

#include "AdminService.h"
#include "UserService.h"

class UserInterface {
private:
    AdminService& adminService;
    UserService& userService;

public:
//    //default constructor
//    UserInterface();

    // parameter constructor
    UserInterface(AdminService& admin_service, UserService& user_service);

    static void print_menu_of_admin();

    static void print_dog(const Dog& dog);

    static void print_all_dogs(const vector<Dog>& dog_array);

    void add_dog_admin();

    void delete_dog_admin();

    void update_dog_admin();

    void start_administrator_mode();

    static void print_menu_of_user();

    void print_adoption_list_user();

    void open_adoption_list();

    bool jump_to_next_dog_user();

    void adopt_dog_user();

    void print_current_dog();

    void start_user_mode();

    void start_program();

    ~UserInterface();

    void read_breed_of_dogs();

    void set_output_file();

    AdminService& get_admin_service();

    UserService& get_user_service();

    vector<Dog> get_all();
};


#endif //A45_911_ANDRIOAIE_DARIA_CONSOLEUI_H
