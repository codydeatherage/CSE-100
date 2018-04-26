#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pairs;

class Graph
{
        list< pair<int, int> > *adjacent;
    	int V;
public:
        void MST();
        void addEdge(int a, int b, int c);
    	Graph(int V);  // Constructor
};

void Graph::MST()
{
        int i,u,v, weight; 
        int src = 0;
        priority_queue <pairs,vector <pairs>, greater<pairs> > pQueue;
        vector<int> key(V, INT_MAX);
        key[src] = 0;
        pQueue.push(make_pair(0, src));
        vector<bool> interiorMst(V, false);
        vector<int> parent(V, -1);

        while (!pQueue.empty())
        {
            list< pair<int, int> >::iterator i;
            u = pQueue.top().second;
            pQueue.pop();
            interiorMst[u] = true;
            for (i = adjacent[u].begin(); i != adjacent[u].end(); i++)
            {
                    v = (*i).first;
                    weight = (*i).second;
                    if (interiorMst[v] == false && key[v] > weight)
                    {
                        key[v] = weight;
                        pQueue.push(make_pair(key[v], v));
                        parent[v] = u;
                    }
            }
        }
    // Print function
    if (pQueue.empty()) 
    {
       for (i = 1; i < V; ++i)
        cout<<parent[i]<<endl; 
    }

}

void Graph::addEdge(int a, int b, int c)
{
        adjacent[b].push_back(make_pair(a, c));
        adjacent[a].push_back(make_pair(b, c));
}

Graph::Graph(int V)
{
        this->V = V;
        adjacent = new list<pairs> [V];
}

void initializeGraph(int nodes, int edges) 
{
    int i;
    int* u = new int[edges];
    int* v = new int[edges];
    int* weight = new int[edges];
    Graph g(nodes);
  
    for(i = 0; i < edges; i++)
    {
        cin>>u[i];
        cin>>v[i];
        cin>>weight[i];
        g.addEdge(u[i],v[i],weight[i]);
    }

    g.MST();
}

int main(){
	int vertices, edges;
    cin >> vertices;
    cin >> edges;

    initializeGraph(vertices, edges);

    }