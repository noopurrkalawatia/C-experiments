/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec 
{
    private:
    
    void performSerialise(TreeNode *root, string &result)
    {
        if(root == NULL)
        {
            result.append("n,");
            return;
        }

        result.append(to_string(root->val));
        result.append(",");
        
        performSerialise(root->left, result);
        performSerialise(root->right, result);   
    }
    
    void processString(string &str, vector<string> &result)
    {
        int found = str.find_first_of(',');
        while(found != string::npos)
        {
            result.push_back(str.substr(0, found));
            str = str.substr(found + 1);
            found = str.find_first_of(',');
        }
        
        result.push_back(str);
    }
    
    void processString2(string &str, vector<string> &tokens)
    {
        stringstream ss(str);
        string intermediate;
      
        while(getline(ss, intermediate, ',')) 
        { 
            tokens.push_back(intermediate); 
        }
    }
    
    TreeNode* performDeserialize(int &index,const vector<string> &data)
    {
        if(data[index] == "n")
        {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(stoi(data[index]));
        root->left = performDeserialize(++index, data);
        root->right = performDeserialize(++index, data);
        
        return root;
    }
    
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string result;
        performSerialise(root, result);
        result.resize(result.size() - 1);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if(data.size() == 0)
        {
            return NULL;
        }
        
        int index = 0;
        vector<string> dataVector; 
        processString2(data, dataVector);
        TreeNode *root = performDeserialize(index, dataVector);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
