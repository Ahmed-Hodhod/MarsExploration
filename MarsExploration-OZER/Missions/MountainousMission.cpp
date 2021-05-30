#include"MountainousMission.h"


void MountainousMission::Save_Data(ofstream& outfile)
{
	outfile << CD << ID << D_formulation << WD << ExD;
}

Rovers* MountainousMission::get_rover()
{
	return Associatedrover;
}

bool MountainousMission::Attach_Rover(Rovers* Rptr)
{
	if (dynamic_cast<MountainousRovers*>(Rptr)) { return true; }
	else if (dynamic_cast<EmergencyRovers*>(Rptr)) { return true; }
	else { return false; }
}

int MountainousMission::get_significance() const
{
	return signif;
}

void MountainousMission::set_CD(int cd)
{
	CD = cd;
}

void MountainousMission::set_Exd(int exd)
{
	ExD = exd;
}

void MountainousMission::set_WD(int wd)
{
	WD = wd;
}

int MountainousMission::get_ID() const
{
	return ID;
}

int MountainousMission::get_WD() const
{
	return WD;
}

int MountainousMission::get_CD() const
{
	return CD;
}

int MountainousMission::get_FD() const
{
	return D_formulation;
}

int MountainousMission::get_ED() const
{
	return ExD;
}

int MountainousMission::getT_Loc() const
{
	return T_Loc;
}

int MountainousMission::getM_Duration() const
{
	return M_Duration;
}
