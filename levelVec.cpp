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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int> > result;
        if(root == NULL)
        {
            return result;
        }
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        vector<int> inter;
        TreeNode* temp;
        
        while(myQueue.size() != 0)
        {
            int level = myQueue.size();
            for(int i = 0 ; i < level; ++i)
            {
                temp = myQueue.front();
                myQueue.pop();
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
            result.push_back(inter);
            inter.clear();
        }
        return result;
    }
};
