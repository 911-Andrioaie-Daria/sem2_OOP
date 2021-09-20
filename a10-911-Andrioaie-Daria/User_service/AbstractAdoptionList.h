//
// Created by daria on 19/04/2021.
//

#ifndef A67_911_ANDRIOAIE_DARIA_ABSTRACTADOPTIONLIST_H
#define A67_911_ANDRIOAIE_DARIA_ABSTRACTADOPTIONLIST_H

#include "Dog.h"
#include "vector"
#include <fstream>
#include <windows.h>
#include <shellapi.h>

class AbstractAdoptionList{
protected:
    vector<Dog> data;
public:
    AbstractAdoptionList();
    virtual ~AbstractAdoptionList();

    vector<Dog>& get_data(){
        return this->data;
    }


    virtual void write()=0;
    virtual void open()=0;

};

class CSVAdoptionList: public AbstractAdoptionList{
private:
    string file;
public:
    explicit CSVAdoptionList(const string& filename);
    ~CSVAdoptionList() override;

    void write() override{
        ofstream out_file(this->file);
        for(auto& dog: this->data){
            out_file<<dog.to_csv_representation()<<endl;
        }
    }
    void open() override{
        this->write();
        ShellExecuteA(nullptr, "open", "AdoptionList.csv", nullptr, nullptr, SW_SHOWNORMAL);
    }
};

class HTMLAdoptionList: public AbstractAdoptionList{
private:
    string file;
public:
    explicit HTMLAdoptionList(const string& filename);
    ~HTMLAdoptionList() override;


    void write() override{
        ofstream out_file(this->file);
        out_file<<"<!DOCTYPE html>"<<endl;
        out_file<<"<html>"<<endl;
        out_file<<"<head>"<<endl;
        out_file<<"\t<title>Happy dogs</title>"<<endl;
        out_file<<"</head>"<<endl;
        out_file<<"<body>"<<endl;
        out_file<<"<table border='2'>"<<endl;

        /// the header of the table
        out_file<<"\t<tr>"<<endl;
        out_file<<"\t\t<td>Name</td>"<<endl;
        out_file<<"\t\t<td>Breed</td>"<<endl;
        out_file<<"\t\t<td>Age</td>"<<endl;
        out_file<<"\t\t<td>Photograph</td>"<<endl;
        out_file<<"\t</tr>"<<endl;

        ///here print the doggos
        for(auto& dog:this->data){
            out_file<<dog.to_HTML_representation();
        }
        out_file<<"</table>"<<endl;
        out_file<<"</body>"<<endl;
        out_file<<"</html>"<<endl;

    }
    void open() override{
        this->write();
        ShellExecuteA(nullptr, "open", "AdoptionList.html", nullptr, nullptr, SW_SHOWNORMAL);
    }
};



#endif //A67_911_ANDRIOAIE_DARIA_ABSTRACTADOPTIONLIST_H
