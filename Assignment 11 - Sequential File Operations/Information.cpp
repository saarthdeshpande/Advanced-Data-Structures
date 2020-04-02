/*
 * Information.cpp
 *
 *  Created on: 02-Apr-2020
 *      Author: saarth
 */

#include "Information.h"

Information::Information() {
	// TODO Auto-generated constructor stub

}

Information::~Information() {
	// TODO Auto-generated destructor stub
}

void Information::input()
{
	op.open("abc.txt",ios::in|ios::app);
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

void Information::display()
{
	int id,age,div;
	string name,loc;
	ip.open("abc.txt",ios::out);
	while(ip >> id >> name >> div >> age >> loc)
		cout << setw(7) << id << setw(14) << name << setw(10) << div << setw(11) << age << setw(15) << loc << endl;
	ip.close();
}

void Information::search(int key,int *flag)
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

void Information::edit(int key)
{
	int id,age,flag = 0,n,div;
	string name, loc;
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

void Information::removeEntry(int key)
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
