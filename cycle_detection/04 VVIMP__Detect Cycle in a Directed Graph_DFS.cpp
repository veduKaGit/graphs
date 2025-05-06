// 2 VVIMP THINGS:

// 1. no need to check for parent like in undirected graph
//    because its a directed graph here....so connection is only 1 way...not 2 way

// 2. Use recursion stack (bool vector) => only visited array will not be enough
//    example: 3->0->1->2 is our graph and we only use visited array
//    if we start from 0 => 0, 1, 2 are marked visited
//    when we do dfs from 3 now => 0 is already visited => it will say cycle exists

#include<bits/stdc++.h> 
using namespace std; 

bool DFSRec(vector<int> adj[], int s,bool visited[], bool recSt[]) 
{ 	
    visited[s]=true;
    recSt[s]=true;
    
    for(int u:adj[s])
    {
        if(visited[u]==false && DFSRec(adj,u,visited,recSt)==true)//check for immidiate NON visited descendant
                {return true;}
        else if(recSt[u]==true) //if already one of the descendants is in the recursion call stack, it means a back edge from descendant to ancestor, means theres a cycle
            {return true;}
    }
    recSt[s]=false; //once all the descendants are visited, remove it from the call stack
    return false;
}

bool DFS(vector<int> adj[], int V){
    bool visited[V]; 
	for(int i=0;i<V; i++) 
		visited[i] = false;
	
	bool recSt[V]; //array to store if a particular vertex is in the recursion call stack 
	for(int i=0;i<V; i++) 
		recSt[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            if(DFSRec(adj,i,visited,recSt)==true)
                return true;
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

int main() 
{ 
	int V=6;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,2,1); 
	addEdge(adj,2,3); 
	addEdge(adj,3,4); 
	addEdge(adj,4,5);
	addEdge(adj,5,3);

	if(DFS(adj,V))
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";

	return 0; 
} 
