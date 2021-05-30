#include "Input.h"


Modes Input::getMode()
{
	int c;
	cout << "choose a mode to enter " << endl;
	cout << "1- interactive \n" << "2-Step-By-Step\n" << "3-Silent\n";
	do {
		cin >> c;
		switch (c - 1) {
		case 0:
			return Modes::Interactive;
		case 1:
			return Modes::StepbyStep;
		case 2:
			return Modes::Silent;
		default:
			cout << "Wrong Choice ! Please choose again..." << endl;
		}
	} while (c > 3);
}

void Input::GetPress()
{
	char c;
	//cout << "Press any Button to continue ... " << endl;
	cin >> c;
	return;
}

string Input::Get_File_name()
{
	string filename;
	ifstream infile;
	cout << "Please enter file name in (.txt) format : " << endl;
	cin >> filename;
	infile.open(filename);
	while (infile.fail()) {
		cout << "File not found , Please try again" << endl;
		cin >> filename;
		infile.open(filename);
	}
	return filename;
}