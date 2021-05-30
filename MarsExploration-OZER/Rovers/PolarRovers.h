#pragma once

#include"Rovers.h"
class PolarRovers : public Rovers
{
    PolarRovers(float sp, int max , int check);

    float getSpeed();

    float CalculateDuration(float Duration, float TargetLocation);

    void setMaxMissions(int MaxMissionsNo);

    int getCheckupDuration();

    int getMaxMissions();

    int UpdateMissions();
};


