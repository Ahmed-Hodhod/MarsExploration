#include "MountainousMission.h"

MountainousMission::MountainousMission(int Dform, int mID, int loc, int dur, int sig, Rovers* attachedrover):Missions(Dform,mID,loc,dur,sig,attachedrover)
{
}

int MountainousMission::getT_Loc() const
{
	return T_Loc;
}

int MountainousMission::getM_Duration() const
{
	return M_Duration;
}

int MountainousMission::get_significance() const
{
	return signif;

}

MountainousMission::~MountainousMission()
{
	//nothing
}
