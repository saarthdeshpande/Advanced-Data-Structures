#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

struct Student
{
	int id,age,div;
	string name, loc;
};

void input()
{
	ofstream op;
	op.open("abc.txt",ios::in|ios::app);
	Student s;
	cout << "Student ID: ";
	cin >> s.id;
	op << s.id << "\t";
	cout << "Name: ";
	cin.ignore();
	getline(cin,s.name);
	op << s.name << "\t";
	cout << "Division: ";
	cin >> s.div;
	op << s.div << "\t";
	cout << "Age: ";
	cin >> s.age;
	op << s.age << "\t";
	cout << "Location: ";
	cin.ignore();
	getline(cin,s.loc);
	op << s.loc << endl;
	op.close();
}

void display()
{
	ifstream ip;
	int id,age,div;
	string name,loc;
	ip.open("abc.txt",ios::out);
	while(ip >> id >> name >> div >> age >> loc)
		cout << setw(7) << id << setw(14) << name << setw(10) << div << setw(11) << age << setw(15) << loc << endl;
	ip.close();
}

void search(int key,int *flag)
{
	int id,age,div;
	string name,loc;
	ifstream ip;
	ip.open("abc.txt",ios::in);
	while(!ip.eof())
	{
		ip >> id >> name >> div >> age >> loc;
		if(id == key)
		{
			*flag = 1;
			break;
		}
	}
	ip.close();
}

void edit(int key)
{
	int id,age,flag = 0,n,div;
	string name, loc;
	fstream fp;
	fp.open("abc.txt",ios::in|ios::out);
	while(!fp.eof())
	{
		n = fp.tellg();
		fp >> id >> name >> div >> age >> loc;
		if(id == key)
		{
			flag = 1;
			break;
		}
	}
	if(flag == 1)
	{
		if(n != 0)
			fp.seekg(n + 1,ios::beg);
		else
			fp.seekg(n,ios::beg);
		cout << "Student ID: ";
		cin >> id;
		fp << id << "\t";
		cout << "Name: ";
		cin.ignore();
		getline(cin,name);
		fp << name << "\t";
		cout << "Division: ";
		cin >> div;
		fp << div << "\t";
		cout << "Age: ";
		cin >> age;
		fp << age << "\t";
		cout << "Location: ";
		cin.ignore();
		getline(cin,loc);
		fp << loc << endl;
		cout << endl << "Record Edited Successfully!" << endl;
	}
	else
		cout << endl << "Record Unavailable." << endl;
	fp.close();
}

void remove(int key)
{
	int id,age,flag = 0,div;
	string name,loc;
	fstream fp,ft;
	fp.open("abc.txt",ios::in|ios::out);
	ft.open("temp.txt",ios::out);
	while(!fp.eof())
	{
		fp >> id >> name >> div >> age >> loc;
		if(id == key)
		{
			flag = 1;
			break;
		}
		else
			ft << id << "\t" << name << "\t" << div << "\t" << age << "\t" << loc << "\t" << endl;
	}
	if(flag == 1)
	{
		while(fp >> id >> name >> div >> age >> loc)
			ft << id << "\t" << name << "\t" << div << "\t" << age << "\t" << loc << "\t" << endl;
		cout << endl << "Record Deleted Successfully!" << endl;
	}
	else
		cout << endl << "Record Unavailable." << endl;
	remove("abc.txt");
	rename("temp.txt","abc.txt");
	fp.close();
	ft.close();
}

int main()
{
	int resp,n,key,flag;
	ofstream op;
	do
	{
		cout << "\nSEQUENTIAL FILE OPERATIONS\n\n1. Create Table\n2. Display Table\n3. Add Entry\n4. Delete Entry\n5. Edit Entry\n6. Search Entry\n7. Exit\nYour Choice: ";
		cin >> resp;
		switch(resp)
		{
			case 1: op.open("abc.txt",ios::out|ios::trunc);
					op.close();
					cout << "No. of Records to Create: ";
					cin >> n;
					for(int i = 0;i < n;i++)
					{
						cout << endl << "Entry #" << i + 1 << endl;
						input();
					}
					break;
			case 2: cout << endl << "Student ID" << setw(10) << "Name" << setw(15) << "Division" << setw(8) << "Age" << setw(14) << "Location" << endl;
					display();
					break;
			case 3: input();
					break;
			case 4: cout << "Enter Roll No. to Edit: ";
					cin >> key;
					remove(key);
					break;
			case 5: cout << "Enter Roll No. to Edit: ";
					cin >> key;
					edit(key);
					break;
			case 6: flag = 0;
					cout << "Enter Roll No. to Search: ";
					cin >> key;
					search(key,&flag);
					if(flag == 1)
						cout << endl <<"Record Found!" << endl;
					else
						cout << endl << "Record Unavailable." << endl;
					flag = 0;
					break;
			case 7: return 1;
		}
	}while(resp != 7);
	return 0;
}
