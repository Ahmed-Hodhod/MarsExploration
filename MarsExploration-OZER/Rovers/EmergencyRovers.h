#pragma once
#include "Rovers.h"
class EmergencyRovers : public Rovers
{

    EmergencyRovers(float s, int max , int check);

    float getSpeed();

    float CalculateDuration(float Duration, float TargetLocation);

    void setMaxMissions(int MaxMissionsNo);

    int getCheckupDuration();

    int getMaxMissions();

    int UpdateMissions();

};

