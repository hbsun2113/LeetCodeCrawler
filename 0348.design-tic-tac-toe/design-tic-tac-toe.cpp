class TicTacToe {
public:
    // https://leetcode.com/problems/design-tic-tac-toe/discuss/81898/Java-O(1)-solution-easy-to-understand
    /** Initialize your data structure here. */
    TicTacToe(int nn) {
        n=nn;
        rows.resize(nn,0);
        cols.resize(nn,0);
        shun=ni=0;
    }
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int t=player==1?1:-1;
        if(row==col){
            shun+=t;
            if(abs(shun)==n) return player;
        }
        if(row+col==n-1){
            ni+=t;
            if(abs(ni)==n) return player;
        }
        
        rows[row]+=t;
        if(abs(rows[row])==n) return player;
        
        cols[col]+=t;
        if(abs(cols[col])==n) return player;
        
        return 0;
    }
    
    vector<int> rows,cols;
    int n;
    int shun,ni;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */