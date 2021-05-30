#pragma once
#include "Missions.h"

class PolarMission :
    private Missions
{
public:
	//PolarMission(int Dform, int mID, int loc, int dur, int sig,Rovers* attachedrover);
	using Missions::Missions; 

	 int get_significance() const;
};

