#include <iostream>
#include <limits.h>

using namespace std;

struct Graph
{
	int V;
	int E;
	Edge *edges;
};

struct Edge
{
	int begin;
	int end;
	int value;
}


int main() 
{
	int vertices, edges;
	Graph *g;
	cin >> vertices;
	cin >> edges;
	g->V = vertices;
	g->E = edges;
	for(int i = 0; i<g->E;i++)
	{
		int start, end, weight;
		cin>>start>>end>>weight;
		g->edges[i].begin = start;
		g->edges[i].end = end;
		g->edges[i].value = weight;
	}
	int distance[vertices];

	//Sets every edge to max
	for (int i = 0; i < vertices; i++) {
		distance[i] = INT_MAX;
	}

	distance[0] = 0;

	//Check for negative cycles 
	for (i = 0; i < vertices; i++) 
	{
		for (j = 0; j<g->E;j++) 
		{
			int a = g->edges[j].begin;
			int b = g->edges[j].end;
			if (distance[a]!=INT_MAX&&distance[b]+g->edges[j].value < distance[a])
				distance[a]=distance[b]+g->edges[j];
		}
	}

	for(j = 0; j<g->E;j++)
	{
			int a = g->edges[j].begin;
			int b = g->edges[j].end;
			if (distance[a]!=INT_MAX&&distance[b]+g->edges[j].value < distance[a])
			{
				cout<<"FALSE"<<endl;
				break;
			}
	}

	cout << "TRUE";
	for(int i = 0; i < g->V; i++)
		cout<<distance[i]<<endl;

	return 0;

	