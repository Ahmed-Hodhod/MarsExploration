#pragma once
#ifndef _EVENTS_H
#define _EVENTS_H
class Events {
	int ED;
	int ID; 
public: 
	virtual void Execute() = 0;
};
#endif