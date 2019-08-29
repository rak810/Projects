#include<iostream>
#include<cstdlib>
#include<string>
#include<iomanip>
#include<vector>
#include "csv.h"

using namespace std;


class Task
{
	string sl;
	string name;
	string st_date;
	string end_date;
public:
	void GetData();
	void AddTasks();
	void SeeTasks(string file);
	void RemoveTasks(string file);
	void choice(string fl);
	//friend void initscr();

};

void Task :: GetData()
{
	string nm, st, dt;
	cin.ignore();
	cout << "ENTER THE TASK NAME : ";
	getline(cin, nm);
	cout << "ENTER THE TASK STARTING DATE : ";
	getline(cin, st);
	cout << "ENTER THE TASK DUE DATE : ";
	getline(cin, dt);
	name = nm;
	st_date = st;
	end_date = dt; 
}

void Task :: AddTasks()
{
	initscr();
	int ln, n;
	string s;
	std::vector<string> v;
	cout << setw(28) << "HOW MANY TASK YOU WANT TO ADD : ";
	cin >> n;
	CSV TaskAdder("tasks.csv");

	for (int i = 0; i < n; ++i)
	{
		ln = 101 + TaskAdder.CountRow();
		string s =  to_string(ln+i);
		sl = s;
		GetData();
		v = {sl, name, st_date, end_date};
		TaskAdder.AddDatainRow(v.begin(), v.end()); 
		v.clear();
	}
}

void Task :: SeeTasks(string file)
{
	initscr();
	cout << "_____________________________________________________________" << endl;
	cout << "|" << "SL NO" << setw(5) << "|" << "TASK" << setw(15) << "|" << "ST DATE" << setw(5) << "|" << "DUE DATE" << setw(5) << "|" << endl;
	cout << "_____________________________________________________________" << endl;
	
	string line, word;
	vector<string> row;

	ifstream fp;
	fp.open(file);

	while(getline(fp, line))
	{
		stringstream s(line);
		while(getline(s,word, ','))
		{
			row.push_back(word);
		}
		for (int i = 0; i < 4; ++i)
		{
			cout << row[i] << setw(5) << "|";
		}
		cout << endl;
		row.clear();
	}
	fp.close();
}

void Task :: RemoveTasks(string file)
{
	SeeTasks(file);
	cout << "ENTER THE NUMBER OF TASKS YOU WANT TO DELETE : ";
	int n;
	cin >> n;
	std::vector<string> v;
	string s;
	CSV remover("tasks.csv");
	cout << "ENTER THE SERIAL NUMBERS :";
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		remover.DeleteRow(s);
	}
}


void Task :: choice(string fl)
{
	int ch;
	cout << "\t\t\t" << "CHOOSE AN OPTION : " ;
	cin >> ch;
	if(ch == 1)
	{
		AddTasks();
	}
	else if(ch == 2)
	{
		SeeTasks(fl);
	}
	else if(ch == 3)
	{
		RemoveTasks(fl);
	}
	else
	{
		cout << "\t\t\t" << "ERROR : INVALID CHOICE ! " << endl;
		choice(fl);
	}
}

