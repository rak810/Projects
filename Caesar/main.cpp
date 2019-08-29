#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>


using namespace std;

std::map<char, int> alp;

std::vector<string> splitString(string s)
{
	std::vector<string> v;
	string temp;
	for(int i = 0; i < s.size(); i++)
	{
		
		if(s[i] != ' ')
		{
			temp += s[i];
		}
		else 
		{
			v.push_back(temp);
			temp = "";
		}
	}
	v.push_back(temp);
	
	return v;
}


void mapInsert()
{
	char c = 'a';
	int i = 1;
	for(i = 1; i <=26; i++)
	{
		alp.insert(pair<char,int>(c,i));
		c++;
	}
}

char searchMap(int val)
{
	char c;
	for(auto i = alp.begin(); i != alp.end(); i++)
	{
		if(i->second == val)
		{
			c = i->first;
			break;
		}
	}
	return c;
}

std::vector<string> caesarCypher(string s, int k)
{
	std::vector<string> v = splitString(s);
	std::vector<string> tmp;
	string temp;
	for (int i = 0; i < v.size(); ++i)
	{
		for(int j = 0; j < v[i].size(); j++)
		{
			int val = (alp[v[i][j]]+k);
			if(val > 26)
			{
				val = (alp[v[i][j]]+k)%26;
			}
			temp += searchMap(val);
		}
		tmp.push_back(temp);
		temp = "";
	}
	return tmp;
}

int main()
{
	string s;
	int key;

	cout << "Enter A String : ";
	getline(cin, s);
	cout << "Enter the key : ";
	cin >> key;

	mapInsert();
	std::vector<string> v = caesarCypher(s, key);
	cout << "Encrypted/Decrypted string is : " ;
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

}