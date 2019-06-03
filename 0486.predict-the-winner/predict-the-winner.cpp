class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        for(int i=1;i<=n;i++) dp[i][i]=nums[i-1];
        for(int l=2;l<=n;l++){
            for(int i=1;i+l-1<=n;i++){
                int j=i+l-1;
                // cout<<i<<" "<<j<<endl;
                dp[i][j]=max(nums[i-1]-dp[i+1][j],nums[j-1]-dp[i][j-1]);
            }
        }
        return dp[1][n]>=0;
    }
};