#include "PolarRovers.h"
#include <iostream>
PolarRovers::PolarRovers(float sp, int max)
{
	speed = sp;
	MaxMissions = max;
}

float PolarRovers::getSpeed()
{
	return speed;
}

float PolarRovers::CalculateDuration(float Duration, float TargetLocation)
{
	float JourneyTime;
	JourneyTime = TargetLocation / getSpeed();
	float TotalDuration = (2 * JourneyTime) + Duration;
	return ceil(TotalDuration / 25);
}

void PolarRovers::setMaxMissions(int MaxMissionsNo)
{
	MaxMissions = MaxMissionsNo;
}

int PolarRovers::getMaxMissions()
{
	return MaxMissions;
}

int  PolarRovers::UpdateMissions()
{
	return MaxMissions--;
}
