//
// Created by daria on 05/04/2021.
//

#include "FileRepository.h"

FileRepository::FileRepository(const std::string& File)
{
    this->file_name = File;
    this->dog_array = this->load_data();
}


void FileRepository::write_data(const vector<Dog>& dog_array) {
    ofstream out_file(this->file_name);
    for(const auto& current_dog : dog_array)
    {
        out_file << current_dog << "\n";
    }
}

vector<Dog> FileRepository::load_data() {
//    ifstream in_file(this->file_name);
//    Dog current_dog;
//    vector<Dog> dog_array;
//    while(in_file >> current_dog){
//        dog_array.push_back(current_dog);
//    }
//    return dog_array;

    ifstream in_file(this->file_name);
    Dog current_dog;
    vector<Dog> dog_array; //= this->get_dog_array();
    while(in_file >> current_dog){
        dog_array.push_back(current_dog);
    }
    return dog_array;
}

void FileRepository::add_dog(const Dog &new_dog) {
    this->dog_array = this->load_data();
    //vector<Dog> dog_array = load_data();
    int dog_position = this->search_dog(new_dog.get_dog_breed(), new_dog.get_dog_name());

    if(dog_position != -1){
        // the dog is already in the repo
        throw RepositoryException("Dog is already in the shelter");
    }
    this->dog_array.push_back(new_dog);
    this->write_data(this->dog_array);
}

void FileRepository::delete_dog(const string &dog_breed, const string &dog_name) {
    vector<Dog> dog_array = load_data();
    int dog_position = this->search_dog(dog_breed, dog_name);

    if(dog_position == -1){
        throw RepositoryException("Dog cannot be found in the shelter.");
    }
    dog_array.erase(dog_array.begin() + dog_position);
    this->write_data(dog_array);
}

void FileRepository::update_dog_age(const string &dog_breed, const string &dog_name, int new_dog_age) {
    vector<Dog> dog_array = load_data();
    int dog_position = this->search_dog(dog_breed, dog_name);

    if(dog_position == -1){
        throw RepositoryException("Dog cannot be found in the shelter.");
    }
    string dog_photograph = dog_array.at(dog_position).get_dog_photograph();
    Dog updated_dog(dog_breed, new_dog_age, dog_name, dog_photograph);
    dog_array.at(dog_position) = updated_dog;
    this->write_data(dog_array);
}

void FileRepository::update_dog_photograph(const string &dog_breed, const string &dog_name,
                                           const string &new_dog_photograph) {
    vector<Dog> dog_array = load_data();
    int dog_position = this->search_dog(dog_breed, dog_name);

    if(dog_position == -1){
        throw RepositoryException("Dog cannot be found in the shelter.");
    }
    int dog_age = dog_array.at(dog_position).get_dog_age();
    Dog updated_dog(dog_breed, dog_age, dog_name, new_dog_photograph);
    dog_array.at(dog_position) = updated_dog;
    this->write_data(dog_array);
}

int FileRepository::search_dog(const string &dog_breed, const string &dog_name) {
    vector<Dog> dog_array = this->load_data();
    int index = 0;
    for(auto& dog: dog_array){
        if(dog.get_dog_breed() == dog_breed && dog.get_dog_name() == dog_name)
            return index;
        index++;
    }
    return -1;
}

void FileRepository::init() {
    this->dog_array = this->load_data();
}

vector<Dog>& FileRepository::get_dog_array() {
    this->dog_array = this->load_data();
    return this->dog_array;
}

FileRepository::~FileRepository()= default;