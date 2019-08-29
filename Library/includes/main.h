#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<set>
#include<iterator>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#define clearscr() printf("\033[H\033[J")
#define initscr() {\
					clearscr();\
					cout << "\t\t\t LIBRARY MANAGEMENT SYSTEM" << endl;\
					cout << "\t\t\t----------------------------" << endl;\
					cout << endl;\
				}
#include "csv.h"
#include "time.h"
#include "book.h"
#include "admin.h"
#include "student.h"


Admin adm;
Student st;

using namespace std;



void init()
{

}
void prompt()
{
	int opt;
	cout << "Enter a option : " ;
	cin >> opt;
	cout << endl;
	if(opt == 1)
	{
		st.Login("Students.csv");
	}
	else if(opt == 2)
	{
		adm.adminLogin();
	}
	else if(opt == 3)
	{
		st.Registration();
	}
	else
	{
		cout << "Invalid option choice" << endl;
		cout << "Again ";
		prompt();
	}
}
int MainLogin()
{
	initscr();
	while(1)
	{
		cout << "\t\t\t 1 - Student Login" << endl;
		cout << "\t\t\t 2 - Admin Login" << endl;
		cout << "\t\t\t 3 - Student Registration" << endl;
		prompt();
	}
}