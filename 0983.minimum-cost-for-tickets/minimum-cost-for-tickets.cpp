class Solution {
public:
    // https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-983-minimum-cost-for-tickets/
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ddl=days.back();
        vector<int> req(ddl+1,0);
        vector<int> dp(ddl+1,0);
        for(const auto &d:days)
            req[d]=1;
        for(int i=1;i<=ddl;i++){
            if(!req[i]){
                dp[i]=dp[i-1];
                continue;
            }
            dp[i]=dp[i-1]+costs[0];
            dp[i]=min(dp[i],dp[max(0,i-7)]+costs[1]);
            dp[i]=min(dp[i],dp[max(0,i-30)]+costs[2]);
        }
        return dp.back();
    }
};