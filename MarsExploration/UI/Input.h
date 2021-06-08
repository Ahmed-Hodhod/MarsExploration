#ifndef _INPUT_H
#define _INPUT_H
#include <iostream>
#include<fstream>
#include<string>
using namespace std;

enum Modes { Interactive, StepbyStep, Silent };
class Input {
public:
	Input();
	int setMode();
	Modes getMode(int c);
	void GetPress();
	string Get_File_name(char S);
	~Input();
};
#endif