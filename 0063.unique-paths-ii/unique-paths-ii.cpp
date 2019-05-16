class Solution {
public:
    //二刷，动归问题以后还是尽量long long吧
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==1 && obstacleGrid[0].size()==1 && obstacleGrid[0][0]==0) return 1;
        if(obstacleGrid.size()==1 && obstacleGrid[0].size()==1 && obstacleGrid[0][0]==1) return 0;
        vector<vector<long long>> res(obstacleGrid.size(),vector<long long>(obstacleGrid[0].size(),0));
        res[0][0]=obstacleGrid[0][0]==0;
        for(int i=0;i<obstacleGrid.size();i++){
            for(int j=0;j<obstacleGrid[i].size();j++){
                if(i-1>=0 && obstacleGrid[i-1][j]!=1) res[i][j]+=res[i-1][j];
                if(j-1>=0 && obstacleGrid[i][j-1]!=1) res[i][j]+=res[i][j-1];
                if(obstacleGrid[i][j]==1) res[i][j]=0;
            }
        }
        return res.back()[res.back().size()-1];
    }
    
    
    
    int uniquePathsWithObstacles1(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==1 && obstacleGrid[0].size()==1 && obstacleGrid[0][0]==0) return 1;
        if(obstacleGrid.size()==1 && obstacleGrid[0].size()==1 && obstacleGrid[0][0]==1) return 0;
        vector<vector<int>> res(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
        for(int i=0;i<obstacleGrid.size();i++)
            res[i][0]=obstacleGrid[i][0]==0;
        for(int j=0;j<obstacleGrid[0].size();j++)
            res[0][j]=obstacleGrid[0][j]==0;
        for(int i=1;i<obstacleGrid.size();i++){
            for(int j=1;j<obstacleGrid[i].size();j++){
                if(i-1>=0 && obstacleGrid[i-1][j]!=1) res[i][j]+=res[i-1][j];
                if(j-1>=0 && obstacleGrid[i][j-1]!=1) res[i][j]+=res[i][j-1];
                if(obstacleGrid[i][j]==1) res[i][j]=0;
            }
        }
        return res.back()[res.back().size()-1];
    }
};