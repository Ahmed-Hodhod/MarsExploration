#pragma once
#include "Missions.h"


class MountainousMission : private Missions
{
public:
	//MountainousMission(int Dform, int mID, int loc, int dur, int sig,Rovers* attachedrover);
	using Missions::Missions;
	void Save_Data(ofstream& outfile);
	Rovers* get_rover();
	bool Attach_Rover(Rovers* Rptr);
	int get_significance() const;
	void set_CD(int cd);
	void set_Exd(int exd);
	void set_WD(int wd);
	int get_ID() const;
	int get_WD() const;
	int get_CD() const;
	int get_FD() const;
	int get_ED() const;
	int getT_Loc() const;
	int getM_Duration() const;
};

