class Solution {
public:
    // https://leetcode.com/problems/dungeon-game/discuss/52774/C++-DP-solution // ??dp????INT_MAX?
    // ?????????
    // dp[i][j]?????(i,j)??????health point,?????????nums[i][j]
    // ?????dp[i][j]????????dp[i+1][j]?dp[i][j+1]
    // dp[i+1][j]=dp[i][j]+nums[i][j]
    int calculateMinimumHP(vector<vector<int>>& nums) {
        if(nums.empty()) return 0;
        int row=nums.size(),col=nums[0].size();
        vector<vector<int>> dp(row,vector<int>(col));
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                if(i==row-1 && j==col-1){
                    dp[i][j]=max(1,1-nums[i][j]); // ????1????????????1?????????(i,j)
                    continue;
                }
                int t=INT_MAX;
                if(i+1<row) t=min(t,dp[i+1][j]-nums[i][j]);
                if(j+1<col) t=min(t,dp[i][j+1]-nums[i][j]);
                dp[i][j]=max(1,t); // ??t????INT_MAX
            }
        }
        return dp[0][0];
    }
};