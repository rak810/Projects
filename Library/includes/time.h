#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


class Date
{
private:
	int month;
	int date;
	int year;
public:
	Date();
	Date(int dt, int mn, int yr);
	Date(string dt);
	string CurrentDate();
	string DueDate(int dmon);
	int DueCalc(Date dt); //incomplete
	string DatetoString();
	Date operator + (Date dt);
	Date operator - (Date dt);
	bool operator > (Date dt);

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

Date::Date(int dt, int mn, int yr)
{
	date = dt;
	month = mn;
	year = yr;
}

Date::Date(string dt)
{

  	std::vector<string> v;
  	string temp;
    
	for (int i = 0; i < dt.length(); ++i)
	{
		if(dt[i] != '-')
		{
            temp += dt[i];
		}
		else 
		{
		    v.push_back(temp);
		    temp = "";
		    
		}
	}
	v.push_back(temp);

	date = stoi(v[0]);
	month = stoi(v[1]);
	year = stoi(v[2]);


}

Date Date::operator + (Date dt)
{
	Date temp(0, 0, 0);
	int x = 30;
	temp.date = this->date + dt.date;
	temp.month = this->month + dt.month;
	temp.year = this->year + dt.year;
	if ((dt.year % 4 == 0) && (dt.year % 100 != 0) || (dt.year % 400 == 0) && dt.year != 0)
	{	
		x = 28;
	}

	if(temp.date%x > 0)
	{
		temp.date = temp.date%x;
		temp.month += temp.date/x;
	}
	if(temp.month%12 > 0)
	{
		temp.month = temp.month%12;
		temp.year += temp.month/12;
	}
	return(temp);
}

Date Date::operator - (Date dt)
{
	Date temp;
	int x = 30;
	if ((dt.year % 4 == 0) && (dt.year % 100 != 0) || (dt.year % 400 == 0) && dt.year != 0)
	{	
		x = 29;
	}

	if(this->date < dt.date)
	{
		temp.date = (this->date + x) - dt.date;
		dt.month++;
	}
	else
	{
		temp.date = this->date - dt.date;
	}
	if(this->month < dt.month)
	{
		temp.month = (this->month + 12) - dt.month;
		dt.year++;
	}
	else
	{
		temp.month = this->month - dt.month;
	}
	temp.year = this->year - dt.year;
	return temp;
}

bool Date::operator > (Date dt)
{
	if(this->date > dt.date && this -> month > dt.month && this -> year > dt.year)
	{
		return true;
	}
	else if (this->date > dt.date && this -> month > dt.month && this -> year == dt.year)
	{
		return true;
	}
	else if(this->date > dt.date && this -> month == dt.month && this -> year > dt.year)
	{
		return true;
	}
	else if(this->date == dt.date && this -> month > dt.month && this -> year > dt.year)
	{
		return true;
	}
	else if(this -> month > dt.month && this -> year > dt.year)
	{
		return true;
	}
	else if(this->date == dt.date && this -> month > dt.month && this -> year == dt.year)
	{
		return true;
	}
	else if(this->date > dt.date && this -> month == dt.month && this -> year == dt.year)
	{
		return true;
	}
	else if(this -> year > dt.year)
	{
		return true;
	}
	else
		return false;
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

int Date :: DueCalc(Date dt)
{
	int days = dt.date+dt.month*30+dt.year*365;
	return days*2;
}

string Date::DatetoString()
{
	string str_dt = to_string(date);
	string str_mon = to_string(month);
	string str_yr = to_string(year);
	string str_date = str_dt + "-" + str_mon + "-" + str_yr;
	return(str_date);
}

