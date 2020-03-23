class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) 
    { 
        if(n == 0)
        {
            return result;
        }
        string ans;
        backtrack(ans,0,0,n);
        return result;
    }
    
    void backtrack(string ans,int open,int close, int n)
    {
        if(ans.size() == n * 2)
        {
            result.push_back(ans);
            return;
        }
        
        if(open < n)
        {
            backtrack(ans + "(" , open + 1, close, n);
        }
        if(close < open)
        {
            backtrack(ans + ")", open, close + 1, n);
        }
    }
};
