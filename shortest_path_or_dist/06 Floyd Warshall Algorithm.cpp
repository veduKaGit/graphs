//Floyd Warshall Algorithm....Graphs + DP

// Time Complexity: O(V^3)
// Auxiliary Space: O(V^2)

// Find the shortest distances between every pair of vertices in a given edge-weighted DIRECTED graph.
// For UNdirected => make it directed
// if we have an edge from u-v with weight wt
// add 2 directed edges (from u->v and v->u with weight wt)
// now it'll work


// The graph is represented as an adjacency MATRIX of size n*n. 
// Matrix[i][j] denotes the weight of the edge from i to j. 
// If Matrix[i][j]=-1, it means there is no edge from i to j.
// Do it in place.

// Algo:
// matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j])
// i = source node, j = destination node, k = the node via which we are reaching from i to j.
// calculate dist[i][j] for every possible node k (k = 0, 1, ...V), where V = no. of nodes

// Note: dist[i][i] = 0 (dist from itself)

// How to detect a -ive cycle:
// we discussed: cost of reaching a node from itself must be 0 (dist[i][i]=0). 
// But in -ive cycle, if we try to reach a node from itself => the cost becomes < 0. 
// This is ONLY possible if the graph contains a -ive cycle.
// So, if we find that the cost of reaching any node from itself is < 0 => graph has a negative cycle.


// for a particular k => dp[i][j] = min dist b/w nodes i,j  using (0, 1, 2... k-1) as intermediate nodes

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	void shortest_distance(vector<vector<int>>&matrix) {
		int n = matrix.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == -1) 
					matrix[i][j] = 1e9;  //~INFINITE if no edge exists
				if (i == j) 
	  				matrix[i][j] = 0;  //dist from itself
			}
		}
	
		for (int k = 0; k < n; k++) {  //VVIMP => K wala loop bahar
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
				}
			}
		}
	
	
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i==j && dist[i][j]<0)
	  				cout<<"detected a -ive wt cycle"<<endl;  //cycle detect
	
				if (matrix[i][j] == 1e9) //reset to INFINITY
					matrix[i][j] = -1;
			}
		}
	
	}
};


int main() {

	int V = 4;
	vector<vector<int>> matrix(V, vector<int>(V, -1));
	matrix[0][1] = 2;
	matrix[1][0] = 1;
	matrix[1][2] = 3;
	matrix[3][0] = 3;
	matrix[3][1] = 5;
	matrix[3][2] = 4;

	Solution obj;
	obj.shortest_distance(matrix);

	for (auto row : matrix) {
		for (auto cell : row) {
			cout << cell << " ";
		}
		cout << endl;
	}

	return 0;
}
