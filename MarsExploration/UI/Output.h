#pragma once 
#include<iostream>
using namespace std;
#include"Input.h"
#include<Windows.h>
class MarsStation;
class Output {
	MarsStation* BStationptr;
public:
	Output(MarsStation* BSptr);
	void PrintDay(MarsStation* msptr);
	void PrintMsg(string s);
	
	~Output();
};

