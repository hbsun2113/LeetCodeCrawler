class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n=costs.size();
        if(n==0) return 0;
        vector<vector<int>> dp(n,vector<int>(3,INT_MAX));
        unordered_map<int,vector<int>> um;
        um[0]={1,2};
        um[1]={0,2};
        um[2]={0,1};
        dp[0]=costs[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<3;j++){
                for(auto k:um[j]){
                    dp[i][j]=min(dp[i][j],costs[i][j]+dp[i-1][k]);
                }
            }
        }
        return *min_element(dp.back().begin(),dp.back().end());
    }
};