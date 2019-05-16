/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (22.30%)
 * Total Accepted:    136.9K
 * Total Submissions: 614K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * Example:
 * 
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * After running your function, the board should be:
 * 
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * Explanation:
 * 
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 */
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        if(row==0) return ;
        int col=board[0].size();
        for(int i=0;i<board.size();i++){
            dfs(board,i,0);
            dfs(board,i,col-1);
        }
        for(int i=0;i<col;i++){
            dfs(board,0,i);
            dfs(board,row-1,i);
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='.') board[i][j]='O';
                else board[i][j]='X'; 
            }
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y){
        if(board[x][y]!='O') return ;
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};
        for(int k=0;k<4;k++){
            int xx=x+dx[k];
            int yy=y+dy[k];
            board[x][y]='.';
            if(xx>=0 && xx<board.size() && yy>=0 && yy<board[0].size() && board[xx][yy]=='O'){
                dfs(board,xx,yy);
            }
        }
    }
};

