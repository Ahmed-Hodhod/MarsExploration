#pragma once
#include "Missions.h"


class EmergencyMission : public Missions // Changed to Pulic 
{
public:
	//EmergencyMission(int Dform, int mID, int loc, int dur, int sig,Rovers* attachedrover);
	using Missions::Missions;
	//void Save_Data(ofstream& outfile);
	Rovers* get_rover();
	virtual bool Attach_Rover(Rovers* Rptr);

	//Rovers* get_Attached_Rover(); 
	int Update_Exd();
	int get_significance() const;
	
	int get_ID() const;
	int get_WD() const;
	int get_CD() const;
	int get_FD() const;

	int getT_Loc() const;
	int getM_Duration() const;

	void Update_CD();
	void Update_WD();
	
	int Calculate_New_pri();
	void Print_Mission_Rover();
	char get_type();
	
};

