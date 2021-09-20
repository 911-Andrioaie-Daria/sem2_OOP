//
// Created by daria on 24/03/2021.
//

#ifndef A45_911_ANDRIOAIE_DARIA_USERSERVICE_H
#define A45_911_ANDRIOAIE_DARIA_USERSERVICE_H

#include <fstream>
#include <windows.h>
#include <shellapi.h>

#include "DogRepository.h"
#include "AbstractAdoptionList.h"
//
//class AbstractAdoptionList{
//protected:
//    vector<Dog> data;
//public:
//    AbstractAdoptionList();
//    virtual ~AbstractAdoptionList();
//
//    vector<Dog>& get_data(){
//        return this->data;
//    }
//    virtual void write()=0;
//    virtual void open()=0;
//
//};
//
//class CSVAdoptionList: public AbstractAdoptionList{
//private:
//    string file;
//public:
//    explicit CSVAdoptionList(const string& filename);
//    ~CSVAdoptionList() override;
//
//    void write() override{
//        ofstream out_file(this->file);
//        for(auto& dog: this->data){
//            out_file<<dog.to_csv_representation()<<endl;
//        }
//    }
//    void open() override{
//        this->write();
//        ShellExecuteA(nullptr, "open", "AdoptionList.csv", nullptr, nullptr, SW_SHOWNORMAL);
//    }
//};
//
//class HTMLAdoptionList: public AbstractAdoptionList{
//private:
//    string file;
//public:
//    explicit HTMLAdoptionList(const string& filename);
//    ~HTMLAdoptionList() override;
//
//
//    void write() override{
//        ofstream out_file(this->file);
//        out_file<<"<!DOCTYPE html>"<<endl;
//        out_file<<"<html>"<<endl;
//        out_file<<"<head>"<<endl;
//        out_file<<"\t<title>Happy dogs</title>"<<endl;
//        out_file<<"</head>"<<endl;
//        out_file<<"<body>"<<endl;
//        out_file<<"<table border='2'>"<<endl;
//
//        /// the header of the table
//        out_file<<"\t<tr>"<<endl;
//        out_file<<"\t\t<td>Name</td>"<<endl;
//        out_file<<"\t\t<td>Breed</td>"<<endl;
//        out_file<<"\t\t<td>Age</td>"<<endl;
//        out_file<<"\t\t<td>Photograph</td>"<<endl;
//        out_file<<"\t</tr>"<<endl;
//
//        ///here print the doggos
//        for(auto& dog:this->data){
//            out_file<<dog.to_HTML_representation();
//        }
//        out_file<<"</table>"<<endl;
//        out_file<<"</body>"<<endl;
//        out_file<<"</html>"<<endl;
//
//    }
//    void open() override{
//        this->write();
//        ShellExecuteA(nullptr, "open", "AdoptionList.html", nullptr, nullptr, SW_SHOWNORMAL);
//    }
//};
//
//

class UserService {
private:
    DogRepository& repository;
    AbstractAdoptionList* adopted_dogs{};
    vector<Dog> dogs_filtered_by_breed{};
    int dog_index_in_show_list;

public:

    /// parameter constructor
    explicit UserService(DogRepository& dog_repository);

    void setCSVFile();

    void setHTMLFile();

    /// The function filters the dogs in the database by a given breed,
    /// always storing the result of the filtering in this->dogs_filtered_by_breed;
    /// \param dog_breed: can be either a specific breed or an empty string,
    /// case in which all the dogs in the database will be stored in the filtered list.
    void filter_dogs_by_breed(const string& dog_breed);

    /// The function adds a dog to the list of adopted dogs and calls the method which
    /// removes the adopted dog from the repository.
    /// \param lucky_dog: the instance of the class Dog that is adopted.
    void adopt_dog(const Dog& lucky_dog);

    void open_adoption_list();

    /// Getter function for the repository under the service.
    DogRepository& get_repository();

    /// Getter function for the list of adopted dogs.
    vector<Dog>& get_adopted_dogs();

    /// Getter function for the list of dogs filtered by breed.
    vector<Dog>& get_dogs_filtered();

    /// Getter function for the current dog inside the list of dogs filtered by breed.
    Dog get_current_dog();

    /// Getter function for the index of the current dog inside the list of dogs filtered by breed.
    int get_dog_index() const;

    /// Function that increments the index of the current dog inside the list of dogs filtered by breed
    void increment_dog_index();

    /// destructor
    ~UserService();

};



#endif //A45_911_ANDRIOAIE_DARIA_USERSERVICE_H
