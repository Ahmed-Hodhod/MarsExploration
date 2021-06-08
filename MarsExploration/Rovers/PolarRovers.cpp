#include "PolarRovers.h"
#include<iostream>

int PolarRovers::getSpeed()
{
	return speed;
}

//int PolarRovers::CalculateDuration(int Duration, int TargetLocation)
//{
//	int JourneyTime;
//	JourneyTime = TargetLocation / getSpeed();
//	int TotalDuration = (2 * JourneyTime) + Duration;
//	return ceil(TotalDuration / 25);
//}

void PolarRovers::setMaxMissions(int MaxMissionsNo)
{
	MaxMissions = MaxMissionsNo;
}



int PolarRovers::getID()
{
	return ID;
}

bool PolarRovers::getStat()
{
	return Associated;
}

void PolarRovers::Toggle()
{
	if (Associated) { Associated=false; }
	else { Associated = true; }
}

int PolarRovers::get_Return_time(int Tarloc)    //oz
{
	return ceil((Tarloc / (speed * 25)));
}



int PolarRovers::getMaxMissions()
{
	return MaxMissions;
}

int  PolarRovers::UpdateMissions()
{
	return MaxMissions--;
}
