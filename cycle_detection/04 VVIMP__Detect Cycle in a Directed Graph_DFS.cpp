// 2 VVIMP THINGS:

// 1. no need to check for parent like in undirected graph
//    because its a directed graph here....so connection is only 1 way...not 2 way

// 2. Use recursion stack (bool vector) => only visited array will not be enough
//    example: 3->0->1->2 is our graph and we only use visited array
//    if we start from 0 => 0, 1, 2 are marked visited
//    when we do dfs from 3 now => 0 is already visited => it will say cycle exists

class Solution {
  public:
    bool dfs(int node, vector<bool>&rec, vector<bool>&vis, vector<vector<int>>&adj){
        // vis => tells us ALL nodes visited till now 
        // rec => tells us nodes visited in the CURRENT dfs call
        // (example when we start with node 0 for 3->0->1->2)
        // after this dfs call {0, 1, 2} => vis will be true
        // after this dfs call {3, 0, 1, 2}=> rec will be false
        vis[node] = true; 
        rec[node] = true;
        
        for(auto x: adj[node]){
            if(vis[x] == false){ // x never visited before
                if(dfs(x, rec, vis, adj) == true)
                    return true;
            }else if(rec[x] == true){ // x already visited in the CURRENT dfs call
                return true;
            }
        }
        
        rec[node] = false; // VVIMP => reset to false
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>>adj(V);
        
        for(auto x:edges)
            adj[x[0]].push_back(x[1]);
        
        vector<bool>rec(V, false);
        vector<bool>vis(V, false);
        
        for(int i=0;i<V;i++){
            if(vis[i] == false){
                if(dfs(i, rec, vis, adj) == true)
                    return true;
            }
        }
        
        return false;
    }
};
