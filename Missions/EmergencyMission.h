#pragma once
#include "Missions.h"
class EmergencyMission :
    private Missions
{
	//EmergencyMission(int Dform, int mID, int loc, int dur, int sig, Rovers* attachedrover);
	using Missions::Missions; // To use the same constructor of Missions

	 int get_significance() const;
	
};

/*

#pragma once
#include "Missions.h"
class Emergency_Missions: public Missions
{

public:
	Emergency_Missions(int FD, int ID, int Tar_Loc, int Duration, int SIG) :
		Missions(FD, ID, Tar_Loc, Duration, SIG, -1, nullptr) {};
	~Emergency_Missions();
};*/
