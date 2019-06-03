class Solution {
public:
    vector<vector<bool>> vis;
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    int row,col;
    bool exist(vector<vector<char>>& board, string word) {
        row=board.size();
        if(row==0) return false;
        col=board[0].size();
        if(row*col<word.size()) return false;
        vis.clear();
        vis.resize(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(dfs(board,vis,word,i,j,0)) return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, vector<vector<bool>> &vis, string &word, int x, int y, int i){
        if(board[x][y]!=word[i]) return false;
        if(i==word.size()-1) return true;
        vis[x][y]=true;
        for(int k=0;k<4;k++){
            int xx=x+dx[k];
            int yy=y+dy[k];
            if(xx<0 || xx>=row || yy<0 || yy>=col || vis[xx][yy]) continue;
            if(dfs(board,vis,word,xx,yy,i+1)) return true;
        }
        vis[x][y]=false;
        return false;
    }
};