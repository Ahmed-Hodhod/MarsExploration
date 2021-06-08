#pragma once
#include"Events.h"
#include "../Missions/Missions.h"
#include "../Missions/PolarMission.h"
#include "../Missions/EmergencyMission.h"

// HOD
#include "../ADT/LinkedQueue.h"
#include "../ADT/PriQ.h"


class FormulationEvent :
    private Events
{
private:
	int SIG;    //Mission Significance
	char Type;  //Misssion Type
	int Duration;  //Mission Duration
	int Tar_Loc;  //Mission Target Location
	LinkedQueue<PolarMission*>* WPM;
	PQueue<EmergencyMission*>* WEM; 

	
public:
	// Do we need all these Functions ??? 

	//FormulationEvent* Fptr = new FormulationEvent(ED, ID, type, LOCAT, DUR, SIG,
	//Waiting_Polar_Missions, Waiting_Emergency_Missions);
	FormulationEvent(char type, int ED, int ID, int Tar_Loc,
		int Dur, int SIG, LinkedQueue<PolarMission*> &WPM, PQueue<EmergencyMission*> &WEM);
	void Execute();
	char get_Type();
	int get_ED(); 
	int get_Duration();
	int get_TarLoc();
	int get_SIG();

	

};

