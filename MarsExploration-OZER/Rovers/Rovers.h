#pragma once
class Rovers
{
protected:

    float speed; 

	int CheckupDuration;   

	int MaxMissions;


public:
	Rovers(float spd, int checkdur, int Maxmission) :speed(spd), CheckupDuration(checkdur), MaxMissions(Maxmission) {}; //ozer did this

	virtual float getSpeed() = 0;

	virtual  int CalculateDuration(int du, int TargLoca) = 0;

	virtual  void setMaxMissions(int max) = 0;

	virtual int getCheckupDuration() = 0;    //ozer did this 

	virtual int getMaxMissions() = 0;

	virtual int UpdateMissions() = 0;
};
