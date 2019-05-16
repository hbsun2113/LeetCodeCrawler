class Solution {
public:
    // 二刷，做了挺久
    int row;
    int col;
    bool exist(vector<vector<char>>& board, string word) {
        row=board.size();
        col=board[0].size();
        vector<vector<bool>> vis(row,vector<bool>(col,true));
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++){
                if(dfs(board,vis,word,0,i,j)) return true;
            }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, string &word, int index, int x, int y){
        
        if(index==word.size()) return true;
        if(x<0 || x>=row || y<0 || y>=col || vis[x][y]==false) return false;
        if(word[index]!=board[x][y]) return false;
        
        vector<int> dx{0,0,1,-1};
        vector<int> dy{1,-1,0,0};
        
        vis[x][y]=false;
        for(int k=0;k<4;k++){
            int xx=x+dx[k];
            int yy=y+dy[k];
            if(dfs(board,vis,word,index+1,xx,yy)) return true;
        }
        vis[x][y]=true;
        
        return false;
    }
    
    
    /*
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visit(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++){
                if(helper(board,visit,word,0,i,j)) return true;
            }
        return false;
    }
    
    
    bool helper(vector<vector<char>>& board, vector<vector<bool>>& visit, string word, int index, int x, int y){
        if(index==word.size()) return true;
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || visit[x][y]) return false;
        
        if(board[x][y]==word[index]){
            visit[x][y]=true;
            if(helper(board,visit,word,index+1,x+1,y) || 
               helper(board,visit,word,index+1,x-1,y) ||
               helper(board,visit,word,index+1,x,y+1) ||
               helper(board,visit,word,index+1,x,y-1) 
              ) return true;
            
        }
        visit[x][y]=false;
        return false;
        
    }*/
};