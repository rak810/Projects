
using namespace std;

class Student : private Book
{
	string serial;
	string roll;
	string name;
	string dept;
	string password;
public:
	friend class CSV;
	void Registration();
	void Login(string file);
	void SeeBooks();

};

void Student ::  Registration()
{
	int ln; 
	vector<string> v;
	CSV writer("Students.csv");
	ln = 101 + writer.CountRow();
	string s =  to_string(ln);
	serial = s;
	cout << "\t\t\t Enter Your Name : ";
	cin.ignore(100,'\n');
	getline(cin, name);
	cout << "\t\t\t Enter Your Roll : ";
	cin >> roll;
	cout << "\t\t\t Enter Your Department : ";
	cin >> dept;
	cout << "\t\t\t Enter Your Password : ";
	cin >> password;
	v = {serial, roll, name, dept, password};
	writer.AddDatainRow(v.begin(), v.end());
	cout << "\t\t\t REGISTRATION SUCCESSFUL!" << endl;
	cout << endl;
}

void Student :: Login(string file)
{
	string nm, ps, line, word, rl;
	int n = 0;
	vector<string> row;

	cout << "Name : ";
	cin >> nm;
	cout << "Password: ";
	cin >> ps;

	ifstream fp;
	fp.open(file);

	while(getline(fp, line))
	{
		stringstream s(line);
		while(getline(s,word, ','))
		{
			row.push_back(word);
		}
		if(row[2] == nm && row[4] == ps)
		{
			n = 1;
			rl = row[1];
			break;
		}
		row.clear();
	}

	fp.close();

	if(n == 1)
	{
		initscr();
		cout << "\t\t\t Logged in as " << nm << endl;
		cout << "\t\t\t Serial No. :" << row[0] << endl;
		cout << "\t\t\t Roll : " << row[1] << endl; 
		cout << "\t\t\t Department : " << row[3] << endl;
		cout << "\t\t   ++++++++++++++++++++++++++++" << endl;
		cout << "\t\t\t 1 - Search Books" << endl;
		cout << "\t\t\t 2 - See Borrowed Books" << endl;
		cout << "\t\t\t 3 - Renew Books" << endl;
		int z;
		cout << "Enter the choice : ";
		cin >> z;
		if(z == 1)
		{
			SearchBooks(rl, "Books.csv");
		}
		else if(z == 2)
		{
			BorrowedBooks(rl, "Books.csv");
		}
		else if(z == 3)
		{
			RenewBooks(rl, "Books.csv");
		}
	}
	else
	{
		int ch;
		cout << " 1 - Try Again" << endl;
		cout << " 2 - Go to Registration"<< endl;
		cout << "Enter the choice : ";
		cin >> ch;
		if(ch == 1)
		{
			Login(file);
		}
		else if(ch == 2)
		{
			Registration();
		}
	}
		
}
