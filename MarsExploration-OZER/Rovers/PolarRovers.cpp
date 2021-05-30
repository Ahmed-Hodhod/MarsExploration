#include "PolarRovers.h"
#include <iostream>
PolarRovers::PolarRovers(float sp, int max, int check):Rovers(sp,max,check)
{
	
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

int PolarRovers::getCheckupDuration()
{
	return CheckupDuration;
}

int PolarRovers::getMaxMissions()
{
	return MaxMissions;
}

int  PolarRovers::UpdateMissions()
{
	return MaxMissions--;
}
