#pragma once
class Rovers
{
protected:

    float speed; 

	int CheckupDuration;   

	int MaxMissions;


public:


	virtual float getSpeed() = 0;

	virtual  int CalculateDuration(int du, int TargLoca) = 0;

	virtual  void setMaxMissions(int max) = 0;

	virtual int getMaxMissions() = 0;

	virtual int UpdateMissions() = 0;
};
