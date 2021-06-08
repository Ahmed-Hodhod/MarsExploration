#pragma once
#include "Missions/Missions.h"
#include "Missions/EmergencyMission.h"
#include "Missions/PolarMission.h"
#include "Rovers/Rovers.h"
#include "Rovers/PolarRovers.h"
#include "Rovers/EmergencyRovers.h"
#include "Events/Events.h"
#include "Events/FormulationEvent.h"

#include "ADT/LinkedQueue.h"
#include "ADT/LinkedList.h"

#include"ADT/PriQ.h"
#include "UI/Output.h"
#include "UI/Input.h"


#include <iostream> 



class MarsStation
{
private:
	// Numbers Are just for testing [ as a sample test ] 
	int Emer_rov_count; // Emergency Rovers Count 
	int Polar_rov_count; // Polar Rovers Count 
	int Moun_rov_count; // Mountanious Rovers Count 
	int Emer_rov_speed; // Emergency Rovers Speed
	int Polar_rov_speed; // Polar Rovers Speed
	int Moun_rov_speed;  // Mountanious Rovers Speed
	int Missions_Count; // Count missions based on number of Formulation Events ? 
	int Emer_Missions_Count; // Emergency Missions Count 
	int Pol_Missions_Count; // Polar Missions Count 
	int Emer_Missions_Before_Checkup; // Number of Missions before checkup for emergency 
	int Moun_Missions_Before_Checkup; //Number of Missions before checkup for emergency 
	int Polar_Missions_Before_Checkup; //Number of Missions before checkup for emergency 
	int Checkup_Duration;              //Checkup duration for all rovers 
	int Waiting_Missions_Count;
	int In_Execution_Missions_Count;
	int Completed_Missions_Count; 
	int Available_Rovers;
	int In_Check_Up_Rovers;
	int today = 0; 

	int EM_count; 
	int PM_count; 

	// Solo Pointer 
	Input* Input_Interface;
	Output* Output_Interface;

	//Queue or LinkedList ? 
	LinkedQueue<FormulationEvent*> EventList; // Queue of events [Event list]  , Make it Events Later 
	LinkedQueue<PolarMission*> Waiting_Polar_Missions; 
	PQueue<EmergencyMission*> Waiting_Emergency_Missions; // To be PriorityQueue Later 

	LinkedList<EmergencyMission*> In_Execution_Emergency_Missions;
	LinkedQueue<Missions*> Completed_Missions;
	LinkedList<PolarMission*> In_Execution_Polar_Missions;

	// Why Avaialable is LinkedList ??? to be easily printed 
	LinkedQueue<EmergencyRovers*> In_Checkup_Emergency_Rovers;
	LinkedList<EmergencyRovers*> Available_Emergency_Rovers;

	LinkedQueue<PolarRovers*> In_Checkup_Polar_Rovers;
	LinkedList<PolarRovers*> Available_Polar_Rovers;
	LinkedList<Rovers*> In_Execution_Rovers; 

public:
	MarsStation(Input* In);
	// The remainaing functions go here
	Input* Get_Input_Interface();
	
	void Set_Output_Interface(Output* Optr);
	//void SaveSimulation(ofstream& outfile);
	void Readfile();
	friend void Output::PrintDay(MarsStation* msptr);
	void SaveSimulation();
	double GetAvgWait();
	double GetAvgExec();
	void Operate(bool &executed ,  Modes MODE);
	void Update_Waiting_Missions();

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

	// TEST 

	
};

/*
Comments :
- At startup, Load the file and fill the data members.
- Count Missions based on number of Formulation Events

- el Events needs to take the pointer object of MarsStation Object
*/

