/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr))
        {
            return true;
        }
        stack<TreeNode*> myStack;
        struct TreeNode* current = root;
        long int prev = LLONG_MIN;
        
        while(current != nullptr || myStack.size() > 0)
        {
            while(current != nullptr)
            {
                myStack.push(current);
                current = current->left;
            }
            
            current = myStack.top();
            myStack.pop();
              
            if(current->val <= prev)
            {
                return false;
            }
            prev = current->val;
            current = current->right;
        }
        return true;
    }
};
