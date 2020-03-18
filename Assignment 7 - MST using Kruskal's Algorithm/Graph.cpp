/*
 * Graph.cpp
 *
 *  Created on: 06-Mar-2020
 *      Author: g9
 */

#include "Graph.h"

Graph::Graph() {
	// TODO Auto-generated constructor stub
	n_vertices = n_edges = 0;
	edge = result = NULL;
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

void Graph::createGraph()
{
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
	edge = new Edge[n_edges];
	for(int i = 0;i < n_edges;i++)
	{
		cout << "\nEdge #" << i << ":\n";
		cout << "\nStart Node: ";
		cin >> edge[i].startNode;
		while(edge[i].startNode < 0 || edge[i].startNode >= n_vertices) // validation for negative node / node > n_vertices
		{
			cout << "\nInvalid Node. Please enter again.\n\nStart Node: ";
			cin >> edge[i].startNode;
		}
		cout << "\nEnd Node: ";
		cin >> edge[i].endNode;
		while(edge[i].endNode < 0 || edge[i].endNode >= n_vertices || edge[i].startNode == edge[i].endNode) // validation for negative node / node > n_vertices / start node == end node
		{
			cout << "\nInvalid Node. Please enter again.\n\nEnd Node: ";
			cin >> edge[i].endNode;
		}
		cout << "\nWeight of Edge: ";
		cin >> edge[i].weight;
		while(edge[i].weight <= 0)
		{
			cout << "\nInvalid Weight. Please enter again.\n\nWeight of Edge: ";
			cin >> edge[i].weight;
		}
	}
}

int find(subset subsets[], int i)
{
    if (subsets[i].parent != i)	    // find root and make root the parent of i
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y)	// A function that does union of two sets of x and y
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high rank tree (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    // If ranks are same, then make one as root and increment its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges according to their weights used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1 -> weight > b1 -> weight;
}

void Graph::KruskalsAlgorithm()
{
	cout << "\nMST via Kruskal's Algorithm\n\n";
	int V = n_vertices;
	delete []result;	// in case called again
	result = new Edge[n_vertices];
	int mincost = 0;
	int e = 0; // index variable used for result[]
	int i = 0; // index variable used for sorted edges

	qsort(edge, n_edges, sizeof(edge[0]), myComp);		// Sort all the edges in ascending order of their weight

	subset *subsets = new subset[( V * sizeof(subset) )];		// Allocate memory for creating V subsets (as many subsets as n_vertices)

	for (int v = 0; v < V; ++v)	// Create V subsets with single elements
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	while(e < V - 1 && i < n_edges)	// Number of edges in MST to be taken is equal to V-1
	{
		Edge next_edge = edge[i++];			// Pick the smallest edge, increment the index for next iteration

		int x = find(subsets, next_edge.startNode);
		int y = find(subsets, next_edge.endNode);

		if (x != y)	// If including this edge does't cause cycle
		{
			result[e++] = next_edge;	// include it in result and increment the index of result for next edge
			Union(subsets, x, y);
		}
		// Else discard the next_edge
	}
	cout << setw(7) << "Start" << setw(4) << "End" << setw(8) << "Weight" << endl;
	for(int i = 0;i < e;i++)		// print the contents of result[] to display the  built MST
	{
		cout << setw(5) << name[result[i].startNode] << setw(5) << name[result[i].endNode] << setw(7) << result[i].weight << endl;
		mincost += result[i].weight;
	}
	cout << "\nMinimum Cost = " << mincost << endl;
}

void Graph::display()
{
	cout << "\nGiven Graph:\n\n";
	cout << setw(7) << "Start" << setw(4) << "End" << setw(8) << "Weight" << endl;
	for(int i = 0;i < n_edges;i++)
		cout << setw(5) << name[edge[i].startNode] << setw(5) << name[edge[i].endNode] << setw(7) << edge[i].weight << endl;
}
