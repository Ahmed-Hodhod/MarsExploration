#pragma once
#include "Missions.h"
class EmergencyMission :
    private Missions
{
	EmergencyMission(int Dform, int mID, int loc, int dur, int sig, Rovers* attachedrover);
	 Rovers* get_rover();
	 int getT_Loc();
	 int getM_Duration() const;
	 int get_significance() const;
	
};

