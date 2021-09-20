//
// Created by daria on 22/06/2021.
//

#ifndef E2_911_ANDRIOAIE_DARIA_1_OBSERVER_H
#define E2_911_ANDRIOAIE_DARIA_1_OBSERVER_H

#endif //E2_911_ANDRIOAIE_DARIA_1_OBSERVER_H

#pragma once

#include "vector"
#include "algorithm"
using namespace std;

class Observer{
public:
    virtual void update()=0;
    virtual ~Observer()= default;
};

class Observable{
private:
    vector<Observer*> observers;

public:
    virtual ~Observable() = default;

    void addObserver(Observer *obs)
    {
        observers.push_back(obs);
    }

    void removeObserver(Observer *obs)
    {
        auto it = std::find(this->observers.begin(), this->observers.end(), obs);
        if (it != observers.end())
            this->observers.erase(it);
    }

    void notify()
    {
        for (auto obs: observers)
        {
            obs->update();
        }
    }
};
