//
// Created by daria on 22/06/2021.
//

#ifndef E2_911_ANDRIOAIE_DARIA_1_ETHNOLOGIST_H
#define E2_911_ANDRIOAIE_DARIA_1_ETHNOLOGIST_H

#include "string"
#include "vector"
using namespace std;

class Ethnologist {
private:
    string name;
    string area;

public:
    Ethnologist();
    ~Ethnologist();
    Ethnologist(string _name, string _area);

    string getName();
    string getArea();

    friend istream& operator>>(istream& input, Ethnologist& ethnologist);
    static vector<string> tokenize(const string &line, char delimiter);
};


#endif //E2_911_ANDRIOAIE_DARIA_1_ETHNOLOGIST_H
