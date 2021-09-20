//
// Created by daria on 05/04/2021.
//

#ifndef A67_911_ANDRIOAIE_DARIA_FILEREPOSITORY_H
#define A67_911_ANDRIOAIE_DARIA_FILEREPOSITORY_H

#include "DogRepository.h"
#include <fstream>

class FileRepository : public DogRepository{
private:
    string file_name;

    void write_data(const vector<Dog>& dog_array);
    vector<Dog> load_data();

public:
    explicit FileRepository(const std::string& File);

    void init() override;

    vector<Dog>& get_dog_array() override;

    void add_dog(const Dog& new_dog) override;

    void delete_dog(const string& dog_breed, const string& dog_name) override;

    void update_dog_age(const string& dog_breed, const string& dog_name, int new_dog_age) override;

    void update_dog_photograph(const string& dog_breed, const string& dog_name, const string& new_dog_photograph) override;

    int search_dog(const string& dog_breed, const string& dog_name) override;

    ~FileRepository() override;
};


#endif //A67_911_ANDRIOAIE_DARIA_FILEREPOSITORY_H
