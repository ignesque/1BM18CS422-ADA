#include<iostream> 
#include <list> 
using namespace std; 

class Graph { 
	int V;  
	list<int> *adj; 
public: 
	Graph(int V); 
	void addEdge(int v, int w); 
	void BFS(int s); 
}; 

Graph::Graph(int V) { 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) { 
	adj[v].push_back(w);  
} 

void Graph::BFS(int s) { 
	bool *visited = new bool[V]; 
	for(int i = 0; i < V; i++) 
		visited[i] = false; 
	list<int> queue; 
	visited[s] = true; 
	queue.push_back(s); 
	list<int>::iterator i; 
	while(!queue.empty()) { 
		s = queue.front(); 
		cout << s << " "; 
		queue.pop_front(); 
		for (i = adj[s].begin(); i != adj[s].end(); ++i) { 
			if (!visited[*i]) { 
				visited[*i] = true; 
				queue.push_back(*i); 
			} 
		} 
	} 
} 

int main() { 
    int n,s,d,node;
    cout<<"Enter the number of vertices:";
    cin>>n;
    cout<<"Enter source and destination nodes(limit to break):"<<endl;
	Graph g(n); 
	for(;;){
	cin>>s;
	cin>>d;
	if(s< n && d <n)
	g.addEdge(s,d);
	else if(s ==n || d == n)
	break;
	}
    cout<<"Which node to start traversing? ";
    cin>>node;
	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex "<<node<<") \n"; 
	g.BFS(node); 

	return 0; 
} 
