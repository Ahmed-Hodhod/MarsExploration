#pragma once
#include "Missions.h"
class Emergency_Missions: public Missions
{
private:
	int SIG; 
public:
	Emergency_Missions(int FD, int Tar_Loc, int  Duaration,
		int Assign_Day, Rovers* Attached_Rover, int SIG); 
	~Emergency_Missions(); 
};

