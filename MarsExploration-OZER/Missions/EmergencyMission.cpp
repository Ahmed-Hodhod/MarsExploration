#include"EmergencyMission.h"


void EmergencyMission::Save_Data(ofstream& outfile)
{
	outfile << CD << ID << D_formulation << WD << ExD;
}

Rovers* EmergencyMission::get_rover()
{
	return Associatedrover;
}

bool EmergencyMission::Attach_Rover(Rovers* Rptr)
{
	
	if (dynamic_cast<EmergencyRovers*>(Rptr)) { return true; }
	else if (dynamic_cast<PolarRovers*>(Rptr)) { return true; }
	else { return false; }
}

int EmergencyMission::get_significance() const
{
	return signif;
}

void EmergencyMission::set_CD(int cd)
{
	CD = cd;
}

void EmergencyMission::set_Exd(int exd)
{
	ExD = exd;
}

void EmergencyMission::set_WD(int wd)
{
	WD = wd;
}

int EmergencyMission::get_ID() const
{
	return ID;
}

int EmergencyMission::get_WD() const
{
	return WD;
}

int EmergencyMission::get_CD() const
{
	return CD;
}

int EmergencyMission::get_FD() const
{
	return D_formulation;
}

int EmergencyMission::get_ED() const
{
	return ExD;
}

int EmergencyMission::getT_Loc() const
{
	return T_Loc;
}

int EmergencyMission::getM_Duration() const
{
	return M_Duration;
}
