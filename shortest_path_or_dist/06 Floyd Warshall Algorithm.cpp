//Floyd Warshall Algorithm....Graphs + DP

// Time Complexity: O(V^3)
// Auxiliary Space: O(V^2)

// Find the shortest distances between every pair of vertices in a given edge-weighted DIRECTED graph.
// For UNdirected => make it directed
// if we have an edge from u-v with weight wt
// add 2 directed edges (from u->v and v->u with weight wt)
// now it'll work


// The graph is represented as an adjacency matrix of size n*n. 
// Matrix[i][j] denotes the weight of the edge from i to j. 
// If Matrix[i][j]=-1, it means there is no edge from i to j.
// Do it in place.