inline void MarsStation::Readfile()
{
	string filename = Input_Interface->Get_File_name('L');
	ifstream infile;
	infile.open(filename);

	infile >> Polar_rov_count >> Emer_rov_count;
	//create queues of rovers 
	infile >> Polar_rov_speed >> Emer_rov_speed;
	//assign speeds
	infile >> Checkup_Duration >> Polar_Missions_Before_Checkup >> Emer_Missions_Before_Checkup;
	//assign max mission before checkup and checkup duration 
	int countEvents;
	infile >> countEvents;
	for (int i = 0; i < countEvents; i++) {
		if (!infile.eof()) {
			char eventtype;
			infile >> eventtype;
			if (eventtype == 'F') {
				char type;
				int ED, ID, LOCAT, DUR, SIG;
				infile >> type >> ED >> ID >> LOCAT >> DUR >> SIG;
				FormulationEvent* Fptr = new FormulationEvent(type, ED, ID, LOCAT, DUR, SIG,
					Waiting_Polar_Missions, Waiting_Emergency_Missions);

				EventList.enqueue(Fptr);

				// Count missions of each type 
				Missions_Count++;
				if (type == 'E') {
					EM_count++;
				}
				else if (type == 'P') {
					PM_count++;
				}

			}
		}
	}
}

inline MarsStation::MarsStation(Input* In )
{
	Input_Interface = In;
	Emer_Missions_Count = 0;
	Pol_Missions_Count = 0; 
	Completed_Missions_Count = In_Execution_Missions_Count = Waiting_Missions_Count = Missions_Count = 0;
	Emer_rov_count = Polar_rov_count = 0;
	Emer_rov_speed = Polar_rov_speed = 0;
	Emer_Missions_Before_Checkup = Polar_Missions_Before_Checkup = 0;
	Checkup_Duration = 0;
	EM_count = PM_count = 0;
	In_Check_Up_Rovers = 0;
	today = 0;
	// Create the Rovers here and add them to the proper lists 

	Readfile();
	for (int i = 0; i < Emer_rov_count; i++) {
		EmergencyRovers* Erover = new EmergencyRovers(Emer_rov_speed, Checkup_Duration, Emer_Missions_Before_Checkup, i + 1);
		Available_Emergency_Rovers.InsertEnd(Erover);
	}
	for (int i = 0; i < Polar_rov_count; i++) {
		PolarRovers* Prover = new PolarRovers(Polar_rov_speed, Checkup_Duration, Polar_Missions_Before_Checkup, (i + Emer_rov_count + 1));
		Available_Polar_Rovers.InsertEnd(Prover);
	}

	Available_Rovers = Emer_rov_count + Polar_rov_count;
}

inline Input* MarsStation::Get_Input_Interface()
{
	return Input_Interface;
}


inline void MarsStation::Set_Output_Interface(Output* Optr)
{
	Output_Interface = Optr;
}


inline double MarsStation::GetAvgWait()
{
	double Average_Wait = 0;
	int sum_waited = 0;
	int count = Completed_Missions.getCapacity();
	Node<Missions*>* P = Completed_Missions.get_FrontPtr();
	for (int i = 0; i < count; i++) {
		sum_waited += P->getItem()->get_WD();
		P = P->getNext();
	}
	Average_Wait = (double)sum_waited / count;
	return Average_Wait;
}

inline double MarsStation::GetAvgExec()
{
	double Exec_Wait = 0;
	int sum_exec = 0;
	int count = Completed_Missions.getCapacity();
	Node<Missions*>* P = Completed_Missions.get_FrontPtr();
	for (int i = 0; i < count; i++) {
		sum_exec += P->getItem()->get_ExD();
		P = P->getNext();
	}
	Exec_Wait = (double)sum_exec / count;
	return Exec_Wait;
}

inline void MarsStation::SaveSimulation()
{
	string filename = Input_Interface->Get_File_name('S');
	ofstream outfile;
	outfile.open(filename);
	outfile.clear();
	outfile << "CD" << "  ID" << "  FD" << "    WD" << "   ED  " << '\n';
	int count_completed = Completed_Missions.getCapacity();
	Node<Missions*>* P = Completed_Missions.get_FrontPtr();
	for (int i = 0; i < count_completed; i++) {
		outfile << P->getItem()->get_CD() << "   " << P->getItem()->get_ID() << "   " << P->getItem()->get_FD() << "     " << P->getItem()->get_WD() << "     " << P->getItem()->get_ExD() << endl;
		P = P->getNext();
	}
	outfile << "Missions :" << (Missions_Count) << " [ P: " << PM_count << ", E : " << EM_count << " ]" << endl;
	outfile << "Rovers :" << (Emer_rov_count + Polar_rov_count) << " [ P: " << Polar_rov_count << ", E : " << Emer_rov_count << " ]" << endl;
	outfile << "Avg.Wait = " << GetAvgWait() << "      , Avg.Exec = " << GetAvgExec() << endl;
	outfile.close();
}







