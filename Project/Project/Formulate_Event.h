#pragma once
#include "Events.h"


class Formulate_Event: public Events
{
private:
	int SIG;    //Mission Significance
	char Type;  //Misssion Type
	int Duration;  //Mission Duration
	int Tar_Loc;  //Mission Target Location
public:
	Formulate_Event(int ED, int ID, int Type, int Duration, int Tar_Loc, int SIG);
	void Execute();

};

