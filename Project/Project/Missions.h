#pragma once

#include "Rovers.h"
class Missions
{
private: 
	int FD; // Formulation Day 
	int Tar_Loc; // Mission Target Location 
	int Duaration; // Mission Duration 
	int Assign_Day; // The Day when the Mission got assigned 
	Rovers* Attached_Rover; // The rover which is was assigned the mission 

public:
	Missions(int FD, int Tar_Loc, int  Duaration,
		int Assign_Day, Rovers* Attached_Rover) :FD(FD), Tar_Loc(Tar_Loc), Duaration(Duaration),
		Assign_Day(Assign_Day), Attached_Rover(Attached_Rover) {}; 
	virtual ~Missions() = 0; 
	
};

