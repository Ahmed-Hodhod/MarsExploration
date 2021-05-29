#include "Formulate_Event.h"


Formulate_Event::Formulate_Event(int ED, int ID, int Type, int Duration, int Tar_Loc, int SIG):Events(ED, ID)
{
	this->Type = Type; 
	this->Duration = Duration; 
	this->Tar_Loc = Tar_Loc; 
	this->SIG = SIG; 
}


void Formulate_Event::Execute()
{
	if (Type == 'p')
	{
		//Polar_Mission* mission = new Polar_Missions(); R
		return; 
	}
	if (Type == 'e')
	{
		//Emergency Mission* mission = new Emergency_Misions();
		return;
	}
}
