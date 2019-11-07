class Solution {
public:
    int findJudge(int N, vector<vector<int> >& trust) 
    {
        if(trust.size() == 0)
        {
            return 1;
        }
        
        vector<int> balance(N + 1);
        
        for(int i = 0; i < trust.size(); ++i)
        {
            --balance[trust[i][0]];
            ++balance[trust[i][1]];
        }
        
        for(int i = 1; i <= N; ++i)
        {
            if(balance[i] == N - 1)
            {
                return i;
            }
        }
        
        return -1;
    }
};
