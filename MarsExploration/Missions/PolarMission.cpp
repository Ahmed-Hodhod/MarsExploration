#include"PolarMission.h"


void PolarMission::Save_Data(ofstream& outfile)
{
	outfile << CD << ID << D_formulation << WD << ExD;
}

Rovers* PolarMission::get_rover()
{
		return Associatedrover;	
}

bool PolarMission::Attach_Rover(Rovers* Rptr)
{
	Associatedrover = Rptr; 
	if (dynamic_cast<PolarRovers*>(Rptr)) {  return true; }
	else { return false; }
}

int PolarMission::get_significance() const
{
	return signif;
}


void PolarMission::set_WD(int wd)
{
	WD = wd;
}

int PolarMission::get_ID() const
{
	return ID;
}

int PolarMission::get_WD() const
{
	return WD;
}

int PolarMission::get_CD() const
{
	return CD;
}

int PolarMission::get_FD() const
{
	return D_formulation;
}


int PolarMission::getT_Loc() const
{
	return T_Loc;
}

int PolarMission::getM_Duration() const
{
	return M_Duration;
}



void PolarMission::Update_CD()
{
	CD = WD + ExD + D_formulation;
}

void PolarMission::Update_WD()
{
	WD++;
}

void PolarMission::Print_Mission_Rover()
{
	std::cout << ID << " / " << get_rover()->getID() << "  ";
}

char PolarMission::get_type()
{
	return 'P';
}

int PolarMission::Update_Exd()
{
	int dummycalc = ceil(2.00 * T_Loc / (Associatedrover->getSpeed() * 25.00));
	ExD = (M_Duration + dummycalc);
	return ExD;
}

