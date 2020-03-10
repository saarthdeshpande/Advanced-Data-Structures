/*
 * Graph.h
 *
 *  Created on: 06-Mar-2020
 *      Author: g9
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include<iomanip>
using namespace std;

class Graph
{
	string name[20];
	int n_vertices, n_edges;
	float weight[20][20];
public:
	Graph();
	void createGraph();
	void PrimsAlgorithm();
	void display();
	virtual ~Graph();
};

#endif /* GRAPH_H_ */
