//VVIMP NOTE: it works only FOR ACYCLIC GRAPHS!

//then how did we use it for cycle detection in directed graph??....we modified it using count variavle!


#include<bits/stdc++.h> 
using namespace std; 

void topologicalSort(vector<int> adj[], int V) 
{ 
    vector<int> in_degree(V, 0); 
  
    for (int u = 0; u < V; u++) { 
        for (int x:adj[u]) 
            in_degree[x]++; 
    } 
  
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 

    int count=0;  //exact same as topological/khans algo...just this count variable is extra
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop(); 
  
        for (int x: adj[u]) 
	{
		in_degree[x]--;
		if (in_degree[x] == 0) 
                    q.push(x); 
	}
        count++;  //counting the number of vertices popped 
    } 
    if (count != V) {//whenever theres a cycle, surely count<V, because there will certainly be a set of nodes whose indegree will never become zero
        cout << "There exists a cycle in the graph\n"; 
    }
    else{
        cout << "There exists no cycle in the graph\n";
    }
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

int main() 
{ 
    int V=5;
    vector<int> adj[V];
    addEdge(adj,0, 1); 
    addEdge(adj,4, 1); 
    addEdge(adj,1, 2); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 1);  
  
    topologicalSort(adj,V);

	return 0; 
} 
