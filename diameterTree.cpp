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
    
    int diameterBinary(TreeNode* root, int &result)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int left = diameterBinary(root->left,result);
        int right = diameterBinary(root->right,result);
        
        result = max(left+right+1, result);
        return max(left,right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int result = 1;
        diameterBinary(root,result);
        return(result - 1);
    } 
};
