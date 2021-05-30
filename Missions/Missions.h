#pragma once


#ifndef MISSIONS_H
#define MISSIONS_H

class Rovers;
class Missions {
protected:
	int D_formulation;
	int ID;
	int T_Loc; //target_location
	int M_Duration; //Mission Duration 
	int signif; //significance 
	Rovers* Associatedrover;
public : 
	//setters and getters 
	Missions(int Dform, int mID, int loc, int dur, int sig, Rovers* attachedrover) :D_formulation(Dform), ID(mID), T_Loc(loc), M_Duration(dur), signif(sig), Associatedrover(attachedrover) {};

	virtual Rovers* get_rover() = 0;
	virtual int getT_Loc() const = 0;
    virtual int getM_Duration() const = 0;
	virtual int get_significance() const = 0;
	
	~Missions() {};
};
#endif
