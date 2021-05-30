#include "MountainousRovers.h"
#include<iostream>

MountainousRovers::MountainousRovers(float sp, int max, int check):Rovers(sp,max,check)
{
	
}

float MountainousRovers::getSpeed()
{
	return speed;
}

float MountainousRovers::CalculateDuration(float Duration, float TargetLocation)
{
	float JourneyTime;
	JourneyTime = TargetLocation / getSpeed();
	float TotalDuration = (2 * JourneyTime) + Duration;
	return ceil(TotalDuration / 25);
}

void MountainousRovers::setMaxMissions(int MaxMissionsNo)
{
	MaxMissions = MaxMissionsNo;
}

int MountainousRovers::getCheckupDuration()
{
	return CheckupDuration;
}

int MountainousRovers::getMaxMissions()
{
	return MaxMissions;
}

int MountainousRovers::UpdateMissions()
{
	return MaxMissions--;
}
