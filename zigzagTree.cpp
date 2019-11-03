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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int> > result;
        if(root == NULL)
        {
            return result;
        }
        queue<TreeNode*> myQueue;
        vector<int> inter;
        bool rev = false;
        
        myQueue.push(root);
        myQueue.push(NULL);
        
        while(myQueue.size() != 0)
        {
            TreeNode* temp = myQueue.front();
            myQueue.pop();
            
            if(temp == NULL)
            {
                if(rev == true)
                {
                    reverse(inter.begin(),inter.end()); 
                }
                result.push_back(inter);
                rev = !rev;
                if(myQueue.size() != 0)
                {
                    myQueue.push(NULL);
                }
                inter.clear();
            }
            else
            {
                inter.push_back(temp->val);
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
        return result;
    }
};
