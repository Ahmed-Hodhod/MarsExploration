#include<iostream>
using namespace std;
#include"Input.h"
class MarsStation;
#ifndef _OUTPUT_H
#define _OUTPUT_H

class Output {
	Input* pIn; 
	MarsStation* BStationptr;
public :
	Input* getInput();
	void PrintDay();
	void printRovers();
	void printMissions();
	void DisplayMessage();
	void ShowStatistics();
};
#endif