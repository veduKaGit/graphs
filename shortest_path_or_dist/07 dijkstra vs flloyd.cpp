// same problem statement as Flloyd warshall => 
// find the shortest distances between every pair of vertices

// If the graph has a -ive cycle: 
// Dijkstra’s => TLE 
// Use flloyd warshall

// If the graph does NOT contain a -ive cycle: 
// Apply Dijkstra’s algorithm for every possible node
// time complexity for Dijkstra’s algorithm for this purpose => O(V*(E*logV)) => lesser than Flloyd warshall
