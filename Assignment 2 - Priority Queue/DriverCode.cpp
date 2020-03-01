/*

Roll Number : 23150
Batch: G9
Mock Practical : Assignment No. 2

*/

#include "QueueADT.h"
#include<string.h>
#include<stdio.h>

#include <iostream>
using namespace std;

static int count = 0;

Patient inputData()
{
	Patient p;
	count += 1;
	cout << "Name: ";
	cin.ignore();
	getline(cin,p.name);
	cout << "Age: ";
	cin >> p.age;
	cout << "Sex: ";
	cin >> p.sex;
	while(p.sex != 'M' && p.sex != 'F')	// sex M / F validation
	{
		cout << "\nPlease enter 'M' for Male or 'F' for female.\n";
		cout << "\nSex: ";
		cin >> p.sex;
	}
	char dummy[7];
	p.patientID = "PT";
	sprintf(dummy,"%03d",count);	// used for unique patient ID generation
	p.patientID += dummy;
	return p;
}

void showData(Patient p)
{
	cout << "PatientID: " << p.patientID << endl;
	cout << "Name: " << p.name << endl;
	cout << "Sex: " << p.sex << endl;
	cout << "Age: " << p.age << endl;
}

int main()
{
	int resp,resp2,priority;
	QueueADT q;
	do
	{
		cout << "\n\nPRIORITY QUEUE OPERATIONS\n\n1. Insert Record\n2. Exit\nYour Choice: ";
		cin >> resp;
		switch(resp)
		{
			case 1: cout << "\nEnter Patient Details:\n\n";
					cout << "Priority of Patient: ";
					cin >> priority;
					if(priority < 1 || priority > 3)	// 1 <= priority <= 3 validation
					{
						cout << "Priority can only lie in [1,3] range.";
						resp = 0;
						continue;
					}
					q.enqueue(inputData(),priority);
					break;
			case 2: return 1;
			default: cout << "Please enter a valid response.\n";
		}
	}while((resp != 1)&&(resp != 2));
	do
	{
		cout << "\n1. Insert Record\n2. Delete Record\n3. Display Records\n4. Exit\nYour Choice: ";
		cin >> resp;
		switch(resp)
		{
			case 1: cout << "\nEnter Patient Details:\n\n";
					cout << "Priority of Patient: ";
					cin >> priority;
					if(priority < 1 || priority > 3)	// 1 <= priority <= 3 validation
					{
						cout << "Priority can only lie in [1,3] range.";
						continue;
					}
					q.enqueue(inputData(),priority);
					break;
			case 2: if(!q.isempty())
					{
						cout << "Delete the following record:\n\n";
						showData(q.peek());
						cout << "\nConfirm Deletion? (1 for YES | 0 for NO): ";
						cin >> resp2;
						if(resp2 == 1)
						{
							q.dequeue();
							cout << "\nRecord Deleted Successfully!\n";
						}
						else
							cout << "\nRecord NOT Deleted.\n";
					}
					else cout << "\nQueue is Empty." << endl;
					break;
			case 3: q.display();
					break;
			case 4: return 0;
			default: cout << "Please enter a valid response.\n";
		}
	}while(resp != 4);
	return 0;
}
