#pragma once
#include<fstream>
using std::ofstream;
#include<string>
#include"../Rovers/Rovers.h"
#include"../Rovers/EmergencyRovers.h"
#include"../Rovers/MountainousRovers.h"
#include"../Rovers/PolarRovers.h"
class Missions {
protected:
	int D_formulation; // Formulation Day 
	int ID; // Mission ID 
	int T_Loc; //target_location
	int M_Duration; //Mission Duration 
	int signif; //significance 
	int CD;
	int ExD;
	int WD;
	Rovers* Associatedrover;
public : 
	//setters and getters 
	// why to pass AssociatedRover? we want to assign it later !
	Missions(int Dform, int mID, int loc, int dur, int sig, Rovers* attachedrover) :D_formulation(Dform), ID(mID), T_Loc(loc), M_Duration(dur), signif(sig), Associatedrover(attachedrover) {};

	virtual Rovers* get_rover() = 0; 
	/*virtual bool Attach_rover() const = 0;
	virtual void Save_Data(ofstream& outfile) const = 0;
	virtual void set_CD(int cd) = 0;
	virtual void set_Exd(int exd) = 0; 
	virtual void set_WD(int wd) = 0;
	virtual int get_ID() const = 0;
	virtual int get_CD() const =0;
	virtual int get_ExD() const =0;
	virtual int get_WD() ;
	virtual int get_FD() ;
	virtual int getT_Loc() ; 
	virtual int getM_Duration() ;
	virtual int get_significance() = 0;*/
	
	virtual ~Missions() {};
};

