class Solution {
    private:
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    int rows, cols;
    
public:
    int dfs(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &cache)
    {
        if(cache[i][j] != 0)
        {
            return cache[i][j];
        }
        int ans = 0;
        
        for(auto dir : directions)
        {
            int x = i + dir[0];
            int y = j + dir[1];
            
            if((0 <= x && x < rows) && (0 <= y && y < cols) && (matrix[x][y] > matrix[i][j]))
            {
                cache[i][j] = max(cache[i][j],dfs(matrix,x,y,cache));
            }
        }
        
        return ++cache[i][j];
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        if(matrix.size() == 0)
        {
            return 0;
        }
        int ans = 0;
        rows = matrix.size();
        cols = matrix[0].size();
        vector<vector<int>> cache(rows,vector<int>(cols,0));
        
        for(int i = 0 ;i < rows; ++i)
        {
            for(int j = 0 ;j < cols; ++j)
            {
                ans = max(ans, dfs(matrix,i,j,cache));
            }
        }
        return ans; 
    }
};
