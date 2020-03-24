/*
 * Graph.cpp
 *
 *  Created on: 20-Mar-2020
 *      Author: saarth
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

int Graph::returnVertices()
{
	return n_vertices;
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

int Graph::minDistance(int dist[], bool visited[])
{

    // Initialize min value
    int min = 999, min_index;

    for (int v = 0; v < n_vertices; v++)
        if (visited[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void Graph::printPath(int parent[], int j)
{

    // Base Case : If j is source
    if (parent[j] == - 1)
        return;

    printPath(parent, parent[j]);

    (parent[parent[j]] == -1) ? (cout << name[j]) : (cout << " -> " << name[j] );
}

void Graph::printSolution(int dist[],int parent[],int src)
{
    cout << "\nVertex\t\tDistance\tPath\n";
    for (int i = 0; i < n_vertices; i++)
    {
    	(parent[i] != -1) ? (cout << "\n" << name[src] << " -> " << name[i] << "\t\t  " << dist[i] << "\t\t" << name[src] << " -> ") : (cout << "\n" << name[src] << " -> " << name[i] << "\t\t  " << dist[i] << "\t\t" << name[src]);
    	printPath(parent, i);
    }
    cout << endl;
}

void Graph::Djikstra(int sourceNode)
{
	int dist[n_vertices]; // dist[i] will hold the shortest distance from sourceNode to i

	int parent[n_vertices];

	bool visited[n_vertices]; // visited[i] will be true if vertex i is included in shortest path tree or shortest distance from source to i is finalized

	for (int i = 0; i < n_vertices; i++)	// Initialize all distances as INFINITE and visited[] as false
		dist[i] = INT_MAX, visited[i] = false, parent[i] = -1;

	dist[sourceNode] = 0;	// Distance of source vertex from itself is always 0

	for(int count = 0; count < n_vertices - 1; count++)	// Find shortest path for all vertices
	{
		int u = minDistance(dist, visited);			// Pick the minimum distance vertex from the set of vertices not yet processed. u is always equal to source in the first iteration.

		visited[u] = true;	// Mark the picked vertex as processed

		for (int v = 0; v < n_vertices; v++)	// Update dist value of the adjacent vertices of the picked vertex.

			// Update dist[v] only if is not in visited, there is an edge from u to v, and total weight of path from sourceNode to  v through u is smaller than current value of dist[v]
			if(!visited[v] && weight[u][v] && dist[u] != INT_MAX && dist[u] + weight[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + weight[u][v];
			}
	}
	// print the constructed distance array
	printSolution(dist, parent, sourceNode);
}
