class Solution {
public:
    vector<vector<int>> dp;
    int row;
    int col;
    int maxDistance(vector<vector<int>>& grid) {
        row=grid.size();
        if(row==0) return  0;
        col=grid[0].size();
        dp.resize(row,vector<int>(col,INT_MAX));
        bool flag1=false;
        bool flag2=false;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,0);
                    flag1=true;
                } 
                else{
                    flag2=true;
                }
            }
        }
        
        if(flag1==false || flag2==false) return -1;
        
        
        int res=INT_MIN;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0){
                    res=max(res,dp[i][j]);
                } 
            }
        }
        
        return res;
    }

    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    void dfs(int x, int y, vector<vector<int>>& grid, int cur){
        dp[x][y]=cur;
        for(int k=0;k<4;k++){
            int xx=x+dx[k];
            int yy=y+dy[k];
            if(xx<0 || xx>=row || yy<0 || yy>=col || grid[xx][yy]==1 || dp[xx][yy]<=cur+1) continue;
            dfs(xx,yy,grid,cur+1);
        }
    }
    
    
};