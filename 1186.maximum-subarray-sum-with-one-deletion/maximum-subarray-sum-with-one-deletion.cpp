class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<vector<long long>> dp(n+1,vector<long long>(2));
        dp[0][1]=dp[0][0]=INT_MIN;   // dp[i][0]????? dp[i][1]???????
        long long res=INT_MIN+0ll-1;
        for(int i=1;i<=n;i++){
            dp[i][0]=max(arr[i-1]+0ll,dp[i-1][0]+arr[i-1]);
            dp[i][1]=max(dp[i-1][1]+arr[i-1],dp[i-1][0]);
            res=max(res,dp[i][0]);
            res=max(res,dp[i][1]);
        }
        return res;
    }
};