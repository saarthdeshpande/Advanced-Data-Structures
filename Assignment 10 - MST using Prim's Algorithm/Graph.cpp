/*
 * Graph.cpp
 *
 *  Created on: 06-Mar-2020
 *      Author: g9
 */

#include "Graph.h"

Graph::Graph() {
	// TODO Auto-generated constructor stub
	for (int i = 0; i < 20; i++)	// initialize weight matrix to 0
	  for (int j = 0; j < 20; j++)
	    weight[i][j] = 0;
	n_vertices = 0;
	n_edges = 0;
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

void Graph::createGraph()
{
	int startNode, endNode;
	cout << "\nNo. of Vertices: ";
	cin >> n_vertices;
	cout << endl;
	for(int i = 0;i < n_vertices;i++)
	{
		cout << "Name of Vertex #" << i << ": ";
		cin >> name[i];
	}
	cout << "\nNo. of Edges: ";
	cin >> n_edges;
	for(int i = 0;i < n_edges;i++)
	{
		cout << "\nEdge #" << i << ":\n";
		cout << "Start Node: ";
		cin >> startNode;
		cout << "End Node: ";
		cin >> endNode;
		cout << "Weight of Edge: ";
		cin >> weight[startNode][endNode];	// add weight of edge to matrix (a -> b)
		weight[endNode][startNode] = weight[startNode][endNode];	// add same weight to (b -> a)
	}
}

void Graph::PrimsAlgorithm()
{
	cout << "\nMST via Prim's Algorithm\n";
	int visited[n_vertices] = {0}, mincost = 0, edge = 0, row, column;
	visited[0] = 1;
	cout << "\nEdge\tWeight\n";
	while(edge < n_vertices - 1)
	{
	  int min = 999;	// keep as high as possible to find local minimum
	  row = 0;
	  column = 0;

	  for(int i = 0; i < n_vertices; i++)
	  {
		if(visited[i])	// if node hasn't been visited before
		{
			for(int j = 0; j < n_vertices; j++)
			{
			  if(!visited[j] && weight[i][j]) // if node has not been visited and there is an edge
			  {
				  if(min > weight[i][j]) 	// if weight is lesser than the assigned minimum
				  {
					  min = weight[i][j];
					  row = i;
					  column = j;
				  }
			  }
			}
		}
	  }
	  mincost += weight[row][column];	// keep adding the processed local minimum to the final MST cost
	  cout << row <<  " - " << column << " :  " << weight[row][column];
	  cout << endl;
	  visited[column] = true;
	  edge++;
	}
	cout << "\nMinimum Cost = " << mincost << endl;
}

void Graph::display()
{
	cout << "\nGiven Graph:\n\n";
	for(int i = 0;i < n_vertices;i++)
		(i == 0)? (cout << setw(6) << name[i]) : (cout << setw(5) << name[i]);
	cout << endl;
	for (int i = 0; i < n_vertices; i++)
	{
		cout << name[i];
	   for (int j = 0; j < n_vertices; j++)
	      cout << setw(5) << weight[i][j] ;
	   // Newline for new row
	   cout << endl;
	}
}
