// very simple => just read once

// works for: ((directed OR undirected) && cyclic graphs  &&  weighted  &&  -ive path distances)

// time complexity : O(V*E)

// works for Directed graphs ONLY? (actually NOT)

// for UNidrected graphs => make it directed
// if we have an edge from u-v with weight wt
// add 2 directed edges (from u->v and v->u with weight wt)
// now it'll work


//algo:
// 1. first we'll define "relax edges":
//    we have edge u->v with weight wt. 
//    dist[u] = the shortest distance to reach node u found UNTIL NOW (similarly dist[v])
//    If: (dist[u] + wt) < dist[v] => we will update the value of dist[v] = (dist[u] + wt) 
//    This process of updating the distance is called the relaxation of edges.

// 2. algo is to relax ALL the edges for N-1( N = no. of nodes) times sequentially.
//    After N-1 iterations, we should have minimized the distance to every node.

//    why this works: algorithm will minimize the distance of the ith node in the ith iteration 
//    like dist[1] will be updated in the 1st iteration, dist[2] will be updated in the 2nd iteration, and so on.
//    In a graph of N nodes => we will take at most N-1 edges to reach from the first to the last node.
//    Thus, we need exact N-1 iterations. It is impossible to draw a graph that takes more than N-1 edges to reach any node. 

// 3. How to detect a -ive cycle in the graph?
//    if we keep on rotating inside a -ive cycle, the path weight will be decreased in every iteration. 
//    But according to our intuition, after N-1 iterations no relaxation of edges is possible.
//    To check for a negative cycle, we will relax the edges one more time after the completion of N-1 iterations. 
//    If in that Nth iteration, it is found that further relaxation of any edge is possible, we can conclude that the graph has a negative cycle. 



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	/*  Function to implement Bellman Ford
	*   edges: vector of vectors which represents the graph
	*   S: source vertex to start traversing graph with
	*   V: number of vertices
	*/
	vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
		vector<int> dist(V, 1e8);
		dist[S] = 0;
		for (int i = 0; i < V - 1; i++) {
			for (auto it : edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];
				if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			}
		}
		// Nth relaxation to check negative cycle
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
				return { -1};
			}
		}


		return dist;
	}
};


int main() {

	int V = 6;
	vector<vector<int>> edges(7, vector<int>(3));
	edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, -3};
	edges[4] = {1, 2, -2};
	edges[5] = {3, 4, -2};
	edges[6] = {2, 4, 3};

	int S = 0;
	Solution obj;
	vector<int> dist = obj.bellman_ford(V, edges, S);
	for (auto d : dist) {
		cout << d << " ";
	}
	cout << endl;

	return 0;
}
