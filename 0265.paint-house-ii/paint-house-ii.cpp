class Solution {
public:
    // ???https://leetcode.com/problems/paint-house-ii/discuss/69492/AC-Java-solution-without-extra-space
    // ???m1?m2??????????
    int minCostII(vector<vector<int>>& costs) {
        int n=costs.size();
        if(n==0) return 0;
        int k=costs[0].size();
        vector<vector<int>> dp(n,vector<int>(k,INT_MAX));
        int m1=-1,m2=-1;
        for(int i=0;i<k;i++){
            dp[0][i]=costs[0][i];
            if(m1==-1 || dp[0][i]<dp[0][m1]){
                m2=m1; // ??????????????
                m1=i;
            }
            else if(m2==-1 || dp[0][i]<dp[0][m2])
                m2=i;
        }
            

        for(int i=1;i<n;i++){
            int x=m1,y=m2;
            m1=-1,m2=-1;
            for(int j=0;j<k;j++){
                if(x==j) dp[i][j]=dp[i-1][y]+costs[i][j];
                else dp[i][j]=dp[i-1][x]+costs[i][j];
                if(m1==-1 || dp[i][j]<dp[i][m1]){
                    m2=m1;
                    m1=j;
                } 
                else if(m2==-1 || dp[i][j]<dp[i][m2]) m2=j;
            }
        }
        
        return dp.back()[m1];
    }
};