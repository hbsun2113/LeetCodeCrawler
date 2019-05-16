class Solution {
public:
    // 自己做的。为了保证最小，每个点都只能从其上面或者其左面移动过来。
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=1;i<n;i++)
            grid[0][i]+=grid[0][i-1];
        for(int i=1;i<m;i++)
            grid[i][0]+=grid[i-1][0];
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid.back().back();
    }
};