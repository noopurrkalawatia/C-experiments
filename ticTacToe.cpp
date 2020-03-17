class TicTacToe {
    private:
    vector<int> rows;
    vector<int> cols;
    int size;
    int diagonal;
    int antidiagonal;
    
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : size(n)
    {
        rows.resize(n,0);
        cols.resize(n,0);
        antidiagonal = 0;
        diagonal = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) 
    {
        if(1 == player)
        {
            ++rows[row];
            ++cols[col];
            
            if(row == col)
            {
                ++diagonal;
            }
            if(row == size - col - 1)
            {
                ++antidiagonal;
            }
            
            if(rows[row] == size || cols[col] == size || diagonal == size || antidiagonal == size)
            {
                return 1;
            }
        }
        else
        {
             --rows[row];
             --cols[col];
            
            if(row == col)
            {
                --diagonal;
            }
            if(row == size - col - 1)
            {
                --antidiagonal;
            }
            
            if(abs(rows[row]) == size || abs(cols[col]) == size || abs(diagonal) == size || abs(antidiagonal) == size)
            {
                return 2;
            }
        }
        
        // cout << "Info : " << endl;
        // cout << "rows[row] : " << rows[row] << endl;
        // cout << "cols[col] : " << cols[col] << endl;
        // cout << "diagonal : " << diagonal << endl;
        // cout << "antidiagonal : " << antidiagonal << endl;
        // cout << "----------------------------------------------------" << endl;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
