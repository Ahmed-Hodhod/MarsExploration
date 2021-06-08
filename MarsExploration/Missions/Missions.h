#pragma once
#include<fstream>
using std::ofstream;
#include<string>
#include"../Rovers/Rovers.h"
#include"../Rovers/EmergencyRovers.h"
#include"../Rovers/PolarRovers.h"
#include <iostream>
class Missions {
protected:
	int D_formulation; // Formulation Day 
	int ID; // Mission ID 
	int T_Loc; //target_location
	int M_Duration; //Mission Duration 
	int signif; //significance 
	int CD;  //Completion Day
	int ExD;  //Execution Time 
	int WD;   // Waiting Day 
	char type; //Mission Types 
	Rovers* Associatedrover;  //Assigned rover 
public: 
	//setters and getters 
	// why to pass AssociatedRover? we want to assign it later !
	Missions(int Dform, int mID, int loc, int dur, int sig, Rovers* attachedrover) :D_formulation(Dform), ID(mID), T_Loc(loc), M_Duration(dur), signif(sig), Associatedrover(attachedrover) {
		WD = 0;
		ExD = 0;   // we still don't know that 
		//CD = ExD + D_formulation;
	};

	virtual Rovers* get_rover() = 0; 
	virtual  bool Attach_Rover(Rovers*) = 0;
	//virtual void Calculate_CD() = 0;  OZ : Walahy hen7taghom 7atta lw hatsmeehom update
	virtual int Update_Exd() = 0; 
	//virtual void Update_WD(int wd) = 0;
	virtual char get_type()=0; // gets the type whether it's E or P // overriden in derived classes (Yeah I know that you know) 
	virtual int get_ID() const = 0;
	virtual int get_CD() { return CD;  };
	virtual int get_ExD() const { return ExD;  };
	virtual int get_WD() { return WD;  };
	virtual int get_FD() { return D_formulation; };
	virtual int getT_Loc() { return T_Loc; };
	virtual int getM_Duration() {
		return M_Duration; ;
	}

	
		virtual int get_significance() {
			return signif;
		};
	
	virtual ~Missions() {};
};

