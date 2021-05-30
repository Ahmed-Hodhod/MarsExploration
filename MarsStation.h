#pragma once
#include "MarsStation.h"
#include "Missions/Missions.h"
#include "Missions/EmergencyMission.h"
#include "Missions/PolarMission.h"
#include "Rovers/Rovers.h"
#include "Rovers/PolarRovers.h"
#include "Rovers/EmergencyRovers.h"
#include "Events/Events.h"
#include "Events/FormulationEvent.h"
#include "ADT/LinkedList.h"
#include "ADT/Queue.h"



template <class T>
class MarsStation
{
private:
	int today;
	// Numbers Are just for testing [ as a sample test ] 
	int Emer_rov_count = 2; // Emergency Rovers Count 
	int Polar_rov_count = 3; // Polar Rovers Count 
	int Moun_rov_count = 3; // Mountanious Rovers Count 
	int Emer_rov_speed = 2; // Emergency Rovers Speed
	int Polar_rov_speed = 2; // Polar Rovers Speed
	int Moun_rov_speed = 1;  // Mountanious Rovers Speed
	int Missions_Count = 6; // Count missions based on number of Formulation Events ? 
	int Count_Of_Missions_Before_Checkup = 3; // Number of Missions per checkup 

	// Solo Pointer 


	// Lists 
	LinkedQueue<T>** EventList; // Queue of events [Event list]
	LinkedQueue<T> Waiting_Emergency_Missions; // To be PriorityQueue Later 
	LinkedList<T>** Completed_Emergency_Missions;
	LinkedList<T>** In_Execution_Emergency_Missions;

	LinkedQueue<T> Waiting_Polar_Missions;
	LinkedList<T>** Completed_Polar_Missions;
	LinkedList<T>** In_Execution_Polar_Missions;

	// Why Avaialable is LinkedList ??? 
	LinkedList<T>** In_Checkup_Emergency_Rovers;
	LinkedList<T>** Available_Emergency_Rovers;

	LinkedQueue<T>** In_Checkup_Polar_Rovers;
	LinkedList<T>** Available_Polar_Rovers;


	// Test because that other classes are incomplete 
	void Formulate_Event(char Type, int ED, int ID, int Tar_Loc, int Duration, int SIG)
	{
		if (Type == 'E')
		{
			return;
		}
	}

	void AddToMissionsList(Missions* mission) {
		if (dynamic_cast<PolarMission*>(mission) )
		{
			Waiting_Polar_Missions.enqueue(mission);
		}
		else if (dynamic_cast<EmergencyMission*>(mission))
		{
			Waiting_Emergency_Missions.enqueue(mission);
		}
	}


public:
	MarsStation();
	// The remainaing functions go here

	
};

/*
Comments :
- At startup, Load the file and fill the data members.
- Count Missions based on number of Formulation Events

- el Events needs to take the pointer object of MarsStation Object

*/