//clone wale mei always use unordered_map

class Solution {
public:
    void dfs(Node* node, unordered_map<Node*, Node*>& m) {
        if (m.find(node) != m.end()) return;

        m[node] = new Node(node->val);
        for (auto neighbor : node->neighbors) {
            dfs(neighbor, m);
            m[node]->neighbors.push_back(m[neighbor]);  //imp => do after dfs
        }
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;

        unordered_map<Node*, Node*> m;  //acts as vis array
        dfs(node, m);
        return m[node];
    }
};
