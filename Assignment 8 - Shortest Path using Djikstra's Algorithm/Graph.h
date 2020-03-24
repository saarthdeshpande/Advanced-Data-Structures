/*
 * Graph.h
 *
 *  Created on: 20-Mar-2020
 *      Author: saarth
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include<iostream>
#include<limits.h>
using namespace std;

struct QNode
{
	int node, priority;
};

class Graph
{
	int n_vertices, n_edges;
	string name[20];
	float weight[20][20];
public:
	Graph();
	void createGraph();
	void Djikstra(int);
	int minDistance(int[],bool[]);
	void printPath(int[],int);
	void printSolution(int[],int[],int);
	int returnVertices();
	virtual ~Graph();
};

#endif /* GRAPH_H_ */
