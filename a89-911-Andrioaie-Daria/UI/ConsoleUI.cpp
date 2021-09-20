//
// Created by daria on 20/03/2021.
//

#include "ConsoleUI.h"
#include <iostream>

////default constructor
//UserInterface::UserInterface()= default;

// parameter constructor
UserInterface::UserInterface(AdminService& admin_service, UserService& user_service): adminService{admin_service}, userService{user_service}{
//    this->adminService = admin_service;
//    this->userService = user_service;
}

AdminService& UserInterface::get_admin_service(){
    return this->adminService;
}

UserService& UserInterface::get_user_service() {
    return this->userService;
}

vector<Dog> UserInterface::get_all(){
    return this->adminService.get_dog_array();
}

void UserInterface::print_menu_of_admin(){
    cout<<"You are in administrator mode."<<endl;
    cout<<endl;
    cout<<"1. Print all dogs."<<endl;
    cout<<"2. Add a dog."<<endl;
    cout<<"3. Delete a dog."<<endl;
    cout<<"4. Update dog."<<endl;
    cout<<"0. Exit."<<endl;
    cout<<endl;
}

void UserInterface::print_menu_of_user(){
    cout<<"1. Adopt."<<endl;
    cout<<"2. Next dog."<<endl;
    cout<<"3. See your adopted dogs."<<endl;
    cout<<"4. See another breed."<<endl;
    cout<<"5. See adoption list in application."<<endl;
    cout<<"0. Exit"<<endl<<endl;
    cout<<"Option:";
}

void UserInterface::print_dog(const Dog& dog){
    cout<<dog.to_string()<<endl;
}


void UserInterface::print_all_dogs(const vector<Dog>& dog_array){

    for(auto & index : dog_array){
        print_dog(index);
    }
    cout<<endl;
}

void UserInterface::add_dog_admin(){
    AdminService admin_service = get_admin_service();
    string breed, name, photograph, age;
    cout<<"Breed:";
    cin>>breed;
    cout<<"Name:";
    cin>>name;
    cout<<"Age:";
    cin>>age;
    cout<<"Photo:";
    cin>>photograph;
    try{
        admin_service.add_dog(breed, age, name, photograph);
        cout<<name<<" is now in the shelter."<<endl;
    }
    catch(const CustomException& operation_exception){
        cout<<operation_exception.what()<<"\n";
    }
}

void UserInterface::delete_dog_admin(){
    AdminService admin_service = get_admin_service();
    string breed, name;
    cout<<"Breed:";
    cin>>breed;
    cout<<"Name:";
    cin>>name;

    try {
        admin_service.delete_dog(breed, name);
        cout << "Yey! " << name << " is not in the shelter anymore." << endl;
    }
    catch(const CustomException& operation_exception){
        cout<<operation_exception.what()<<"\n";
    }
    cout<<endl;
}

void UserInterface::update_dog_admin(){
    char option;
    AdminService admin_service = get_admin_service();
    string breed, name;

    cout<<"Identify the dog:"<<endl;
    cout<<"Breed:";
    cin>>breed;
    cout<<"Name:";
    cin>>name;

    cout<<"What do you want to update?"<<endl;
    cout<<"\ta. age"<<endl;
    cout<<"\tb. photograph"<<endl;
    cin>>option;

    try{
        if(option == 'a'){
            string new_age;
            cout<<"New age:";
            cin>>new_age;
            admin_service.update_dog_age(breed, name, new_age);
            cout<<name<<"'s age was updated."<<endl;
        }
        else{
            if(option == 'b'){
                string new_photograph;
                cout<<"New photo:";
                cin>>new_photograph;
                admin_service.update_dog_photograph(breed, name, new_photograph);
                cout<<name<<"'s photograph was updated. He's gorgeous."<<endl;

            }
            else cout<<"Invalid command."<<endl;
        }
    }
    catch(const CustomException& operation_exception){
        cout<<operation_exception.what()<<"\n";
    }

    cout<<endl;
}

void UserInterface::start_administrator_mode(){
    char option;
    while(true){
        this->print_menu_of_admin();
        cout<<"Your option:";
        cin>>option;
        switch (option) {
            case '0': {
                cout<<endl<<"See you!";
//                finished = true;
//                break;
                exit(0);
            }
            case '1': {
                vector<Dog> dog_array = this->get_all();
                this->print_all_dogs(dog_array);
                break;
            }
            case '2': {
                this->add_dog_admin();
                break;
            }
            case '3': {
                this->delete_dog_admin();
                break;
            }
            case '4': {
                this->update_dog_admin();
                break;
            }
            default: {
                cout<<endl<<"Invalid admin command!"<<endl;
                break;
            }
        }
    }

}

