#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

typedef pair<int, int> pairI;
class Graph{
    	int V;//# of vertices
    	//Need to store an integer for vertex and weight
    	list< pair<int, int> > *adj;
public:
    	Graph(int V);  // Constructor
    	//add edge to graph
    	void addEdge(int u, int v, int w);
    	void primMST();
};

//Graph constructor
Graph::Graph(int V){
    	this->V = V;
    	adj = new list<pairI> [V];
}

//Used to add an edge with weight to the adj graph
void Graph::addEdge(int u, int v, int w){
    	adj[u].push_back(make_pair(v, w));
    	adj[v].push_back(make_pair(u, w));
}

void Graph::primMST(){
	//init min prior queue
    	priority_queue< pairI, vector <pairI> , greater<pairI> > prioQueue;
	//Declare 0 as src
    	int src = 0;
	//v.key = infinity
    	vector<int> key(V, INT_MAX);
    	//Vector that stores parents and in turn MST
    	vector<int> parent(V, -1);
    	//Vector that keeps track of vertices used
    	vector<bool> inMST(V, false);
	//insert src and make key 0
    	prioQueue.push(make_pair(0, src));
    	key[src] = 0;
	//while Q != 0
    	while (!prioQueue.empty()){
		//U extractMin(Q)
        	int u = prioQueue.top().second;
        	prioQueue.pop();
		//Add u to the used
	        inMST[u] = true;
        	// 'i' is used to get all adjacent vertices of a vertex
        	list< pair<int, int> >::iterator i;
        	for (i = adj[u].begin(); i != adj[u].end(); ++i){
            		// Get vertex label and weight of current adj node
            		int v = (*i).first;
            		int weight = (*i).second;
			//if v is not used and w(u,v) < v.key
            		if (inMST[v] == false && key[v] > weight){
                		//Update key of v
                		key[v] = weight;
                		prioQueue.push(make_pair(key[v], v));
                		parent[v] = u;
            		}
        	}
    	}
    	// Print edges of MST using parent array
    	for (int i = 1; i < V; ++i)
		cout<<parent[i]<<endl;
}

int main(){
	//Get the input
	int vertices;
	int edges;
	cin>>vertices;
	cin>>edges;
	Graph g(vertices);
	int* u = new int[edges];
	int* v = new int[edges];
	int* weight = new int[edges];
	for(int i = 0; i < edges; i++){
		cin>>u[i];
		cin>>v[i];
		cin>>weight[i];
		g.addEdge(u[i],v[i],weight[i]);
	}
	//Run prims
	g.primMST();
}
