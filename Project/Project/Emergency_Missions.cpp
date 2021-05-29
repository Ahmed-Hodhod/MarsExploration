#include "Emergency_Missions.h"


Emergency_Missions::Emergency_Missions(int FD, int Tar_Loc, int  Duaration,
	int Assign_Day, Rovers* Attached_Rover, int SIG) : Missions(FD, Tar_Loc,
		Duaration, Assign_Day, Attached_Rover), SIG(SIG) { 
};

Emergency_Missions::~Emergency_Missions()
{
	// Just do nothing 
}



