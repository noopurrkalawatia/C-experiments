/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root == NULL)
        {
            return root;
        }
        
        queue<Node*> myQueue;
        int noOfNodes = 0;
        Node* temp = NULL;
        myQueue.push(root);
        
        while(myQueue.size() != 0)
        {
            noOfNodes = myQueue.size();
            for(int i = 0 ; i < noOfNodes; ++i)
            {
                temp = myQueue.front();
                myQueue.pop();
                
                if(i < noOfNodes - 1)
                {
                    temp->next = myQueue.front();
                }
                
                if(temp->left)
                {
                    myQueue.push(temp->left);
                }
                if(temp->right)
                {
                    myQueue.push(temp->right);
                }  
            }
        }
        return root;
    }
};
