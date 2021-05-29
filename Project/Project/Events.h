#pragma once
class Events
{
private : 
	int ED; // Event Day 
	int ID; // Mission ID 
public:
	Events(int ED,int ID) : ED(ED), ID(ID); 
	virtual void Execute() = 0; 
	virtual ~Events(); 
};

