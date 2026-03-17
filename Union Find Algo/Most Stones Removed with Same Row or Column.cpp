// I have written 2 solutions
Time complexity of union-find approach: O(N) => BETTER!!!!
// Time complexity of dfs approach: 0N(N^2) => NOT good

// On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
// means that if 1 stone is @ (0,0) and the other one is @ (100,0), then also 1 of them will be removed.

// Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, 
// return the largest possible number of stones that can be removed.

// Example :
// Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
// Output: 5
// Explanation: One way to remove 5 stones is as follows:
// 1. Remove stone [2,2] because it shares the same row as [2,1].
// 2. Remove stone [2,1] because it shares the same column as [0,1].
// 3. Remove stone [1,2] because it shares the same row as [1,0].
// 4. Remove stone [1,0] because it shares the same column as [0,0].
// 5. Remove stone [0,1] because it shares the same row as [0,0].
// Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.


// SOLUTION:
// One sentence to solve:
// Connected stones can be reduced to 1 stone,
// the maximum stones can be removed = stones number - islands number.
// so just count the number of "islands".

// as mentioned earlier, we can have 2 approaches to find the number of islands
// union-find approach: O(N) time
// dfs approach: O(N^2) time

// EXPLAINING THE UNION-FIND APPROACH:
// You can remove a stone only if: there exists another stone in the same row or column
// So removal depends on connections.
// Stones are connected if they share row/column
// You can keep removing stones as long as the component has >1 nodes
// NOW:
// 1. Model it as a graph
//    Each stone = node
//    Edge between two stones if: same row OR same column
//    Now you get a graph with multiple connected components
// 2. In one connected component of size k: You can remove k - 1 stones
//    You can keep removing until only 1 stone remains in that component
//    so final ans will be (total_stones - num_islands)
// 3. Why DSU works PERFECTLY here
//    We don’t care about order of removals
//    We only care about: which stones are connected, and how many independent groups exist
// 4. BUT which elements should we union/merge into one group?
//    since 2 stones are in a group when they share any of row/column
//    so, for each stone, we merge/union over (row, column+OFFSET)
//    so that when a new stone comes with a matching row/column => its added to that group
  


// APPROACH_1 =>

class Solution {
public:
    int find(int i, vector<int>&par){
        if(i==par[i])
            return i;
        return par[i] = find(par[i], par);
    }
    void union_fun(int x, int y, vector<int>&rank, vector<int>&par){
        int px = find(x, par);
        int py = find(y, par);

        if(rank[px] > rank[py]){
            par[py] = px;
        }else if(rank[py] > rank[px]){
            par[px] = py;
        }else{
            par[px] = py;
            rank[py]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int offset = 1e4+1;
        set<int>islands;

        vector<int>rank(2*1e4 + 5, 0);

        // here initialise as -1 beacuse NOT all numbers in the range [0, 2*1e4+4] are in stones arr
        // we have added a lot extra stones => which will result in extra islands when we count
        // we set par inside the for loop when we do the union
        vector<int>par(2*1e4 + 5, -1);
        
        for(auto x:stones){
            if(par[x[0]]==-1)
                par[x[0]] = x[0];
            if(par[x[1]+offset]==-1)
                par[x[1]+offset] = x[1]+offset;
                
            union_fun(x[0], x[1]+offset, rank, par);
        }

        for(auto x:par)
            if(x!=-1)
                islands.insert(find(x, par));  // VVIMP!!! => find(x, par), NOT par[x]
                
        return stones.size() - islands.size();
    }
};


// APPROACH_2 =>


class Solution {
public:
    void dfs(vector<int> adj[],vector<bool>& visited,int i)
    {
        if(visited[i])
            return;
        visited[i]= true;
        
        for(int u: adj[i])
        {
            if(!visited[u])
                dfs(adj,visited,u);
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> adj[n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                    {
                        adj[i].push_back(j);
                    }
                }
            }
        }
        
        vector<bool>visited(n,false);
        
        int count=0;
        for(int k=0;k<n;k++)
        {
            if(!visited[k])
            {
                dfs(adj,visited,k);  
                count++;
            }
        }
        
        return (n-count);
    }
};
