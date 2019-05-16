class Solution {
public:
    //自己做的，针对每个陆地看看它的有效边有多少个。如果该边和其他陆地相邻，那就是无效边
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int res=0;
        for(int x=0;x<row;x++){
            for(int y=0;y<col;y++){
                res+=part(row,col,x,y,grid);
            }
        }
        return res;
        
    }
    
    int part(int row, int col, int x, int y, vector<vector<int>>& grid){
        if(grid[x][y]==0) return 0;
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        int res=4;
        for(int k=0;k<4;k++){
            int xx=x+dx[k];
            int yy=y+dy[k];
            if(xx>=0 && xx<row && yy>=0 && yy<col && grid[xx][yy]==1) res--;
        }
        return res;
    }
};