class Solution {
public:
    // ?????https://leetcode.com/problems/longest-palindromic-substring/
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,1));
        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(i==j-1){ // ???1??2????????
                    if(s[i]==s[j]) dp[i][j]=2;
                    continue;
                }
                if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                // cout<<s.substr(i,l)<<" "<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        return dp[0][n-1];
    }
};