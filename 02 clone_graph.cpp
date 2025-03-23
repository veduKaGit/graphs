//clone wale mei always use unordered_map
//we can NOT use unordered_set => because for loop mei else wale part mei we need to push our current node => NOT possible with set

Node* dfs(Node* curr, unordered_map<Node*, Node*>&vis){
    
    Node* clone = new Node(curr->val);
    
    vis[curr] = clone;                  //imp
    vector<Node *>to_visit;
    
    for(auto x:curr->neighbors){
        if(vis.find(x) == vis.end())
            to_visit.push_back(dfs(x, vis));    //dfs
        else
            to_visit.push_back(vis[x]);         //IMP => vis[x] => already cloned node
    }
    
    clone->neighbors = to_visit;          
    
    return clone;                        
} 
 
Node *Solution::cloneGraph(Node *node) {
    unordered_map<Node*, Node*>vis;  //vis is NOT array here
    return dfs(node, vis);
}
