class Solution {
public:
    const int mod=1e9+7;
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(d+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=d;i++){
            for(int j=1;j<=target;j++){
                for(int k=1;k<=f;k++){
                    if(j>=k) dp[i][j]=(dp[i][j]+dp[i-1][j-k])%mod;
                }
            }
        }
        return dp.back().back()%mod;
    }
};