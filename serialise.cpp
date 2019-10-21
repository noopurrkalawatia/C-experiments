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
public:

void serialiseTree(TreeNode* root, string &result)
{
    if(root == nullptr)
    {
        return;
    }

    result += (to_string(root->val));
    result.push_back(' ');

    if(root->left == nullptr && root->right == nullptr)
    {
        return;
    }
    serialiseTree(root->left,result);

    if(root->right)
    {
        serialiseTree(root->right,result);
    }   
}

string serialize(TreeNode* root) 
{
    string result;
    serialiseTree(root,result);
    return result;
}

void tokeniseString(string data, vector<int> &result)
{
    stringstream ss(data);
    string inter;

    while(getline(ss,inter,' '))
    {
        result.push_back(stoi(inter));
    }
}
    
struct TreeNode* newNode(int val)
{
    struct TreeNode *temp =  (struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* deserialize(string data)
{
    if(data.size() == 0)
    {
        return nullptr;
    }
    vector<int> input;
    stack<struct TreeNode*> myStack;
    tokeniseString(data,input);
    
    struct TreeNode* top;
    struct TreeNode* newRoot = newNode(input[0]);

    myStack.push(newRoot);

    for(int i = 1 ; i < input.size(); ++i)
    {
        top = nullptr;
        if(input[i] < myStack.top()->val)
        {
            struct TreeNode* newnode = newNode(input[i]);
            top = myStack.top();
            top->left = newnode;
            myStack.push(newnode);
        }

        else
        {
            while(myStack.size() > 0 && myStack.top()->val < input[i])
            {
                top = myStack.top();
                myStack.pop();
            }

            struct TreeNode* newnode = newNode(input[i]);
            top->right = newnode;
            myStack.push(newnode);
        }
    }
    return newRoot;
}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
