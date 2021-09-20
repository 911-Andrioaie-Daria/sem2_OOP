//
// Created by daria on 22/06/2021.
//

#ifndef E2_911_ANDRIOAIE_DARIA_1_REPOSITORY_H
#define E2_911_ANDRIOAIE_DARIA_1_REPOSITORY_H

#include "Ethnologist.h"
#include "Building.h"

class Repository {
private:
    vector<Ethnologist> ethnologists;
    vector<Building> buildings;
    int availableID;

public:
    Repository();
    ~Repository();

    vector<Ethnologist>& get_ethnologists();
    vector<Building>& get_buildings();

    void load_ethnologists();
    void load_buildings();

    void addBuilding(const string& description, const string& area, vector<string> square_location);
    void updateBuilding(int id, const string& description, const vector<string>& loaction);
};


#endif //E2_911_ANDRIOAIE_DARIA_1_REPOSITORY_H
