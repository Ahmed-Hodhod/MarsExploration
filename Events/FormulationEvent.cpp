#include "FormulationEvent.h"
#include "../Missions/Missions.h"
#include "../Missions/PolarMission.h"
#include "../Missions/EmergencyMission.h"


FormulationEvent::FormulationEvent(int ED, int ID, int Type, int Duration, int Tar_Loc, int SIG) :Events(ED, ID)
{
	this->Type = Type;
	this->Duration = Duration;
	this->Tar_Loc = Tar_Loc;
	this->SIG = SIG;
}


void FormulationEvent::Execute()
{
	if (Type == 'P') // P for Polar 
	{
		PolarMission* mission = new PolarMission(ED, ID, Tar_Loc, Duration, SIG,nullptr);

		// we need an object of MarsStation to reach the addtomisionslist function 

	}
	if (Type == 'E') // E for Emergency
	{
		//Emergency Mission* mission = new Emergency_Misions();
		return;
	}
}
char FormulationEvent::get_Type() { return Type; }
int FormulationEvent::get_Duration() { return Duration; }

int FormulationEvent::get_TarLoc() { return Tar_Loc; }
int FormulationEvent::get_SIG() { return SIG; }
