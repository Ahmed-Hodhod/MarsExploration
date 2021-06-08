#pragma once
#include <iostream>

class Rovers
{
protected:

    int speed; 

	int Checkup_Starting_Day;   

	bool Associated; 

	int MaxMissions;

	int Return_Time;  //oz

	int ID;     //ozer
	
	int JourneyTime; 
	
	int Assignment_Day;  // 


public:
	Rovers(int spd, int CSD, int Maxmission, int id) :speed(spd), Checkup_Starting_Day(CSD), MaxMissions(Maxmission), ID(id) { Associated = false;
	
	Assignment_Day = 0; 
	JourneyTime = 0; 
	}; //ozer did this

	virtual int get_Assignment_Day() { return Assignment_Day;  };
	virtual void set_Assignment_Day(int d) {  Assignment_Day = d;  };

	virtual int getSpeed() { return speed;  };

	virtual void Toggle() = 0;

	virtual bool getStat() = 0;

	virtual int getID() = 0; 

	virtual void CalculateDuration(int Duration, int TargetLocation)
	{
		JourneyTime = ceil( 2.00 * TargetLocation / (getSpeed()*  25.00 ) + Duration );
	}
	virtual int get_JourneyTime()
	{
		return JourneyTime;
	}


	virtual int get_CheckupStartingDay() {
		return Checkup_Starting_Day; 
	}

	virtual void set_CheckupStartingDay(int d) { Checkup_Starting_Day = d; }

	virtual  void setMaxMissions(int max) {
		MaxMissions = max; 
	};


	virtual int get_Return_time(int Tarloc) = 0;  //oz

	virtual int getMaxMissions() = 0;

	virtual int UpdateMissions() = 0;

	


};
