#include "Input.h"

Input::Input()
{}

int Input::setMode()
{
	int c;
	cout << "choose a mode to enter " << endl;
	cout << "1- interactive \n" << "2-Step-By-Step\n" << "3-Silent\n";
	cin >> c;
	while (c > 3) {
		cout << "Wrong Choice ! Please choose again..." << endl;
		cin >> c;
	}
	return c;
}

Modes Input::getMode(int c)
{

	switch (c - 1) {
	case 0:
		return Modes::Interactive;
	case 1:
		return Modes::StepbyStep;
	case 2:
		return Modes::Silent;
	}
}

void Input::GetPress()
{
	char c;
	cout << "Press any Button to show statistics ... " << endl;
	cin >> c;
	return;
}

string Input::Get_File_name(char Str)
{
	if (Str == 'L') {
		//we are loading 
		string filename;
		ifstream infile;
		cout << "Please enter file in .txt format  : " << endl;
		cin >> filename;
		infile.open(filename);
		while (infile.fail()) {
			cout << "File not found , Please try again" << endl;
			cin >> filename;
			infile.open(filename);
		}
		return filename;
	}
	else {
		string filename;
		cout << "Please enter file name to save into  : " << endl;
		cin >> filename;
		return (filename);
	}
}

Input::~Input()
{
}


