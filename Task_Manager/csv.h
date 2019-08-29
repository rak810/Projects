#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<iterator>
#include<string>
#include<cstdio>

using namespace std;

class CSV
{
	string filename;
	string delimiter;
	int linescount;
public:
	CSV(string file, string delm = ",")
	{
		filename = file;
		delimiter = delm;
		linescount = 0;
	}

	template<typename T> void AddDatainRow(T first, T last)
	{
		fstream fp;
		fp.open(filename, ios::in | ios::out | ios::app);

		for( ; first != last; )
		{
			fp << *first;
			if(++first != last)
			{
				fp << delimiter;
			}
		}
		fp << endl;
		linescount++;
		fp.close();
	}

	void ReadDatainRow()
	{
		string str,word;
		vector<string> row;
		ifstream fp;
		fp.open(filename);
		while(getline(fp, str))
		{
			stringstream s(str);
			while(getline(s,word, ','))
			{
				row.push_back(word);
			}
			
			cout << endl;
		}
		fp.close();
	}
	int CountRow()
	{
		string str;
		ifstream fp;
		fp.open(filename);
		int lines = 0;
		while(getline(fp, str))
		{
			lines++;
		}
		fp.close();
		return(lines);
	}
	void UpdateRow(vector<string> up)
	{
		char fln[filename.length()+1];
		for (int i = 0; i < sizeof(fln); ++i)
		{
			fln[i] = filename[i];
		}

		CSV update("Updated.csv");
		string str,word;
		vector<string> row;
		ifstream fp;
		fp.open(filename);
		while(getline(fp, str))
		{
			stringstream s(str);
			while(getline(s,word, ','))
			{
				row.push_back(word);
			}
			if(row[0]==up[0])
			{
				update.AddDatainRow(up.begin(), up.end());
			}
			else
			{
				update.AddDatainRow(row.begin(), row.end());
			}
			row.clear();
		}
		fp.close();
		remove(fln);
		rename("Updated.csv", fln);
	}

	void DeleteRow(string data)
	{
		char fln[filename.length()+1];
		for (int i = 0; i < sizeof(fln); ++i)
		{
			fln[i] = filename[i];
		}

		CSV update("Updated.csv");
		string str,word;
		vector<string> row;
		ifstream fp;
		fp.open(filename);
		while(getline(fp, str))
		{
			stringstream s(str);
			while(getline(s,word, ','))
			{
				row.push_back(word);
			}
			if(row[0]!= data)
			{
				update.AddDatainRow(row.begin(), row.end());
			}

			row.clear();
		}
		fp.close();
		remove(fln);
		rename("Updated.csv", fln);
	}
};	
