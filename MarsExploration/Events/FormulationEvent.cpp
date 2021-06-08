#include "FormulationEvent.h"


FormulationEvent::FormulationEvent(char type,int ED, int ID, int Tar_Loc, int Duration, int SIG, 
	LinkedQueue<PolarMission*> &WPM, PQueue<EmergencyMission*>& WEM)
	: Events(ED, ID)
{
	this->Type = type;
	this->Duration = Duration;
	this->Tar_Loc = Tar_Loc;
	this->SIG = SIG;

	this->WEM =&WEM; 
	this->WPM = &WPM;

}

void FormulationEvent::Execute()
{
	EmergencyMission* mission; 
	if (Type == 'P') // P for Polar 
	{
		PolarMission* mission = new PolarMission(ED, ID, Tar_Loc, Duration, SIG,nullptr);
		
		WPM->enqueue(mission); 
	}
	if (Type == 'E') // E for Emergency
	{
		EmergencyMission* mission = new EmergencyMission(ED, ID, Tar_Loc, Duration, SIG, nullptr);
		// Let the Emergency Mission to update its Sig THrough CalcSIG ( call it in GetSiG () )

		WEM->enqueue(mission, mission->Calculate_New_pri()); 
	}
}

char FormulationEvent::get_Type() { return Type; }
int FormulationEvent::get_ED()
{
	return ED;
}
int FormulationEvent::get_Duration() { return Duration; }

int FormulationEvent::get_TarLoc() { return Tar_Loc; }
int FormulationEvent::get_SIG() { return SIG; }
