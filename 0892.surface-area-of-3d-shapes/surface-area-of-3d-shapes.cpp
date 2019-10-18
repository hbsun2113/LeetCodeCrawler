class Solution {
public:
    // https://leetcode.com/problems/surface-area-of-3d-shapes/discuss/163414/C++Java1-line-Python-Minus-Hidden-Area
    int surfaceArea(vector<vector<int>>& grid) {
        int res=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                // ???for??????if
                if(grid[i][j]) res+=grid[i][j]*4+2; // ????????????
                if(i-1>=0) res-=min(grid[i][j],grid[i-1][j])*2;
                if(j-1>=0) res-=min(grid[i][j],grid[i][j-1])*2;
            }
        }
        return res;
    }
};