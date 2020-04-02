//============================================================================
// Name        : Assignment 11 - Sequential File Operations
// Author      : Saarth Deshpande 23150
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

#include "Information.h"

int main()
{
	Information infoObject;
	int resp,n,key,flag;
	ofstream op;
	do
	{
		cout << "\nSEQUENTIAL FILE OPERATIONS\n\n1. Create Table\n2. Display Table\n3. Add Entry\n4. Delete Entry\n5. Edit Entry\n6. Search Entry\n7. Exit\nYour Choice: ";
		cin >> resp;
		switch(resp)
		{
			case 1: op.open("abc.txt",ios::out|ios::trunc);	// if file already exists, truncate it
					op.close();
					cout << "No. of Records to Create: ";
					cin >> n;
					for(int i = 0;i < n;i++)
					{
						cout << endl << "Entry #" << i + 1 << endl;
						infoObject.input();
					}
					break;
			case 2: cout << endl << "Student ID" << setw(10) << "Name" << setw(15) << "Division" << setw(8) << "Age" << setw(14) << "Location" << endl;
					infoObject.display();
					break;
			case 3: infoObject.input();
					break;
			case 4: cout << "Enter Roll No. to Delete: ";
					cin >> key;
					infoObject.removeEntry(key);
					break;
			case 5: cout << "Enter Roll No. to Edit: ";
					cin >> key;
					infoObject.edit(key);
					break;
			case 6: flag = 0;
					cout << "Enter Roll No. to Search: ";
					cin >> key;
					infoObject.search(key,&flag);
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
