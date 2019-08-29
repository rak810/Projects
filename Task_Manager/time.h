#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<vector>

using namespace std;


class Date
{
private:
	int month;
	int date;
	int year;
public:
	Date();
	string CurrentDate();
	string DueDate(int dmon);
	int DueCalc(string issue, string due); //incomplete
	~Date() {}
};

Date :: Date()
{
	const int BASE_YEAR = 1900;
	time_t timer = time(0);
	tm *ltime;
	ltime = localtime(&timer);
	date = ltime->tm_mday;
	month = ltime->tm_mon + 1;
	year = ltime->tm_year + BASE_YEAR;
}
string Date :: CurrentDate()
{
	string str_dt = to_string(date);
	string str_mon = to_string(month);
	string str_yr = to_string(year);
	string str_date = str_dt + "-" + str_mon + "-" + str_yr;
	return(str_date);
}

string Date :: DueDate(int dmon)
{
	const int dt = date+1;
	int mn;
	mn = month + dmon;
	string due_dt = to_string(dt);
	string due_mon = to_string(mn);
	string due_yr = to_string(year);
	string due_date = due_dt + "-" + due_mon + "-" + due_yr;
	return(due_date);
}

int Date :: DueCalc(string issue, string due)
{
	std::vector<string> iss;
	std::vector<string> du;
	string ts = "";
	for (int i = 0; i < issue.length(); ++i)
	{

		if(issue[i] != '-')
		{
			ts = ts+issue[i];
		}
		else
		{
			iss.push_back(ts);
			ts = "";
		}
		
	}
}
