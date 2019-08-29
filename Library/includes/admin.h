using namespace std;

class Admin : public Book
{
	string name;
	string pass;
public:
	Admin();
	void adminLogin();
	void adminPrompt();
	void deleteUser(string roll);
	
};

Admin :: Admin()
{
	name = "ADMIN";
	pass = "Admin";
}

void Admin::adminPrompt()
{
		cout << "LOGGED IN AS ADMIN!" << endl;
		cout << endl;
		cout << "1 - Add New Books" << endl;
		cout << "2 - Delete books" << endl;
		cout << "3 - Update Returned Books" << endl;
		cout << "4 - Delete A User" << endl;
		cout << endl;
		cout << "Enter the choice : ";
		int z;
		cin >> z;

		if(z == 1)
		{
			AddBooks();
			adminPrompt();

		}
		else if(z == 2)
		{
			DeleteBooks();
			adminPrompt();
		}
		else if(z == 3)
		{
			cout << "Enter Roll of the Student : ";
			string r;
			cin >> r;
			ReturnBooks(r);
			adminPrompt();
		}
		else if(z == 4)
		{
			cout << "Enter Serial No. of the Student : ";
			string r;
			cin >> r;
			deleteUser(r);
			adminPrompt();
		}
}

void Admin :: adminLogin()
{
	string n, p;
	cout << "Enter Username : ";
	cin >> n;
	cout << "Enter Password : ";
	cin >> p;
	if(name == n && pass == p)
	{
		adminPrompt();
	}
	else
	{
		cout << "Wrong Username or Password." << endl;
		cout << "1 - Try again" << endl;
		cout << "2 - Quit" << endl;
		int k;
		cout << "Enter Choice : ";
		cin >> k;
		if(k == 1)
		{
			adminLogin();
		}
	}
}

void Admin::deleteUser(string roll)
{
	CSV Del("Students.csv");
	Del.DeleteRow(roll);
}
