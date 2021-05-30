#include"EmergencyMission.h"

EmergencyMission::EmergencyMission(int Dform, int mID, int loc, int dur, int sig, Rovers* attachedrover):Missions(Dform , mID,loc,dur,sig,attachedrover)
{
}


Rovers* EmergencyMission::get_rover()
{
	return Associatedrover;
}

int EmergencyMission::getT_Loc()
{
	return T_Loc;
}

int EmergencyMission::getM_Duration() const
{
	return M_Duration;
}

int EmergencyMission::get_significance() const
{
	return signif;
}


