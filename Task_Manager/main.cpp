#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<iomanip>
#include<fstream>
#define clearscr() printf("\033[H\033[J")
#define initscr() {\
					clearscr();\
					cout << "\t\t\t" << "======================" << endl;\
					cout << "\t\t\t" << "\tTASK.IO" << endl;\
					cout << "\t\t\t" << "======================" << endl;\
				}

#include "task.h"
using namespace std;


/*void init()
{
	clear();
	cout << "\t\t\t" << "======================" << endl;
	cout << "\t\t\t" << "\tTASK.IO" << endl;
	cout << "\t\t\t" << "======================" << endl;
}*/

void interface()
{
	initscr();
	cout << "\t\t" << "WELCOME TO TERMINAL TASK MANAGER TASK.IO!" << endl;
	cout << "\t\t\t\t" << "------" << endl;
	cout << "\t\t\t\t " << "MENU" << endl;
	cout<< setw(45)<< " ------------------ " << endl;
	cout<< setw(28)<< " 1" << " ADD NEW TASK" << endl;
	cout<< setw(28)<< " 2" << " SEE TASKS" << endl;
	cout<< setw(28)<< " 3" << " REMOVE A TASK" << endl;
}



int main()
{
	interface();
	Task ts;
	ts.choice("tasks.csv");

}