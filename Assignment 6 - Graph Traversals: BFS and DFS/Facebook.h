/*
 * Facebook.h
 *
 *  Created on: 28-Feb-2020
 *      Author: g9
 */

#ifndef FACEBOOK_H_
#define FACEBOOK_H_

#include<iostream>
using namespace std;

struct DOB
{
	int day;
	int month;
	int year;
};

struct user;

struct connection
{
	int id;
	int comments;
	user *node;
	connection * next;
};

struct user
{
	int id;
	string name;
	DOB date;
	user *dlink;
	connection *flink;
};

class Facebook
{
	user *head;
public:
	Facebook();
	int DFS(const int);
	void birthdayMonth(int);
	int minCommentsBFS();
	void createGraph();
	void displayUsers();
	virtual ~Facebook();
};

#endif /* FACEBOOK_H_ */
