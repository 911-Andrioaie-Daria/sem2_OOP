//
// Created by daria on 22/06/2021.
//

#ifndef E2_911_ANDRIOAIE_DARIA_1_SERVICE_H
#define E2_911_ANDRIOAIE_DARIA_1_SERVICE_H

#include "Repository.h"
#include "Observer.h"

class Service : public Observable{
private:
    Repository& repository;

public:
    Service(Repository &repository1);
    ~Service();
    vector<Ethnologist>& get_ethnologists();
    vector<Building>& get_buildings();
    void addBuilding(const string& description, const string& area, const string& location);
    void updateBuilding(int id, const string &description, const string &location);
    vector<string> tokenizeLocation(const string& location);

    bool checkOverlaps(vector<string> squareLocations, int id);
    bool checkContiguousArea(vector<string> squareLocations);
    vector<Building> getSortedByArea(Ethnologist ethnologist);
};


#endif //E2_911_ANDRIOAIE_DARIA_1_SERVICE_H
