class Solution {
public:
    string longestPalindrome(string s) 
    {
        if(s.size() == 0 || s.size() == 1)
        {
            return s;
        }
        
        int size = s.size(), start = 0, maxLen = 1;
        
        bool table[size][size];
        memset(table,0,sizeof(table));
        
        for(int i = 0 ; i < size; ++i)
        {
            table[i][i] = true;
        }
                
        for(int i = 0 ; i < size; ++i)
        {
            if(s[i] == s[i + 1])
            {
                table[i][i+1] = true;
                start = i;
                maxLen = 2;
            }
        }
        
        for(int k = 3; k <= size; ++k)
        {
            for(int i = 0 ; i < size - k + 1; ++i)
            {
                int j = i + k - 1;
                
                if(table[i+1][j-1] && s[i] == s[j])
                {
                    table[i][j] = true;
                    if(k > maxLen)
                    {
                        start = i;
                        maxLen = k;
                    }
                }
            }
        }
                
        return s.substr(start,maxLen);
    }
};
