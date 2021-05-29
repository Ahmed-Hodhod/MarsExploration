#pragma once
#include "queue.h"
#include "MarsStation.h"
#include "Missions.h"
#include "Emergency_Missions.h"
#include "PolarMissions.h"
#include "Rovers.h"
#include "Polar_Rovers.h"
#include "Emergency_Rovers.h"
#include "Events.h"
#include "Formulate_Event.h"


template <class T> 
class MarsStation
{
private:
	int today;
	int Emer_rov_count; // Emergency Rovers Count 
	int Polar_rov_count; // Polar Rovers Count 
	int Moun_rov_count; // Mountanious Rovers Count 
	int Emer_rov_speed; // Emergency Rovers Speed
	int Polar_rov_speed; // Polar Rovers Speed
	int Moun_rov_speed;  // Mountanious Rovers Speed

	// Lists 
	LinkedQueue<T>* EventList; // Queue of events [Event list]




public:
	MarsStation(); 
	// The remainaing functions go here
	

	MarsStation~(); 




};

