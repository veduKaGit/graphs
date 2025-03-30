// Whenever we have UNdirected graph with a -ive weight
// We can NEVER find shortest dist
// BOTH dijkstra, Bellman Ford DO NOT work

//if we have -ive edge bw u and v
//then u and/or v will always be in the queue/priority_queue => TLE
