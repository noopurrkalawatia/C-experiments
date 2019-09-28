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
    int distributeCoins(TreeNode* root) 
    {   
        int ans = 0;
        calCoins(root,ans);
        return ans;
    }
    
    int calCoins(TreeNode* root, int& ans)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int l = calCoins(root->left,ans);
        int r = calCoins(root->right,ans);
        
        //update moves
        ans += abs(l) + abs(r);
            
        return (root->val - 1 + l + r);
    }
};
