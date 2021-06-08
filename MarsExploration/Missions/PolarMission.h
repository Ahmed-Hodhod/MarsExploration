#pragma once
#include "Missions.h"

#include <iostream>
class PolarMission : public Missions  //Changed to Public 
{
public:
	//PolarMission(int Dform, int mID, int loc, int dur, int sig,Rovers* attachedrover);
	using Missions::Missions; 
	//ozer did all of this 
	void Save_Data(ofstream& outfile);
	 Rovers* get_rover();
	 bool Attach_Rover(Rovers* Rptr);

	 virtual int get_significance() const;

	
	 void set_WD(int wd);
	 int get_ID() const;
	 int get_WD() const;
	 int get_CD() const;
	 int get_FD() const;

	 int getT_Loc() const;
	 int getM_Duration() const;
	

	 void Update_CD();
	 void Update_WD();
	 void Print_Mission_Rover();
	 char get_type();

	 int Update_Exd();
};

