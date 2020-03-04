/*
 * Facebook.cpp
 *
 *  Created on: 28-Feb-2020
 *      Author: g9
 */

#include "Facebook.h"
#include <stack>
#include <queue>
#include <iomanip>

Facebook::Facebook() {
	// TODO Auto-generated constructor stub
	head = NULL;
}

Facebook::~Facebook() {
	// TODO Auto-generated destructor stub
}

static int count = 0;

user* newUser()		// allocates memory and takes data for new user node
{
	user *temp = new user;
	count += 1;
	temp -> id = count;
	cout << "Name: ";
	cin.ignore();
	getline(cin,temp -> name);
	cout << "Date of Birth (DDMMYYYY):\nDay: ";
	cin >> temp -> date.day;
	cout << "Month: ";
	cin >> temp -> date.month;
	cout << "Year: ";
	cin >> temp -> date.year;
	temp -> dlink = NULL;
	temp -> flink = NULL;
	return temp;
}

connection* newFriend()		// allocates memory and takes data for new friend node
{
	connection *temp = new connection;
	cout << "Friend ID: ";
	cin >> temp -> id;
	cout << "No. of Comments on Friend's Posts: ";
	cin >> temp -> comments;
	temp -> next = NULL;
	return temp;
}

void Facebook::createGraph()
{
	if(head != NULL)
	{
		count = 0;
		for(user *temp = head;temp != NULL;temp = temp -> dlink)
		{
			head = head -> dlink;
			delete temp;
		}
	}
	int n_friends,n_users;
	cout << "\nNo. of Users: ";
	cin >> n_users;
	for(int i = 0;i < n_users;i++)
	{
		cout << "\nUser #" << i + 1 << "\n";
		user *temp = newUser();
		cout << "No. of Friends: ";
		cin >> n_friends;

		for(int j = 0;j < n_friends;j++)
		{
			cout << "\nFriend #" << j + 1 << ":\n";
			connection *frnd = newFriend();
			if(temp -> flink == NULL)	// if no friends have been inserted yet
				temp -> flink = frnd;
			else
			{
				connection *temp1 = temp -> flink;
				while(temp1 -> next != NULL)	// iterate till last friend has been reached
					temp1 = temp1 -> next;
				temp1 -> next = frnd;	// insert new friend at last position
			}
		}
		if(head == NULL)	// if no user has been added yet
			head = temp;
		else
		{
			user *temp1 = head;
			while(temp1 -> dlink != NULL)	// iterate till latest user has been reached
				temp1 = temp1 -> dlink;
			temp1 -> dlink = temp;	// insert at end
		//	temp1 = temp1 -> dlink;
		//	temp1 -> dlink = NULL;
		}
	}

	// now, store addresses of user nodes in the connection nodes

	for(user *temp = head;temp != NULL;temp = temp -> dlink)	// each user node
	{
		for(connection *frnd = temp -> flink;frnd != NULL;frnd = frnd -> next)	// each connection node
		{
			for(user *temp = head;temp != NULL;temp = temp -> dlink)	// search address of node
			{
				if(frnd -> id == temp -> id)
					frnd -> node = temp;
			}
		}
	}
}

void Facebook::displayUsers()
{
	cout << "User ID" << setw(10) << "Name" << setw(27) << "Connection | Comments\n";
	for(user *temp = head;temp != NULL;temp = temp -> dlink)
	{
		cout << endl  << setw(4) << temp -> id << setw(15) <<  temp -> name << setw(6);
		for(connection *temp1 = temp -> flink; temp1 != NULL;temp1 = temp1 -> next)
			(temp1 -> next == NULL) ? (cout << temp1 -> id << " | " << temp1 -> comments) :(cout << temp1 -> id << " | " << temp1 -> comments << " -> ");
	}
	cout << endl;
}

void displaySingleUser(user* u)
{
	cout << endl  << setw(4) << u -> id << setw(15) <<  u -> name << setw(6);
	for(connection *temp1 = u -> flink; temp1 != NULL;temp1 = temp1 -> next)
		(temp1 -> next == NULL) ? (cout << temp1 -> id << " | " << temp1 -> comments) :(cout << temp1 -> id << " | " << temp1 -> comments << " -> ");
}

void Facebook::birthdayMonth(int month)
{
	queue <user*> q;
	int visited[count] = {0};	// array to store whether user node has been visited
	q.push(head);
	cout << "User ID" << setw(10) << "Name" << setw(27) << "Connection | Comments\n";
	while(!q.empty())
	{
		user *v = q.front();
		q.pop();
		visited[v -> id - 1] = 1;	// set given user node has been visited
		for(connection *temp = v -> flink;temp != NULL;temp = temp -> next)
		{
			if(!visited[temp -> id - 1])	// if user node has not been visited, push to queue
				q.push(temp -> node);
		}
		if(v -> date.month == month)
			displaySingleUser(v);
	}
	cout << endl;
}

int Facebook::DFS(const int p)		// single DFS function for maximum comments && friends
{
	stack <user*> s;
	int visited[count] = {0};
	s.push(head);
	int globalmax = 0,localmax = -1;
	while(!s.empty())
	{
		user *v = s.top();
		s.pop();
		visited[v -> id - 1] = 1;
		if(p == 1)	// reset local maximum in case of maximum comments
			localmax = 0;
		for(connection *temp = v -> flink;temp != NULL;temp = temp -> next)
		{
			if(!visited[temp -> id - 1])
				s.push(temp -> node);
			switch(p)
			{
				case 1: localmax += 1;
						break;
				case 2: if(temp -> comments > globalmax)
							globalmax = temp -> comments;
						break;
			}
		}
		if(p == 1 && localmax > globalmax)	// update globalmax
			globalmax = localmax;
	}
	return globalmax;
}

int Facebook::minCommentsBFS()
{
	queue <user*> q;
	int visited[count] = {0};
	q.push(head);
	int min = 1000;
	while(!q.empty())
	{
		user *v = q.front();
		q.pop();
		visited[v -> id - 1] = 1;
		for(connection *temp = v -> flink;temp != NULL;temp = temp -> next)
		{
			if(temp -> comments < min)
				min = temp -> comments;
			if(!visited[temp -> id - 1])
				q.push(temp -> node);
		}
	}
	return min;
}
