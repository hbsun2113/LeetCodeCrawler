class Solution {
public:
    // https://leetcode.com/problems/guess-number-higher-or-lower-ii/discuss/84762/Improve-the-Question-and-Example
    // https://leetcode.com/problems/guess-number-higher-or-lower-ii/discuss/84764/Simple-DP-solution-with-explanation~~?orderBy=most_votes
    
    // top-down
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));
        return dfs(1,n,dp);   
    }
    
    
    int dfs(int l, int r, vector<vector<int>> &dp){
        if(l>=r) return 0;
        if(dp[l][r]!=INT_MAX) return dp[l][r];
        for(int k=l;k<=r;k++){
            dp[l][r]=min(dp[l][r],k+max(dfs(l,k-1,dp),dfs(k+1,r,dp))); // 选完x后，要么大了，要么小了。即要么去左区间，要么去右区间，取较大者。
        }
        return dp[l][r];
    }
    
    
    // bottom-up
    // dp[l][r]=min(dp[l][r],k+max(dp[l][k-1],dp[k+1][r])) 因此要从左面、下面寻求答案。左面对应列，因此j要从小到大；下面对应行，因此i要从大到小
    int getMoneyAmount1(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                if(i==j){
                    dp[i][j]=0;
                    continue;
                } 
                if(i==j-1){
                    dp[i][j]=min(i,j);
                    continue;
                }
                
                for(int k=i+1;k<=j-1;k++){
                    // cout<<i<<":"<<k-1<<" "<<k+1<<":"<<j<<endl;
                    dp[i][j]=min(dp[i][j],k+max(dp[i][k-1],dp[k+1][j]));
                }
            }
        }
        return dp[1][n];
    }
};
/*
来源于https://leetcode.com/problems/guess-number-higher-or-lower-ii/discuss/84764/Simple-DP-solution-with-explanation~~?orderBy=most_votes
中的一个高赞comment

More readable and easy to write bottom up solution:

1. why make the size (n + 2)*(n + 2)?
    The edge cases we need to deal with are:
    For M[1][?], when k = 1, then the induction rule will need M[0][n] which should be ignored. We solve this by marking it as 0(i.e. M[0][?] = 0 or just not set the value which makes it 0 default)
    For M[?][n], when k = n, then the induction rule will need M[n + 1][n] which is indexOutOfBound and should be ignored. We solve this by expanding the 2D DP matrix size to (n + 2) * (n + 2)
    
    
2. How to write the two for loops?
If we draw the matrix, then according to the induction rule: M[i][j] = k + Math.max(M[i][k - 1], M[k + 1][j]) for k = [i : j], we notice that M[i][k - 1] is in the left of M[i][j], and M[k + 1][j] is to the bottom of M[i][j]. So we need to compute these value before calculating M[i][j]. So we write the matrix from left to right, from bottom to top and since i <= j, so we can just iterate half of matrix by starting j from i.

*/