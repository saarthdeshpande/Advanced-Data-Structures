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
#include<stack>
using namespace std;

struct Edge
{
	int startNode, endNode, weight;
};

struct subset
{
	int parent,rank;
};

class Graph
{
	int n_vertices, n_edges;
	string name[20];
	Edge *edge, *result;
	public:
		Graph();
		void createGraph();
		void KruskalsAlgorithm();
		void display();
		virtual ~Graph();
};

#endif /* GRAPH_H_ */
