class Solution {
public:
    int ori;
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        vector<vector<int>> res(grid);
        ori=grid[r0][c0];
        dfs(grid,r0,c0,color,res);
        return res;
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y, int color, vector<vector<int>>& res){
        // cout<<x<<" "<<y<<endl;
        if(res[x][y]==color || grid[x][y]=='*') return;
        if(judge(grid,x,y))
            res[x][y]=color;
        grid[x][y]='*';
        for(int k=0;k<4;k++){
            int xx=x+dx[k];
            int yy=y+dy[k];
            if(xx<0 || xx>=grid.size() || yy<0 || yy>=grid[0].size() || res[xx][yy]!=ori) continue;
            dfs(grid,xx,yy,color,res);
        }
    }
    
    bool judge(vector<vector<int>>& grid, int x, int y){
        for(int k=0;k<4;k++){
            int xx=x+dx[k];
            int yy=y+dy[k];
            if(xx<0 || xx>=grid.size() || yy<0 || yy>=grid[0].size() || (grid[xx][yy]!=ori && grid[xx][yy]!='*')) return true;
        }
        return false;
    }
};