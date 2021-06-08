#include "Output.h"
#include"../MarsStation.h"
Output::Output(MarsStation* BSptr)
{
    BStationptr = BSptr;
   // pIn = BStationptr->Get_Input_Interface();
}

/*Input* Output::getInput()
{
    return pIn;
}

void Output::setInput(Input* Input)
{
    pIn = Input;
}
*/

void Output::PrintDay(MarsStation* msptr)
{
    BStationptr = msptr;
    //Alert : Incoming too many pointers , because they are different lists.  Space complexity O(infinity) ;)
    cout << "Current Day : " << BStationptr->today << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    //Waiting Missions 
    cout << BStationptr->Waiting_Missions_Count << "Waiting Missions ";
    cout << "[ ";
    PNode<EmergencyMission*>* PWEPtr = BStationptr->Waiting_Emergency_Missions.get_FrontPtr();
    while (PWEPtr) {
        if (PWEPtr->getNext())
            cout << PWEPtr->getItem()->get_ID() << " ,";
        else {
            cout << PWEPtr->getItem()->get_ID() << "  ";
        }
        PWEPtr = PWEPtr->getNext();
    }
    cout << " ]";

    /////////////////////////////////////////////////////////////////////////////////////
    cout << "( ";
    Node<PolarMission*>* PWPtr = BStationptr->Waiting_Polar_Missions.get_FrontPtr();
    while (PWPtr) {
        if (PWPtr->getNext())
            cout << PWPtr->getItem()->get_ID() << " ,";
        else {
            cout << PWPtr->getItem()->get_ID() << "  ";
        }
        PWPtr = PWPtr->getNext();
    }
    cout << " )";
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    //Inexecution_Missions / Rovers
    cout << BStationptr->In_Execution_Missions_Count << "In Execution  Missions / Rovers ";
    L_Node<EmergencyMission*>* PEexecPtr = BStationptr->In_Execution_Emergency_Missions.getHead();
    cout << "[ ";
    while (PEexecPtr) {
        if (PEexecPtr->getNext()) {
            PEexecPtr->getItem()->Print_Mission_Rover();
            cout << " ,";
        }
        else {
            PEexecPtr->getItem()->Print_Mission_Rover();
            cout << "  ";
        }
        PEexecPtr = PEexecPtr->getNext();
    }
    cout << "] ";
    //////////////////////////////////////////////////////////////////////////
    L_Node<PolarMission*>* PPexectr = BStationptr->In_Execution_Polar_Missions.getHead();
    cout << "(  ";
    while (PPexectr) {
        if (PPexectr->getNext()) {
            PPexectr->getItem()->Print_Mission_Rover();
            cout << " ,";
        }
        else {
            PPexectr->getItem()->Print_Mission_Rover();
            cout << "  ";
        }
        PPexectr = PPexectr->getNext();
    }
    cout << ") ";
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    //////////////////////////////////////////////////////////////////////
    //Available Rovers 
    L_Node<EmergencyRovers*>* PassEPtr = BStationptr->Available_Emergency_Rovers.getHead();
    cout << BStationptr->Available_Rovers << "Available Rovers ";
    cout << "[ ";
    while (PassEPtr) {
        if (PassEPtr->getNext()) {
            cout << PassEPtr->getItem()->getID();
            cout << " ,";
        }
        else {
            cout << PassEPtr->getItem()->getID();
            cout << "  ";
        }
        PassEPtr = PassEPtr->getNext();
    }
    cout << "] ";
    ////////////////////////////////////////////////////////////////////////////
    L_Node<PolarRovers*>* PassAPtr = BStationptr->Available_Polar_Rovers.getHead();
    cout << "(";
    while (PassAPtr) {
        if (PassAPtr->getNext()) {
            cout << PassAPtr->getItem()->getID();
            cout << " ,";
        }
        else {
            cout << PassAPtr->getItem()->getID();
            cout << "  ";
        }
        PassAPtr = PassAPtr->getNext();
    }
    cout << ") ";
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    //In_Checkup_Rovers
    Node<EmergencyRovers*>* PassCEPtr = BStationptr->In_Checkup_Emergency_Rovers.get_FrontPtr();
    cout << BStationptr->In_Check_Up_Rovers << "In check up  Rovers ";
    cout << "[ ";
    while (PassCEPtr) {
        if (PassCEPtr->getNext()) {
            cout << PassCEPtr->getItem()->getID();
            cout << " ,";
        }
        else {
            cout << PassCEPtr->getItem()->getID();
            cout << "  ";
        }
        PassCEPtr = PassCEPtr->getNext();
    }
    cout << "] ";
    /////////////////////////////////////////////////////////////////////////////////////
    Node<PolarRovers*>* PassPPtr = BStationptr->In_Checkup_Polar_Rovers.get_FrontPtr();
    cout << "( ";
    while (PassPPtr) {
        if (PassPPtr->getNext()) {
            cout << PassPPtr->getItem()->getID();
            cout << " ,";
        }
        else {
            cout << PassPPtr->getItem()->getID();
            cout << "  ";
        }
        PassPPtr = PassPPtr->getNext();
    }
    cout << ") ";
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    //Completed Missions : This list has stolen my whole life because it contains all missions with their types unlike the above 
    cout << BStationptr->Completed_Missions_Count << "Completed Missions ";
    Node<Missions*>* PCEPtr = BStationptr->Completed_Missions.get_FrontPtr();
    LinkedList<int> CPM_IDs , CEM_IDs; //completed_polar and emergency missions IDs , this will help displaying them 
    while (PCEPtr) {
        if (dynamic_cast<EmergencyMission*>(PCEPtr->getItem())) {
            CEM_IDs.InsertEnd(PCEPtr->getItem()->get_ID());  //pass its ID to the emergency ids linked list
        }
        else if(dynamic_cast<PolarMission*>(PCEPtr->getItem())){
            CPM_IDs.InsertEnd(PCEPtr->getItem()->get_ID());  //pass its ID to the polar ids linked list 
        }
        PCEPtr = PCEPtr->getNext();
    }
    cout << "[ ";
    L_Node<int> * traversal = CEM_IDs.getHead();
    while (traversal)
    {
        if (traversal->getNext()) {
            cout << traversal->getItem() << ", ";
        }
        else {
            cout << traversal->getItem() << "  ";
        }
        traversal = traversal->getNext();
    }
    cout << "  ]";
    //polar//
    traversal = CPM_IDs.getHead();
    cout << "(  ";
    while (traversal)
    {
        if (traversal->getNext()) {
            cout << traversal->getItem() << ", ";
        }
        else {
            cout << traversal->getItem() << "  ";
        }
        traversal = traversal->getNext();
    }
    cout << "  )";
    cout << endl;
    //oz commented : supposed to be a deallocation; well,  the compiler didn't mind it , wouldn't you ? 
    CPM_IDs.~LinkedList();
    CEM_IDs.~LinkedList();
    delete traversal;
}



    void Output::PrintMsg(string s)
    {
        cout << s;
        cout << endl;
    }

    /*void Output::DisplayMessage(Modes AppMode)
    {
        
    //depends on what mode 
    if (AppMode == Interactive) {
        PrintDay();
    }
    else if (AppMode == StepbyStep) {
        Sleep(5000);  // 5msaya w hafo2 
        PrintDay();
    }
    else {
        PrintMsg("Silent Mode ");
        PrintMsg("Simulation Starts ... ");
    }
}*/


/*MarsStation* Output::Get_Pointer_to_Base_Station()
{
    return BStationptr;
}*/

Output::~Output()
{
}
