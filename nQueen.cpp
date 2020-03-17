class Solution {
public:
    bool canPlaceQueen(const int k,const int i, vector<int> &rows)
    {
        //rows[j] -> Refers to the column information
        //k       -> The row information
        //i       -> The column information
        for(int j = 0; j <= k - 1; ++j)
        {
            if((rows[j] == i) || (abs(rows[j] - i) == abs(j - k)))
            {
                return false;   
            }
        }
        return true;
    }
    
    int backtrack(int k, int n, int &count,vector<int> &rows)
    {
        for(int i = 0; i < n; ++i)
        {
            if(canPlaceQueen(k,i,rows))
            {
                rows[k] = i;
                if(k == n - 1)
                {
                     ++count;
                }
                else
                {
                    backtrack(k+1,n,count,rows);
                }
            }
        }
        return count;
    }
    
    int totalNQueens(int n) 
    {
        vector<int> rows(n,0);
        int count = 0;
        int k = 0;
        
        return backtrack(k,n,count,rows);
    }
};
