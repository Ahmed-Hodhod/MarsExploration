#include"EmergencyMission.h"

Rovers* EmergencyMission::get_rover()
{
	if (Associatedrover)
		return Associatedrover;
	else
		return nullptr; 
}

bool EmergencyMission::Attach_Rover(Rovers* Rptr)
{
	Associatedrover = Rptr;
	if (dynamic_cast<EmergencyRovers*>(Rptr)) { return true; }
	else if (dynamic_cast<PolarRovers*>(Rptr)) { return true; }
	else { return false; }
}


int EmergencyMission::get_significance() const
{
	return signif;
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



int EmergencyMission::getT_Loc() const
{
	return T_Loc;
}

int EmergencyMission::getM_Duration() const
{
	return M_Duration;
}


void EmergencyMission::Update_CD()
{
	CD = ExD + WD + D_formulation;
}


void EmergencyMission::Update_WD()
{
	WD++;
}

int EmergencyMission::Calculate_New_pri()
{
	//explaination , the most significant is the one that takes higher time in our POV 
	//it may sound trivial , but logic 
	//If you've been sent on a mission to Sinai with significance 8 for example and the duration would be like 10 days 
	//Doesn't it make it sensible that this mission is kinda important ? 
	// Credits to Peter Memi and El-Ekhtyar series ;P 

	signif = signif * (M_Duration); // To be modified later 
	return signif;
}

void EmergencyMission::Print_Mission_Rover()
{
	// yeah I had no other option , I'm sorry 
	std::cout << ID << " / " << get_rover()->getID() << "  ";
}

char EmergencyMission::get_type()
{
	return 'E';
}

int  EmergencyMission::Update_Exd()
{
	int dummycalc = ceil(2.00 * T_Loc / (Associatedrover->getSpeed() * 25.00)); 
	ExD = (M_Duration + dummycalc);
	return ExD;
}