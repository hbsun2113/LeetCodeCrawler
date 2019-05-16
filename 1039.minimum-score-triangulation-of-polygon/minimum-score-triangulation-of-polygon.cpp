class Solution {
public:
    // bottom-up
    // https://leetcode.com/problems/minimum-score-triangulation-of-polygon/discuss/286705/JavaC++Python-DP？
    int minScoreTriangulation(vector<int>& A) {
        vector<vector<int>> dp(53,vector<int>(53,0));
        for(int d=2;d<A.size();d++){
            for(int i=0;i+d<A.size();i++){
                int j=i+d;
                dp[i][j]=INT_MAX;
                for(int k=i+1;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+A[i]*A[k]*A[j]);
                }
            }
        }
        return dp[0][A.size()-1];
    }
    
    
    
    
    // top-down
    // https://leetcode.com/problems/minimum-score-triangulation-of-polygon/discuss/286753/c-with-picture
    int minScoreTriangulation1(vector<int>& A) {
        vector<vector<int>> dp(53,vector<int>(53,0));
        return helper(0,A.size()-1,A,dp);
    }
    
    int helper(int s, int e, vector<int>& A, vector<vector<int>> &dp){
        if(e-s<=1) return 0;
        if(dp[s][e]!=0) return dp[s][e];
        int res=INT_MAX;
        for(int i=s+1;i<e;i++){
            // cout<<res<<" "<<helper(s,i,A,dp)<<" "<<helper(i,e,A,dp)<<" "<<A[s]*A[i]*A[e]<<endl;
            res=min(res,helper(s,i,A,dp)+helper(i,e,A,dp)+A[s]*A[i]*A[e]);
        }
        dp[s][e]=res;
        return res;
    }
};