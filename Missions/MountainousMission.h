#ifndef _MOUNTAINOUS_MISSIONS_H
#define _MOUNTAINOUS_MISSIONS_H
#include "Missions.h"
class MountainousMission :
    private Missions
{
public :
	MountainousMission(int Dform, int mID, int loc, int dur, int sig, Rovers* attachedrover);
	 int getT_Loc() const;
	 int getM_Duration() const; 
	 int get_significance() const;
	~MountainousMission();
};
#endif
