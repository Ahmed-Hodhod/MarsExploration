#include "MarsStation.h"
#include"HeaderofHeaders.h"
#include<iostream>
using namespace std;


int main()
{

	Input I;
	int appmode = I.setMode();    //ask for mode  
	Modes AM = I.getMode(appmode);   //AM: appmode
	MarsStation MS(&I);  //Create mars station object and pass this input and ask for file name 
	Output O(&MS);   // pass all its data for the output object 
	MS.Set_Output_Interface(&O);
	bool done = false;
	
	/*
	*  	1. Increment Today 
	*	2. Loop over EventList to check if there is an event to be executed 
	*	3. Loop over the waiting Emergency and then waiting Polar to assign them to available rovers 
	*   4. Loop over the In_Execution_Missions to move the completed to Completed_List [Loop over the whole list]    Decrement count of Avaialable_Missions 
	*		Update the Associated_Rover 
	*	5. Loop over the Checkup List to move the rovers who finished checkup duration to the available list again
	*	6. Loop over the In_Execution Rovers To know if they returned to The base after they finished they finished their missions 
	*	7. 
	*/


	while (!done) {
		MS.Operate(done, AM);
	}
	

	return 0;
}

