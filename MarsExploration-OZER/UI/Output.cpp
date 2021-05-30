#include "Output.h"

Output::Output(const MarsStation* BSptr)
{
    BStationptr = BSptr;
}

Input* Output::getInput()
{
    return pIn;
}

void Output::PrintDay()
{
    const MarsStation* BSptr = Get_Pointer_to_Base_Station();
    
    //prints data of each day 
    return; 
}

void Output::PrintMsg(int s)
{
    cout << s << endl;
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
        const MarsStation* BSptr = Get_Pointer_to_Base_Station();
        cout << "Silent Mode " << endl;
        cout << "Simulation Starts ... " << endl;
        
    }
}

void Output::ShowStatistics()
{
    //displays average wait time and average execution time at the end 
}

const MarsStation* Output::Get_Pointer_to_Base_Station()
{
    return BStationptr;
}

Output::~Output()
{
}
