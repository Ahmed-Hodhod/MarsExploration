#pragma once
#include "Rovers.h"
class MountainousRovers :
    public Rovers
{
    MountainousRovers(float sp, int max);

    float getSpeed();

    float CalculateDuration(float Duration, float TargetLocation);

    void setMaxMissions(int MaxMissionsNo);

    int getMaxMissions();

    int UpdateMissions();
};

