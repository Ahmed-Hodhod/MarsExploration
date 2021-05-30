#pragma once
#include"Events.h"
#include"../Missions/Missions.h"

class FormulationEvent :
    private Events
{
private:
	int SIG;    //Mission Significance
	char Type;  //Misssion Type
	int Duration;  //Mission Duration
	int Tar_Loc;  //Mission Target Location
public:
	// Do we need all these Functions ??? 
	FormulationEvent(int ED, int ID, int Type, int Duration, int Tar_Loc, int SIG);
	void Execute();
	char get_Type();
	int get_Duration();
	int get_TarLoc();
	int get_SIG();

};

