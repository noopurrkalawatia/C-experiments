class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> result;
        
        
        if(matrix.empty())
        {
            return {};
        }
        
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0, k = 0, l = 0;
        
        if(row == 1)
        {
            return matrix[0];
        }
        /*
        row -> index of the last row
        col -> index of the last column
        k   -> index of the first row
        l   -> index of the last col
        */

        while(k < row, l < col)
        {
            for(i = l ; i < col; ++i)
            {
                result.push_back(matrix[k][i]);
            } 
            ++k; //increment the row. Now you are on the second row
            
            for(i = k; i < row; ++i)
            {
                result.push_back(matrix[i][col-1]);
            }
            --col;
            
            if(k < row)
            {
                for(i = col - 1; i >= l; --i)
                {
                    result.push_back(matrix[row-1][i]);
                }
                --row;
            }
            
            if(l < col)
            {
                for(i = row - 1; i >= k; --i)
                {
                    result.push_back(matrix[i][l]);
                }
                ++l;
            }  
        }
        
        return result;
    }
};
