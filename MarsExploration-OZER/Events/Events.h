#pragma once
#ifndef _EVENTS_H
#define _EVENTS_H
class Events {
protected:
	int ED;
	int ID; 
public: 
	Events(int ED, int ID) :ED(ED), ID(ID) {};
	virtual void Execute() = 0;
	virtual ~Events(); 
};
#endif