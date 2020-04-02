/*
 * Information.h
 *
 *  Created on: 02-Apr-2020
 *      Author: saarth
 */

#ifndef INFORMATION_H_
#define INFORMATION_H_

#include<iostream>
using namespace std;
#include<fstream>
#include<iomanip>

struct Student
{
	int id,age,div;
	string name, loc;
};

class Information
{
	Student s;
	ofstream op;
	ifstream ip;
	fstream fp;
public:
	Information();
	void input();
	void edit(int);
	void search(int,int*);
	void removeEntry(int);
	void display();

	virtual ~Information();
};

#endif /* INFORMATION_H_ */
