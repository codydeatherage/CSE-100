#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <limits>

using namespace std;

vector<int> adjacent[500], rev[500], sequenceNum;
vector< vector<int> > SCC;
bool visit[500] = {false};

void DFS(vector<int> graph[], vector<int> &sequenceNum, int i) 
{
	visit[i] = true;
	for(int j = 0; j < graph[i].size(); j++) 
	{
		if(!visit[graph[i][j]]) 
			DFS(graph, sequenceNum, graph[i][j]); // calls dfs again to see if node has been visited
		
	}
	sequenceNum.push_back(i);
}

void setFalse(int vertices) 
{
	for (int i = 0; i < vertices; i++)
		visit[i] = false;
}

void makeGraph(int edges) 
{
	int u, v;
	for(int i = 0; i < edges; i++) // Makes the graph
	{ 
		scanf("%d" "%d", &u, &v); 
		adjacent[u].push_back(v);
	}
}

void recordTraverse(int vertices) 
{
	for(int i = 0; i < vertices; i++) 
	{
		for(int j = 0; j < adjacent[i].size(); j++) 
		{
			rev[adjacent[i][j]].push_back(i);
		}
	}
}

void recordReverseTraverse()
{
	for(int i = 0; i < sequenceNum.size(); i++) 
	{
		if(!visit[sequenceNum[i]]) {
			vector<int> component;
			DFS(rev, component, sequenceNum[i]); // does DFS to the reversed graph
			SCC.push_back(component);
		}
	}
}

void output(int arr[],int vertices) 
{
	for(int i = 0; i < vertices; i++) 
	{
		printf("%d", arr[i]);
		cout << endl;
	}
}

int main() {
	int vertices, edges, comp;
	scanf("%d" "%d", &vertices, &edges);
	int arr[vertices];

	for(int i = 0; i < vertices; i++)  // sets arr[i] to be an incrementing value
	{
		arr[i] = i;
	}

	makeGraph(edges);

	setFalse(vertices); // sets all the values in visit to be zero

	for(int i = 0; i < vertices; i++) // Traverses the graph and push_back sequenceNum
	{ 
		if(!visit[i]) {
			DFS(adjacent, sequenceNum, i);
		}
	}

	recordTraverse(vertices);

	setFalse(vertices); // set false again to start recording the transverse

	reverse(sequenceNum.begin(), sequenceNum.end()); // goes from decreasing order in the stack

	recordReverseTraverse(); 

	for(int i = 0; i < SCC.size(); i++) 
	{
		for(int j = 0; j < SCC[i].size(); j++) 
		{
			comp = SCC[i][j];
			for(int k = 0; k < vertices; k++) 
			{
				if(arr[k] == comp)
				 {
					arr[k] = *min_element(SCC[i].begin(), SCC[i].end());
				}
			}
		}
	}

	output(arr,vertices);
	
	return 0;
}