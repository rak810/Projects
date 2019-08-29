using namespace std;
class Book
{
	string serial; //serial number for identification of a book
	string name; //name of a book
	string writer; //name of the author of a book
	string isbn; //ISBN number of the book
	string cat; //catergory of book or topics of the book
	string borrower; //Roll no. of the borrower
	string availability; // Check if the book is available
	string bdate; //date of borrowing
	string duedate; //date of returning books
	string due; //due amount of money for late return
public:
	Book(); //initialize a book object. sets important variables to null or empty state
	void GetData(); //Gets book name, author, isbn, category
	void RenewBooks(string roll, string file);
	void SearchBooks(string roll, string file); //search the Books.csv to check if the searched book is available
	void AddBooks(); //Add Books to the Books.csv
	void DeleteBooks(); //enter book serial to delete a particular book
	void ReturnBooks(string rl); //enter roll of the student to return all books. changes borrower, availability, borrow date, due date to null
	void BorrowedBooks(string roll, string file); //Used by student to see borrowed books using roll number
	void BorrowBooks(string roll, string file); //Used by student to borrow books using roll number
	void DueCheck(string roll, string file);
};

Book :: Book()
{
	borrower = "NA";
	availability = "Y";
	bdate = "NA";
	duedate = "NA";
	due = "0";
}

void Book :: GetData()
{
	cin.ignore(1000,'\n');
	cout << "Enter the Book Name: ";
	getline(cin, name);
	cout << "Enter The Writer Name: ";
	getline(cin, writer);
	cout << "Enter Book's Category :";
	getline(cin, cat);
	cout << "Enter the ISBN number : ";
	cin >> isbn;
}

void Book :: AddBooks()
{
	int ln, i = 0, n; 
	vector<string> v;
	CSV CsvWriter("Books.csv");
	ln = 101 + CsvWriter.CountRow();
	cout << "Enter The Number Of Books You Want To Add : ";
	cin >> n;
	cin.ignore();

	for (i = 0; i < n; ++i)
	{
		cout << "Enter The details of Book no. " << i+1 << endl;
		GetData();
		string s =  to_string(ln+i);
		serial = s;
		v = {serial, name, writer, isbn, cat, borrower, availability, bdate, duedate, due};
		CsvWriter.AddDatainRow(v.begin(), v.end());
	}
}

void Book::DueCheck(string roll, string file)
{
	string line, word;
	int n = 0;
	vector<string> row;
	Date dt;
	ifstream fp;
	fp.open(file);
	CSV dueWriter("Books.csv");
	while(getline(fp, line))
	{
		stringstream s(line);
		while(getline(s,word, ','))
		{
			row.push_back(word);
		}
		if(row[5] == roll)
		{
			Date dt1(row[8]);
			if(dt > dt1)
			{
				Date dt2 = dt - dt1;
				n+=dt.DueCalc(dt2);
				string s = to_string(dt.DueCalc(dt2));
				row[9] = s;
				dueWriter.UpdateRow(row);
			}
		}
		row.clear();
	}
	fp.close();

	cout << "DUE : " << n << endl; 
}

void Book :: BorrowedBooks(string roll, string file)
{
	string line, word;
	int n = 0;
	vector<string> row;

	ifstream fp;
	fp.open(file);
	cout << "\t\t+++++BORROWED BOOKS+++++++++" << endl;
	while(getline(fp, line))
	{
		stringstream s(line);
		while(getline(s,word, ','))
		{
			row.push_back(word);
		}
		if(row[5] == roll)
		{
			cout <<"\t\t  SL NO. : " << row[0] << endl;
			cout <<"\t\t  BOOK NAME : "<<row[1] << endl;
			cout <<"\t\t  AUTHOR : "<<row[2] << endl;
			cout << "\t\t  ISSUE Date : "<<row[7] << endl;
			cout <<"\t\t  DUE DATE : "<<row[8] << endl;
			cout <<"\t\t  DUE :" << row[9] << endl;
			cout << "\t\t------------------------" << endl;
		}
		row.clear();
	}
	fp.close();
}

