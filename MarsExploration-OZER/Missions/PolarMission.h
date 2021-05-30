#pragma once
#include "Missions.h"

class PolarMission : private Missions
{
public:
	//PolarMission(int Dform, int mID, int loc, int dur, int sig,Rovers* attachedrover);
	using Missions::Missions; 
	//ozer did all of this 
	void Save_Data(ofstream& outfile);
	 Rovers* get_rover();
	 bool Attach_Rover(Rovers* Rptr);

	 virtual int get_significance() const;

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

