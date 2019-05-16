const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
    int res;
    int numIslands(vector<vector<char>>& grid) {
        res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    res++;
                    dfs(grid,i,j);
                }
                
            }
        }
        return res;
    }
    
    
    void dfs(vector<vector<char>>& grid, int x, int y){
        grid[x][y]='2';
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};
        for(int k=0;k<4;k++){
            int xx=x+dx[k];
            int yy=y+dy[k];
            if(xx>=0 && xx<grid.size() && yy>=0 && yy<grid[0].size() && grid[xx][yy]=='1'){
               dfs(grid,xx,yy);
            }
        }
    }
};