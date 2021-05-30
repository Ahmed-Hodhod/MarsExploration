#pragma once
#include "Missions/Missions.h"
#include "Missions/EmergencyMission.h"
#include "Missions/PolarMission.h"
#include "Rovers/Rovers.h"
#include "Rovers/PolarRovers.h"
#include "Rovers/EmergencyRovers.h"
#include "Events/Events.h"
#include "Events/FormulationEvent.h"
//#include "ADT/LinkedList.h"
//#include "ADT/Queue.h"
//#include"ADT/PriQ.h"
//#include"ADT/Node.h"
#include "UI/Input.h"
#include "UI/Output.h"




class MarsStation
{
private:
	int today;
	// Numbers Are just for testing [ as a sample test ] 
	int Emer_rov_count; // Emergency Rovers Count 
	int Polar_rov_count; // Polar Rovers Count 
	int Moun_rov_count; // Mountanious Rovers Count 
	int Emer_rov_speed; // Emergency Rovers Speed
	int Polar_rov_speed; // Polar Rovers Speed
	int Moun_rov_speed;  // Mountanious Rovers Speed
	int Missions_Count; // Count missions based on number of Formulation Events ? 
	int Emer_Missions_Before_Checkup; // Number of Missions before checkup for emergency 
	int Moun_Missions_Before_Checkup; //Number of Missions before checkup for emergency 
	int Polar_Missions_Before_Checkup; //Number of Missions before checkup for emergency 
	int Checkup_Duration;              //Checkup duration for all rovers 

	// Solo Pointer 
	Input* Input_Interface;
	Output* Output_Interface;

	/* Lists 
	LinkedQueue<Events> EventList; // Queue of events [Event list]
	LinkedPriQueue<Missions*> Waiting_Emergency_Missions; // To be PriorityQueue Later 
	LinkedList<Missions*> Completed_Emergency_Missions;
	LinkedList<Missions*> In_Execution_Emergency_Missions;

	LinkedQueue<Missions*> Waiting_Polar_Missions;
	LinkedList<Missions*> Completed_Polar_Missions;
	LinkedList<Missions*> In_Execution_Polar_Missions;

	// Why Avaialable is LinkedList ??? to be easily printed 
	LinkedList<Rovers*> In_Checkup_Emergency_Rovers;
	LinkedList<Rovers*> Available_Emergency_Rovers;

	LinkedQueue<Rovers*> In_Checkup_Polar_Rovers;
	LinkedList<Rovers*> Available_Polar_Rovers;
	


	

	void AddToMissionsList(Missions* mission) {
		if (dynamic_cast<PolarMission*>(mission) )
		{
			Waiting_Polar_Missions.enqueue((mission));
		}
		else if (dynamic_cast<EmergencyMission*>(mission))
		{
			Waiting_Emergency_Missions.enqueue(mission,mission->get_significance());
		}
	}

	void AddToRoversList(Rovers* rover) {
		if (dynamic_cast<PolarRovers*>(rover))
		{
			Available_Polar_Rovers.InsertEnd(rover);
		}
		else if (dynamic_cast<EmergencyRovers*>(rover))
		{
			Available_Emergency_Rovers.InsertEnd(rover);
		}
	}
	*/


public:
	MarsStation();
	// The remainaing functions go here
	Input* Get_Input_Interface();
	Output* Get_Output_Interface();
	void SaveSimulation(ofstream& outfile);
	void Readfile();
};

/*
Comments :
- At startup, Load the file and fill the data members.
- Count Missions based on number of Formulation Events

- el Events needs to take the pointer object of MarsStation Object

*/


inline MarsStation::MarsStation()
{
	Missions_Count = 0;
}


inline Input* MarsStation::Get_Input_Interface()
{
	return Input_Interface;
}

inline Output* MarsStation::Get_Output_Interface()
{
	return Output_Interface;
}




inline void MarsStation::SaveSimulation(ofstream& outfile)
{
}


inline void MarsStation::Readfile()
{
	Input* Input = Get_Input_Interface();
	string filename = Input->Get_File_name();
	ifstream infile;
	infile.open(filename);
	
	infile >> Emer_rov_count >> Moun_rov_count >> Polar_rov_count;
	//create queues of rovers 
	
	infile >> Emer_rov_speed >> Moun_rov_speed >> Polar_rov_speed;
	//assign speeds
	infile >> Emer_Missions_Before_Checkup >> Moun_Missions_Before_Checkup >> Polar_Missions_Before_Checkup >> Checkup_Duration;
	//assign max mission before checkup and checkup duration 
	infile.ignore(6); //ignores AutoP
	//infile.seekg(29); //or maybe 5 
	int countEvents; 
	infile >> countEvents;
	for (int i = 0; i < countEvents; i++) {
		char eventtype;
		infile >> eventtype;
		if (eventtype == 'F') {
			char type;
			int ED, ID, LOCAT, DUR, SIG;
			infile >> type >> ED >> ID >> LOCAT >> DUR >> SIG;
			FormulationEvent* Fptr = new FormulationEvent(ED, ID, type, LOCAT, DUR, SIG);
			//we need a function to add to events list 
			Missions_Count++;
		}
		else {
			infile.ignore(256, '\n');
		}
	}
}
