A Bipartite Graph is a graph whose vertices can be divided into two independent sets, 
U and V such that every edge (u, v) either connects a vertex from U to V or a vertex from V to U. 
In other words, for every edge (u, v), either u belongs to U and v to V, or u belongs to V and v to U. 
We can also say that there is no edge that connects vertices of same set.

A bipartite graph is possible if the graph coloring is possible using two colors 
such that vertices in a set are colored with the same color. 

Note that it is possible to color a cycle graph with even cycle using two colors. 

It is NOT possible to colour a cycle graph with odd cycle using two colours. 


In a Bipartite graph, adjacent nodes can NOT have the same colour.


VVIMP STATEMENT:
If a graph has odd length cycle, then its never Bipartite.
If a graph does NOT have an odd length cycle, then surely Bipartite.

