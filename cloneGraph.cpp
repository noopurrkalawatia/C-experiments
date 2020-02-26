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
    private:
    unordered_map<Node*,Node*> visitedMap;
public:
    Node* cloneGraph(Node* node) 
    {
        if (node == NULL)
        {
            return node;
        }
        
        if(visitedMap.find(node) != visitedMap.end())
        {
            return (visitedMap.at(node));
        }
        
        Node* cloneNode = new Node(node->val);
        
        visitedMap[node] = cloneNode;
        
        for(auto neighbor : node->neighbors)
        {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return cloneNode;
    }
};
