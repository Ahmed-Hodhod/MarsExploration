#ifndef _INPUT_H
#define _INPUT_H
#include <iostream>
using namespace std; 

enum Modes { Interactive , StepbyStep , Silent};
class Input {
public : 
	Modes getMode();
	void GetPress();
};
#endif