inline void MarsStation::Operate(bool &executed , Modes MODE)
{

	// TEST 
	if (MODE == Silent) { Output_Interface->PrintMsg("Silent Mode ..."); 
	Output_Interface->PrintMsg("Simulation Starts...");
	}

	// We need to count all missions beforehand 
	while ((Completed_Missions_Count < Missions_Count || !EventList.isEmpty())) //1. 
	{
		++today;

		//2. All Events whose Due today will be executed 
		FormulationEvent* event;
		EventList.peek(event);
		while (!EventList.isEmpty())
		{
			if (event->get_ED() == today) // It is the time to be executed 
			{
				event->Execute(); // Call mission Cal_Priority | Update Missions Count 
				EventList.dequeue(event); // Pass the day to the event 
				EventList.peek(event);
				Waiting_Missions_Count++;
			}
			else
				break;
		}
		// 5.  InCheckupRovers [ Move them to Available ]

		if (!In_Checkup_Polar_Rovers.isEmpty())
		{
			PolarRovers* ptr;
			In_Checkup_Polar_Rovers.peek(ptr);

			while (!In_Checkup_Polar_Rovers.isEmpty() && today - ptr->get_CheckupStartingDay() == Checkup_Duration) { // Checkup Duration is Done 
				Available_Polar_Rovers.InsertEnd(ptr);
				In_Checkup_Polar_Rovers.dequeue(ptr);

				// update the rover's data members , Counters  
				In_Check_Up_Rovers--;
				Available_Rovers++;

				// Continue the Loop 
				In_Checkup_Polar_Rovers.peek(ptr);
			}

		}

		if (!In_Checkup_Emergency_Rovers.isEmpty())
		{
			EmergencyRovers* ptr;
			In_Checkup_Emergency_Rovers.peek(ptr);
			while (!In_Checkup_Emergency_Rovers.isEmpty() && today - ptr->get_CheckupStartingDay() == Checkup_Duration) // Checkup Duration is Done 
			{

				Available_Emergency_Rovers.InsertEnd(ptr);
				In_Checkup_Emergency_Rovers.dequeue(ptr);

				// update the rover's data members , Counters  
				In_Check_Up_Rovers--;
				Available_Rovers++;

				// Continue the Loop 
				In_Checkup_Emergency_Rovers.peek(ptr);
			}

		}
		// 3.  Loop over Avaialble Emergency rovers and Polar Ones 
		while (!Available_Emergency_Rovers.isEmpty() && !Waiting_Emergency_Missions.isEmpty()) 
		{

			EmergencyRovers* rover;
			Available_Emergency_Rovers.remove(rover);

			EmergencyMission* EM;
			Waiting_Emergency_Missions.dequeue(EM);

			EM->Attach_Rover(rover);
			rover->UpdateMissions();
			EM->Update_Exd(); // Because of Private Inheritance 


			// Update Rover Status and all its information 
			rover->set_Assignment_Day(today);
			rover->Toggle();
			rover->CalculateDuration(EM->getM_Duration(), EM->getT_Loc());

			Available_Rovers--;  //Initialize this counter 

			// Add to In_Execution_Emergency Missions 
			In_Execution_Emergency_Missions.InsertEnd(EM);
			In_Execution_Rovers.InsertEnd(rover);

			Waiting_Missions_Count--;
			In_Execution_Missions_Count++;

		}
		
		//ozer: //if there are av.rovers        // and waiting emergency                       or waiting polar
		while (!Available_Polar_Rovers.isEmpty() && (!Waiting_Emergency_Missions.isEmpty() || !Waiting_Polar_Missions.isEmpty()))
		{

			PolarRovers* rover;
			Available_Polar_Rovers.remove(rover);
			if (!Waiting_Emergency_Missions.isEmpty())
			{
				EmergencyMission* EM;
				Waiting_Emergency_Missions.dequeue(EM);
				EM->Attach_Rover(rover);
				rover->UpdateMissions();
				EM->Update_Exd(); // Because of Private Inheritance 
				rover->CalculateDuration(EM->getM_Duration(), EM->getT_Loc());
				In_Execution_Emergency_Missions.InsertEnd(EM);
			}
			else // Then, Waiting_Polar_Missions is not Empty
			{
				PolarMission* PM;
				Waiting_Polar_Missions.dequeue(PM);
				PM->Attach_Rover(rover);
				rover->UpdateMissions();
				rover->CalculateDuration(PM->getM_Duration(), PM->getT_Loc());
				PM->Update_Exd(); // Because of Private Inheritance 
				In_Execution_Polar_Missions.InsertEnd(PM);
			}
			// Update Rover Status and all its information 
			rover->set_Assignment_Day(today);
			rover->Toggle();


			Available_Rovers--;  //Initialize this counter 


			Waiting_Missions_Count--;
			In_Execution_Missions_Count++;
			In_Execution_Rovers.InsertEnd(rover);
		}

		//ozer: upadte waiting after not assigning

		if (!Waiting_Emergency_Missions.isEmpty() || !Waiting_Polar_Missions.isEmpty()) {
			PNode<EmergencyMission*>* eptr = Waiting_Emergency_Missions.get_FrontPtr();
			Node<PolarMission*>* pptr = Waiting_Polar_Missions.get_FrontPtr();
			while (eptr || pptr) {   //either of pointers is not null or both not null //Update all waiting 
				if (eptr) {
					eptr->getItem()->Update_WD();
					eptr = eptr->getNext();
				}
				if (pptr) {
					pptr->getItem()->Update_WD();
					pptr = pptr->getNext();
				}
			}
		}
		//4. 
		// Emergency Missions (In_Execution) -> Completed 

		/*
		* How to Know whether the mission completed or not ?
		*
		*/

		if (!In_Execution_Emergency_Missions.isEmpty())
		{

			L_Node<EmergencyMission*>* ptr;
			L_Node<EmergencyMission*>* Numby = new L_Node<EmergencyMission*>(nullptr);

			Numby->setNext(In_Execution_Emergency_Missions.getHead());  //oz: here is the problem exception thrown 
			ptr = Numby;
			Rovers* rover;

			while (ptr->getNext())
			{
				

				if (today == ptr->getNext()->getItem()->get_ExD() + ptr->getNext()->getItem()->get_FD())
				{
					rover = ptr->getNext()->getItem()->get_rover();
					// Update The Completed Mission 
					// Increment the Completion day 
					ptr->getNext()->getItem()->Update_CD();
					Completed_Missions.enqueue((Missions*)ptr->getNext()->getItem());
					// Update the Attached Rover 
					rover->Toggle();
					//rover->UpdateMissions();  // Decrease Missions by one 
					ptr->getNext()->getItem()->Attach_Rover(nullptr);


					// Remove from the In_Execution list   Do you need to update Mission ? ??? 
					// ptr->setNext(ptr->getNext()->getNext());
					if (ptr->getNext() == In_Execution_Emergency_Missions.getHead()) {
						In_Execution_Emergency_Missions.setHead(In_Execution_Emergency_Missions.getHead()->getNext());
					}
					else {
						ptr->setNext(ptr->getNext()->getNext());
					}
					In_Execution_Missions_Count--;
					
					Completed_Missions_Count++;
				}
					ptr = ptr->getNext(); // Contiue
			}
		}

		if (!In_Execution_Polar_Missions.isEmpty())
		{
			L_Node<PolarMission*>* ptr;

			L_Node<PolarMission*>* Numby = new L_Node<PolarMission*>(nullptr);

			Numby->setNext(In_Execution_Polar_Missions.getHead());
			ptr = Numby;
			Rovers* rover;

			while (ptr->getNext())
			{
				rover = ptr->getNext()->getItem()->get_rover();
				if (today == ptr->getNext()->getItem()->get_ExD() + ptr->getNext()->getItem()->get_FD())
				{

					// Update The Completed Mission 
					// Increment the Completion day 
					ptr->getNext()->getItem()->Update_CD();
					Completed_Missions.enqueue((Missions*)ptr->getNext()->getItem());
					// Update the Attached Rover 
					rover->Toggle();
					//rover->UpdateMissions();  // Decrease Missions by one 
					ptr->getNext()->getItem()->Attach_Rover(nullptr);
					// Remove from the In_Execution list   Do you need to update Mission ? ??? 

					if (ptr->getNext() == In_Execution_Polar_Missions.getHead()) {
						In_Execution_Polar_Missions.setHead(In_Execution_Polar_Missions.getHead()->getNext());
					}
					else {
						ptr->setNext(ptr->getNext()->getNext());
					}
					In_Execution_Missions_Count--;

					Completed_Missions_Count++;
				}
					ptr = ptr->getNext(); // Contiue
			}
		}
		// 6. Check the In_Execution Rovers 
		if (!In_Execution_Rovers.isEmpty())
		{
			L_Node<Rovers*>* ptr;

			L_Node<Rovers*>* Numby = new L_Node<Rovers*>(nullptr);
			Numby->setNext(In_Execution_Rovers.getHead());
			ptr = Numby;
			while (ptr->getNext())
			{
				Rovers* rover = ptr->getNext()->getItem();
				if (today - rover->get_Assignment_Day() == rover->get_JourneyTime()) // Execution is Done 
				{
					
					// Update Counters, // internal data
					if (rover->getMaxMissions()==0)
					{ // Go to Checkup NOOOWW
						if (dynamic_cast<PolarRovers*>(rover))
						{
							In_Checkup_Polar_Rovers.enqueue((PolarRovers*)rover);
							rover->set_CheckupStartingDay(today);
							rover->setMaxMissions(Polar_Missions_Before_Checkup);
						}
						else if (dynamic_cast<EmergencyRovers*>(rover))
						{
							In_Checkup_Emergency_Rovers.enqueue((EmergencyRovers*)rover);
							rover->set_CheckupStartingDay(today);
							rover->setMaxMissions(Emer_Missions_Before_Checkup);
						}
						In_Check_Up_Rovers++;
					}
					else
					{ // Otherwise, Go to available 
						if (dynamic_cast<PolarRovers*>(rover))
						{
							Available_Polar_Rovers.InsertEnd((PolarRovers*)rover);
						}
						else if (dynamic_cast<EmergencyRovers*>(rover))
						{
							Available_Emergency_Rovers.InsertEnd((EmergencyRovers*)rover);
						}
						Available_Rovers++;
					}
					// Remove ptr.next 

					if (ptr->getNext() == In_Execution_Rovers.getHead())
						In_Execution_Rovers.setHead(In_Execution_Rovers.getHead()->getNext());
					else
						ptr->setNext(ptr->getNext()->getNext());
					// UPdate internal data of Rover, Counters 

				}
					ptr = ptr->getNext();
				
			}
		}

		// After first day , go to displayMessage and see the results / statistics 
		if (MODE == Interactive || MODE == StepbyStep)
		 	if (MODE==Interactive) { Input_Interface->GetPress();
		     Output_Interface->PrintDay(this);
		}
		if (MODE==StepbyStep) {
			Sleep(5000); //pc : 5amsaya w afoo2
			Output_Interface->PrintDay(this);
		}
		
	}
	executed = true;


  SaveSimulation();  //will the save file anyways if it do prints or not 
  Output_Interface->PrintMsg("File Generated ... ");
  return;

}


/*
	*  	1. Increment Today
	*	2. Loop over EventList to check if there is an event to be executed
	*	3. Loop over the waiting Emergency and then waiting Polar to assign them to available rovers
	*   4. Loop over the In_Execution_Missions to move the completed to Completed_List [Loop over the whole list]    Decrement count of Avaialable_Missions
	*		Update the Associated_Rover
	*	5. Loop over the Checkup List to move the rovers who finished checkup duration to the available list again
	*	6. Loop over the In_Execution Rovers To know if they returned to The base after they finished they finished their missions
	* check if rovers reached number of durations 
	*	7.
	* 
	* 
	* Number of Missions completed by the rover 
	*/


inline void MarsStation::Update_Waiting_Missions() {			PNode<EmergencyMission*> *P = Waiting_Emergency_Missions.get_FrontPtr();		while (P) {			P->getItem()->Update_WD();			P = P->getNext(); 		}
}