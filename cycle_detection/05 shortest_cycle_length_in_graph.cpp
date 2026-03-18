// UN-directed graph
// 2 <= n <= 1000
// 1 <= edges.length <= 1000
// There are no repeated edges

// find shortest cycle length

//approach->
since shortest path problem => DONT even think of dfs !!! => not useful for shortest path
// this will be something similar to level order traversal (like BFS)
// apply BFS from every node -> find smallest cycle length starting and ending at that node
// do this for every node and find minimum cycle length

//time : O(V * (V+E))



// NOTE: since this is SHORTEST cycle => we use BFS
// if we have ques for LONGEST cycle => we use DFS (similar logic though) => NP HARD problem


class Solution {
public:
    int fun(int st, vector<vector<int>>&adj){
        int ret = INT_MAX, n = adj.size();

        queue<int>q;
        vector<int>dist(n, INT_MAX);
        vector<int>parent(n, -1);

        q.push(st);
        dist[st] = 0;
        parent[st] = -1;
        
        while(q.size()>0){
            int node = q.front();
            q.pop();

            for(auto nbr : adj[node]){
                if(dist[nbr] == INT_MAX){  //not visited
                    dist[nbr] = dist[node]+1;
                    parent[nbr] = node;
                    q.push(nbr);
                }else if(nbr != parent[node]){  // already visited AND not parent => whole code same as BFS => just this logic is extra
                    ret = min(ret, dist[node] + dist[nbr] + 1);
                }
            }
        }

        return ret;
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        int ans = INT_MAX;

        for(int i=0;i<n;i++)
            ans = min(ans, fun(i, adj));

        return ans==INT_MAX ? -1 : ans;
    }
};