void UserInterface::print_adoption_list_user(){
    UserService& user_service = this->get_user_service();
    vector<Dog> adopted_dogs = user_service.get_adopted_dogs();
    if(!adopted_dogs.empty()){
        cout<<"ADOPTED BY YOU:"<<endl<<endl;
        print_all_dogs(adopted_dogs);
    }
    else
        cout<<"You did not adopt any dogs yet, but it's not too late."<<endl<<endl;

}

bool UserInterface::jump_to_next_dog_user(){
    UserService& user_service = this->get_user_service();
    int dog_index = user_service.get_dog_index();
    vector<Dog> dogs_of_breed = user_service.get_dogs_filtered();

    /// we still have dogs of breed to show to the user
    if(dog_index < dogs_of_breed.size() - 1)
        user_service.increment_dog_index();

    /// the list of dogs has reached the end
    else{
        string current_breed = (dogs_of_breed)[0].get_dog_breed();

        /// loop back at the beginning of the list of the given breed
        user_service.filter_dogs_by_breed(current_breed);
        dogs_of_breed = user_service.get_dogs_filtered();

        /// if there are no other dogs in the breed, given the user the option to see another breed
        if(dogs_of_breed.empty() && user_service.get_repository().get_size() != 0) {
            cout << "Congrats!!! You adopted all the dogs from the breed " + current_breed << endl;
            this->read_breed_of_dogs();
        }
        else
            /// if the user adopted all the dogs in the shelter, a message is displayed and the program stops.
            if(dogs_of_breed.empty() && user_service.get_repository().get_size() == 0){
                cout<< "You adopted all of our dogs! You're a wonderful person!"<<endl;
                return false;
            }
    }
    return true;
}

void UserInterface::adopt_dog_user(){
    UserService& user_service = this->get_user_service();

    user_service.adopt_dog(user_service.get_current_dog());
    cout<<"Adopted."<<endl;
}

void UserInterface::open_adoption_list() {
    UserService& user_service = this->get_user_service();
    user_service.open_adoption_list();
}


void UserInterface::set_output_file() {
    UserService& user_service = this->get_user_service();
    char option;
    bool valid = false;
    cout<<"Choose your output file:"<<endl;
    cout<<"1. CSV"<<endl;
    cout<<"2. HTML"<<endl;

    while(!valid){
        cout<<"Your option:";
        cin>>option;
        switch (option) {
            case '1':{
                user_service.setCSVFile();
                valid = true;
                break;
            }
            case '2':{
                user_service.setHTMLFile();
                valid = true;
                break;
            }
            default:{
                cout<<"Invalid option."<<endl;
                break;
            }
        }
    }
}

void UserInterface::read_breed_of_dogs(){
    UserService& user_service = this->get_user_service();
    vector<Dog> dogs_of_breed;

    bool valid_breed = false;
    do{
        cout<<"What breed of dogs would you like to see?"<<endl<<"Breed:";
        string breed_choice;
        cin.ignore();
        getline(cin, breed_choice);

        user_service.filter_dogs_by_breed(breed_choice);

        dogs_of_breed = user_service.get_dogs_filtered();
        int size_of_list = dogs_of_breed.size();
        if(size_of_list > 0){
            valid_breed = true;
        }
        else
            cout<<"It seems that there are no dogs of the given breed in our shelter. Try another one."<<endl<<endl;
    } while(!valid_breed);

}

void UserInterface::print_current_dog() {
    UserService user_service = this->get_user_service();

    cout<<endl<<"AVAILABLE DOG:"<<endl;
    print_dog(user_service.get_current_dog());
    cout<<endl;
}


void UserInterface::start_user_mode(){

    cout<<"Welcome!"<<endl<<endl;

    this->set_output_file();
    this->read_breed_of_dogs();

    bool finished = false;
    while(!finished){
        this->print_current_dog();
        this->print_menu_of_user();
        char user_option;
        cin>>user_option;
        switch (user_option) {
            case '1':{
                /// adopt
                this->adopt_dog_user();
                /// next
                if(!this->jump_to_next_dog_user()) {
                    this->open_adoption_list();
                    finished = true;
                }
                break;
            }
            case '2':{
                /// next
                if(!this->jump_to_next_dog_user())
                    finished = true;
                break;
                }

            case '3':{
                this->print_adoption_list_user();
                break;
            }

            case '4':{
                this->read_breed_of_dogs();
                break;
            }

            case '5':{
                this->open_adoption_list();
                break;
            }

            case '0':{
                cout<<"See you soon!"<<endl;
                exit(0);
            }

            default:
                cout<<"Invalid command!"<<endl;
        }

    }
}

void UserInterface::start_program(){
    char mode_option;
    cout<<"1. Admin mode."<<endl;
    cout<<"2. User mode."<<endl;
    cout<<"Your option:";
    cin>>mode_option;

    if(mode_option == '1')
        this->start_administrator_mode();
    else
        if(mode_option == '2')
            this->start_user_mode();
        else{
            cout<<"Invalid command."<<endl;
            this->start_program();
        }
}

UserInterface::~UserInterface()=default;