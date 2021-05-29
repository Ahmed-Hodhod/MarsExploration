#include "Events.h"


Formulate_Event::Formulate_Event(int ED, int ID, int Type, int Duration, int Tar_Loc, int SIG):Events(ED, ID)
,Type(Type), Duration(Duration), Tar_Loc(Tar_Loc)
{
}

void EventFormulation::Execute()
{
	if (TYP == 'p')
	{
		Polar_Mission* mission = new Polar_Missions();
	}
	if (TYP == 'e')
	{
		Emergency Mission* mission = new Emergency_Misions();
	}
}
