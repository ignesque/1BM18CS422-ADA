#include <bits/stdc++.h> 
using namespace std; 

vector<unordered_set<int> > make_graph(int numTasks, 
			vector<pair<int, int> >& prerequisites) 
{ 
	vector<unordered_set<int> > graph(numTasks); 
	for (auto pre : prerequisites) 
		graph[pre.second].insert(pre.first); 
	return graph; 
} 

vector<int> compute_indegree(vector<unordered_set<int> >& graph) 
{ 
	vector<int> degrees(graph.size(), 0); 
	for (auto neighbors : graph) 
		for (int neigh : neighbors) 
			degrees[neigh]++; 
	return degrees; 
} 

vector<int> findOrder(int numTasks, 
		vector<pair<int, int> >& prerequisites) 
{ 
	vector<unordered_set<int> > graph = 
			make_graph(numTasks, prerequisites); 
	vector<int> degrees = compute_indegree(graph); 
	queue<int> zeros; 
	for (int i = 0; i < numTasks; i++) 
		if (!degrees[i]) 
			zeros.push(i); 

	vector<int> toposort; 
	for (int i = 0; i < numTasks; i++) { 
		if (zeros.empty()) 
			return {}; 
		int zero = zeros.front(); 
		zeros.pop(); 
		toposort.push_back(zero); 
		for (int neigh : graph[zero]) { 
			if (!--degrees[neigh]) 
				zeros.push(neigh); 
		} 
	} 
	return toposort; 
} 

int main() 
{ 
	int numTasks,t1,t2; 
	cout<<"Enter the Number of tasks:";
	cin>>numTasks;
	vector<pair<int, int> > prerequisites; 
	cout<<"Enter the task and its prerequisite(limit to break):";
   for(;;){
      cin>>t1>>t2;
      if(t1 == numTasks && t2 == numTasks)
      break;
	prerequisites.push_back(make_pair(t1, t2)); 
   }
	vector<int> v = findOrder(numTasks, prerequisites); 

	for (int i = 0; i < v.size(); i++) { 
		cout << v[i] << " "; 
	} 

	return 0; 
} 
