#pragma once
#include"Events.h"
#include"../Missions/Missions.h"

class FormulationEvent :
    private Events
{
    Events* Eptr;
    Missions* Mptr;
};

