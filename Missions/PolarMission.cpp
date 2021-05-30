#include"PolarMission.h"

PolarMission::PolarMission(int Dform, int mID, int loc, int dur, int sig, Rovers* attachedrover):Missions(Dform,mID,loc,dur,sig,attachedrover)
{
}

Rovers* PolarMission::get_rover()
{
	return Associatedrover;
}

int PolarMission::getM_Duration() const
{
	return M_Duration;
}

int PolarMission::get_significance() const
{
	return signif;
}
