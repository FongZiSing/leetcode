/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(unordered_map<int, Node*>& visited, Node* node)
    {
        if (visited.find(node->val) != visited.end()) {
            return visited[node->val];
        }

        Node* newNode = new Node(node->val);
        visited.insert(make_pair(node->val, newNode));
        for (auto& neighbor : node->neighbors) {
            Node* n = dfs(visited, neighbor);
            newNode->neighbors.push_back(n);
        }
        return newNode;
    }

    Node* cloneGraph(Node* node)
    {
        unordered_map<int, Node*> visited;
        return node == nullptr ? node : dfs(visited, node);
    }
};