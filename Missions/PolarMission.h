#pragma once
#include "Missions.h"

class PolarMission :
    private Missions
{
public:
	PolarMission(int Dform, int mID, int loc, int dur, int sig,Rovers* attachedrover);
	 Rovers* get_rover();
	 int getT_Loc() const { return T_Loc; }
	 int getM_Duration() const;
	 int get_significance() const;
};

