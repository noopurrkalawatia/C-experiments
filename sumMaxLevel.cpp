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
    int maxLevelSum(TreeNode* root) 
    {
        if(root == NULL)
        {
            return NULL;
        }
        int level = 1;
        int noOfNodes = 0;

        int sum = 0;
        int max = INT_MIN,maxLevel = 0;
        TreeNode* temp;
        
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        
        while(myQueue.size() != 0)
        {
            noOfNodes = myQueue.size();
            for(int i = 0; i < noOfNodes; ++i)
            {
                temp = myQueue.front();
                myQueue.pop();
                sum += temp->val;
                
                if(temp->left)
                {
                    myQueue.push(temp->left);
                }
                if(temp->right)
                {
                    myQueue.push(temp->right);
                }
            }
            if(sum > max)
            {
                max = sum;
                maxLevel = level;
            }
            sum = 0;
            level++;
        }
        
        return maxLevel;
    }
};
