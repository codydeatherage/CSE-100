#include <iostream>
#include <limits.h>

using namespace std;

struct Edge
{
	int begin;
	int end;
	int value;
};

struct Graph
{
	int V;
	int E;
	Edge *edges;
};



int main() 
{
	int vertices, edges;
	Graph g;
	cin >> vertices;
	cin >> edges;
	g.V = vertices;
	g.E = edges;
	g.edges = new Edge[g.E];
	for(int i = 0; i<g.E;i++)
	{
		int start, end, weight;
		cin>>start>>end>>weight;
		g.edges[i].begin = start;
		g.edges[i].end = end;
		g.edges[i].value = weight;
	}
	int distance[g.V];

	//Sets every edge to max
	for (int i = 0; i < g.V; i++) {
		distance[i] = INT_MAX;
	}

	distance[0] = 0;

	for (int i = 0; i < g.V; i++) 
	{
		for (int j = 0; j<g.E;j++) 
		{
			int a = g.edges[j].begin;
			int b = g.edges[j].end;
			if (distance[a]!=INT_MAX&&distance[a]+g.edges[j].value < distance[b])
				distance[b]=distance[a]+g.edges[j].value;
		}
	}

	//Check for negative cycles 
	for(int j = 0; j<g.E;j++)
	{
			int a = g.edges[j].begin;
			int b = g.edges[j].end;
			if (distance[a]!=INT_MAX&&distance[a]+g.edges[j].value < distance[b])
			{
				cout<<"FALSE"<<endl;
				return 0;
			}
	}

	cout << "TRUE\n";
	for(int i = 0; i < g.V; i++)
		if(distance[i]==INT_MAX)
			cout<<"INFINITY\n";
		else
			cout<<distance[i]<<endl;

	return 0;

}	