void Book :: RenewBooks(string roll, string file)
{
	string line, word;
	int n = 0;
	vector<string> row;

	ifstream fp;
	fp.open(file);
	CSV RWriter("Books.csv");

	while(getline(fp, line))
	{
		stringstream s(line);
		while(getline(s,word, ','))
		{
			row.push_back(word);
		}
		if(row[5] == roll)
		{
			Date Rdate(row[8]);
			row[8] = Rdate.DueDate(1);
			RWriter.UpdateRow(row);
		}
		row.clear();
	}
	fp.close();
}
void Book :: SearchBooks(string roll, string file)
{
	string bname;
	cin.ignore();
	cout << "Enter A book Name Or Serial Number to search: ";
	getline(cin, bname);
	string line, word;
	vector<string> row;
	bool k = false;
	ifstream fp;
	fp.open(file);

	while(getline(fp, line))
	{
		stringstream s(line);
		while(getline(s,word, ','))
		{
			row.push_back(word);
		}
		if(row[1] == bname || row[0] == bname)
		{
			cout << "\t\t+++++BOOK INFO++++++++" << endl;
			cout <<"\t\t  SL NO. : " << row[0] << endl;
			cout <<"\t\t  BOOK NAME :"<<row[1] << endl;
			cout <<"\t\t  AUTHOR : "<<row[2] << endl;
			cout << "\t\t ISBN : "<<row[3] << endl;
			cout <<"\t\t  TOPIC : "<<row[4] << endl;
			cout <<"\t\t  AVAILABILITY :" << row[6] << endl;
			cout << "\t\t++++++++++++++++++++++" << endl;
		}
		else
		{
			k = true;
		}
		row.clear();
	}
	if(!k)
	{
		cout << "REQUESTED BOOK NOT FOUND" << endl;
	}
	fp.close();
	int n;
	cout << "1 - Borrow Books" << endl;
	cout << "2 - Search Again" << endl;
	cout << "Enter A choice : " ;
	cin >> n;
	if(n == 1)
	{
		BorrowBooks(roll, file);
	}
	else if(n == 2)
	{
		SearchBooks(roll, file);
	}
}

void Book :: BorrowBooks(string roll, string file)
{
	int k;
	vector<string> sl;
	vector<string> row;
	Date dt;
	cout << "You Can Not Borrow More Than 3 books" << endl;
	cout << "Enter the number of Books : ";
	cin >> k;
	cout << "Enter The Serial Numbers : ";
	for (int i = 0; i < k; ++i)
	{
		string slno;
		cin >> slno;
		sl.push_back(slno);
	}

	string line, word;
	ifstream fp;
	fp.open(file);
	CSV borrow("Books.csv");
	while(getline(fp, line))
	{
		stringstream s(line);
		while(getline(s,word, ','))
		{
			row.push_back(word);
		}
		if(row[0] == sl[0] || row[0] == sl[1] || row[0] == sl[2] && row[6] == "Y")
		{

			row[6] = "N";
			row[5] = roll;
			row[7] = dt.CurrentDate();
			row[8] = dt.DueDate(1);
			borrow.UpdateRow(row);
			cout << "Book Borrowed" << endl;
		}
		row.clear();
	}
	fp.close();
	cout << "1 - See Borrowed Books" << endl;
	cout << "2 - Quit" << endl;
	int x;
	cout << "Enter The Choice : ";
	cin >> x;
	if(x == 1)
	{
		BorrowedBooks(roll, file);
	}

}

void Book :: DeleteBooks()
{
	CSV deletion("Books.csv");
	cout << "Enter the number of books for deletion : ";
	int x;
	cin >> x;
	for (int i = 0; i < x; ++i)
	{
		string s;
		cout << "Enter Book Serial no. " << i+1 << ": ";
		cin >> s;
		deletion.DeleteRow(s);
	}
	
}

void Book :: ReturnBooks(string rl)
{
	int k;
	vector<string> v;
	vector<string> row;
	cout << "Enter the number of Books : ";
	cin >> k;
	cout << "Enter The Serial Numbers : ";
	for (int i = 0; i < k; ++i)
	{
		string slno;
		cin >> slno;
		v.push_back(slno);
	}
	string line, word;
	ifstream fp;
	fp.open("Books.csv");
	CSV returned("Books.csv");
	while(getline(fp, line))
	{
		stringstream s(line);
		while(getline(s,word, ','))
		{
			row.push_back(word);
		}
		if(row[0] == v[0] || row[0] == v[1] || row[0] == v[2] && row[6] == "Y")
		{

			row[6] = "Y";
			row[5] = "NA";
			row[7] = "NA";
			row[8] = "NA";
			row[9] = "0";
			returned.UpdateRow(row);
			cout << "Book Return Updated" << endl;
		}
		row.clear();
	}
	fp.close();
}
