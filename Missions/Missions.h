#pragma once


#ifndef MISSIONS_H
#define MISSIONS_H

class Rovers;
class Missions {
protected:
	int D_formulation; // Formulation Day 
	int ID; // Mission ID 
	int T_Loc; //target_location
	int M_Duration; //Mission Duration 
	int signif; //significance 
	Rovers* Associatedrover;
public : 
	//setters and getters 
	// why to pass AssociatedRover? we want to assign it later !
	Missions(int Dform, int mID, int loc, int dur, int sig, Rovers* attachedrover) :D_formulation(Dform), ID(mID), T_Loc(loc), M_Duration(dur), signif(sig), Associatedrover(attachedrover) {};

	
	virtual Rovers* get_rover() const; 
	virtual bool Attach_rover() const; 
	virtual int getT_Loc() const; 
    virtual int getM_Duration() const;
	virtual int get_significance() const = 0;
	
	virtual ~Missions() {};
};
#endif
