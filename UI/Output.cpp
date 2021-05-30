#include "Output.h"

Input* Output::getInput()
{
    return pIn;
}

void Output::PrintDay()
{
    //prints data of each day 
    return; 
}

void Output::printRovers()
{
    return;
    //merge all rovers and print them 
}

void Output::printMissions()
{
    //merge all missions and print them 
    return; 
}

void Output::DisplayMessage()
{
    //depends on what mode 
    if (pIn->getMode() == Interactive) {
        pIn->GetPress();
        
    }
    else if (pIn->getMode() == StepbyStep) {
        
    }
    else {
        cout << "Silent Mode " << endl;
        cout << "Simulation Starts ... " << endl;
    }
}

void Output::ShowStatistics()
{
    //displays average wait time and average execution time at the end 
}
