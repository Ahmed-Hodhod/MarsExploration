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
	if (dynamic_cast<PolarRovers*>(Rptr)) { return true; }
	else { return false; }
}

int PolarMission::get_significance() const
{
	return signif;
}

void PolarMission::set_CD(int cd)
{
	CD = cd;
}

void PolarMission::set_Exd(int exd)
{
	ExD = exd;
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

int PolarMission::get_ED() const
{
	return ExD;
}

int PolarMission::getT_Loc() const
{
	return T_Loc;
}

int PolarMission::getM_Duration() const
{
	return M_Duration;
}
