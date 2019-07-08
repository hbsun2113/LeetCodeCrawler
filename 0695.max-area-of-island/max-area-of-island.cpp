class Solution {
public:
    int res,row,col;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row=grid.size();
        if(row==0) return 0;
        col=grid[0].size();
        
        int cur=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1) dfs(grid,i,j,cur);
                cur=0;
            }
        }
        return res;
    }
    
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    
    void dfs(vector<vector<int>>& grid, int xx, int yy, int &cur){
        grid[xx][yy]=0;
        res=max(res,cur+1);
        for(int k=0;k<4;k++){
            int x=xx+dx[k];
            int y=yy+dy[k];
            if(x<0 || x>=row || y<0 || y>=col || grid[x][y]==0) continue;
            cur+=1;
            dfs(grid,x,y,cur);
        }
    }
};