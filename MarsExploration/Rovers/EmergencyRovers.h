#pragma once
#include "Rovers.h"
class EmergencyRovers : public Rovers
{
public:
    using Rovers::Rovers;

    int getSpeed();

   // int CalculateDuration(int Duration, int TargetLocation);

    void setMaxMissions(int MaxMissionsNo);


    int getID(); 

    bool getStat();

    void Toggle();

    int get_Return_time(int Tarloc); //oz

    int getMaxMissions();

    int UpdateMissions();

};

