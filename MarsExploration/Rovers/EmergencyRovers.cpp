#include "EmergencyRovers.h"
#include <iostream>


int EmergencyRovers::getSpeed()
{
	return speed;
}


void EmergencyRovers::setMaxMissions(int MaxMissionsNo)
{
	MaxMissions = MaxMissionsNo;
}


int EmergencyRovers::getID()
{
	return ID;
}

bool EmergencyRovers::getStat()
{
	return Associated;
}

void EmergencyRovers::Toggle()
{
	if (Associated) { Associated = false; }
	else { Associated = true; }
}

int EmergencyRovers::get_Return_time(int Tarloc)   //oz
{
	return ceil((Tarloc / (speed*25)));
}

int EmergencyRovers::getMaxMissions()
{
	return MaxMissions;
}

int EmergencyRovers::UpdateMissions()
{
	return MaxMissions--;
}
