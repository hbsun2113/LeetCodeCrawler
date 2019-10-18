class NumMatrix {
public:
    // ?????????????
    NumMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size();
        if(row==0) return ;
        int col=matrix[0].size();
        dp.resize(row+1,vector<int>(col+1,0));
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i-1][j-1];
            }
        }
        
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1]+dp[row1][col1]-dp[row2+1][col1]-dp[row1][col2+1];
    }
    
    vector<vector<int>> dp;
    
    
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */