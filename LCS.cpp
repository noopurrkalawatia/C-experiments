class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m = text1.size();
        int n = text2.size();
        
        int LCS[1024][1024];
        
        for(int i = 0 ; i <= m ; ++i)
        {
            LCS[i][n] = 0;
        }
        
        for(int i = 0 ; i <= n; ++i)
        {
            LCS[m][i] = 0;
        }
        
        for(int i = m - 1; i >= 0; --i)
        {
            for(int j = n - 1; j >= 0; --j)
            {
                LCS[i][j] = LCS[i+1][j+1];
                
                if(text1[i] == text2[j])
                {
                    LCS[i][j]++;
                }
                
                if(LCS[i+1][j] > LCS[i][j])
                {
                    LCS[i][j] = LCS[i+1][j];
                }
                
                if(LCS[i][j+1] > LCS[i][j])
                {
                    LCS[i][j] = LCS[i][j+1];
                }
            }
        }
        return LCS[0][0];
    }
};
