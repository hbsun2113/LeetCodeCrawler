class Solution {
public:
    // 这次踩了坑，做得超慢，因为忽略了恢复状态。
    // 以后还是采用一刷的方式吧
    void solveSudoku(vector<vector<char>>& board) {
        cout<<dfs(board,0,0)<<endl;
    }
    
    bool dfs(vector<vector<char>>& board, int r, int c){
        if(r==9) return true;
        if(c==9) return dfs(board,r+1,0);
        if(board[r][c]!='.') return dfs(board,r,c+1);
        for(int i=1;i<=9;i++){
            char op=('0'+i);
            if(!judge(board,r,c,op)) continue;
            board[r][c]=op;
            if(dfs(board,r,c+1)) return true;
            board[r][c]='.'; // 千万要记得恢复状态啊！！
        }
        return false;
    }
    

    bool judge(vector<vector<char>>& board, int r, int c ,char op){
        for(int i=0;i<9;i++){
            if(board[i][c]==op && i!=r) return false;
            if(board[r][i]==op && i!=c) return false;
        }
        int bx=r/3*3,by=c/3*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int x=bx+i;
                int y=by+j;
                if((x==r) && (y==c)) continue;
                if(board[x][y]==op) return false;
            }
        }
        return true;
    }
    
    
    
    //哈哈，终于自己没有看任何提示做对了！
    void solveSudoku1(vector<vector<char>>& board) {
        helper(board,0,0);
    }
    
    bool helper(vector<vector<char>>& board, int row, int col){
        if(row>=board.size()) return true;
        if(col>=board[0].size()) return helper(board,row+1,0);
        if(board[row][col]!='.') return helper(board,row,col+1);
        for(int i=1;i<=9;i++){
            board[row][col]=('0'+i);
            if(check(board,row,col) && helper(board,row,col+1)) return true;
            board[row][col]='.';
        }
        return false;
    }
    
    bool check(vector<vector<char>>& board, int row, int col){
        for(int i=0;i<board[0].size();i++){
            if(i==col) continue;
            if(board[row][i]==board[row][col]) return false;
        }
            
        
        for(int i=0;i<board.size();i++){
            if(i==row) continue;
            if(board[i][col]==board[row][col]) return false;
        }
        
        int basex=row/3*3;
        int basey=col/3*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if((basex+i==row) && (basey+j==col)) continue;
                if(board[basex+i][basey+j]==board[row][col]) return false;
            }
        }
        
        return true;
    }
};