class Solution {
public:
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        if(row==0) return;
        int col=board[0].size();
        
        for(int i=0;i<row;i++){
            dfs(board,i,0);
            dfs(board,i,col-1);
        }
        
        for(int i=0;i<col;i++){
            dfs(board,0,i);
            dfs(board,row-1,i);
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='#') board[i][j]='O';
                else board[i][j]='X';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board,int x, int y){
        if(board[x][y]!='O') return;
        board[x][y] = '#';
        for(int k=0;k<4;k++){
            int xx=x+dx[k];
            int yy=y+dy[k];
            if(xx>=0 && xx<board.size() && yy>=0 && yy<board[0].size() && board[xx][yy]=='O') 
                dfs(board,xx,yy);
        }
    }
};