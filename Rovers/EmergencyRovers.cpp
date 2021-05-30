#include "EmergencyRovers.h"
#include<iostream>
EmergencyRovers::EmergencyRovers(float s, int max)
{
	speed = s;
	MaxMissions = max;
}

float EmergencyRovers::getSpeed()
{
	return speed;
}

float EmergencyRovers::CalculateDuration(float Duration, float TargetLocation)
{

	float JourneyTime;
	JourneyTime = TargetLocation / getSpeed();
	float TotalDuration = (2 * JourneyTime) + Duration;
	return ceil(TotalDuration / 25);
}

void EmergencyRovers::setMaxMissions(int MaxMissionsNo)
{
	MaxMissions = MaxMissionsNo;
}

int EmergencyRovers::getMaxMissions()
{
	return MaxMissions;
}

int EmergencyRovers::UpdateMissions()
{
	return MaxMissions--;
}


