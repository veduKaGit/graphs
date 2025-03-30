// when we have -ive weight edge (directed or UNdirected):
// Bellman ford works
// Dijkstra fails

// when we have -ive weight cycle:
// Bellman ford detects it
// Dijkstra gives TLE

// Time complexity:
// Bellman Ford: O(V*E)
// Dijkstra: O(E * logV)
