#pragma once

#include"Rovers.h"
class PolarRovers : public Rovers
{
public:
    using Rovers::Rovers;  //oz

    int getSpeed();

  //  int CalculateDuration(int Duration, int TargetLocation);

    void setMaxMissions(int MaxMissionsNo);

   

    int getID();

    bool getStat(); 

    void Toggle();

    int get_Return_time(int Tarloc);

    int getMaxMissions();

    int UpdateMissions();
};


