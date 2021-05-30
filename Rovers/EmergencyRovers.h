#pragma once
#include "Rovers.h"
class EmergencyRovers : public Rovers
{

    EmergencyRovers(float s, int max);

    float getSpeed();

    float CalculateDuration(float Duration, float TargetLocation);

    void setMaxMissions(int MaxMissionsNo);

    int getMaxMissions();

    int UpdateMissions();

};

