#pragma once 
#include<iostream>
using namespace std;
#include"Input.h"
//#include"../MarsStation.h"
class MarsStation;
class Output {
	Input* pIn; 
	const MarsStation* BStationptr;
public :
	Output(const MarsStation* BSptr);
	Input* getInput();
	void PrintDay();
	void PrintMsg(int s);
	void printRovers();
	void printMissions();
	void DisplayMessage();
	void ShowStatistics();
	const MarsStation* Get_Pointer_to_Base_Station();
	~Output();
};
