class Solution {
public:
    // https://leetcode.com/problems/4-keys-keyboard/discuss/105980/Java-4-lines-recursion-with-step-by-step-explanation-to-derive-DP
    // ??????Print ?????????Ctrl A, Ctrl C, Ctrl V 
    // ????????
    int maxA(int N) {
        vector<int> dp(N+1,0);
        for(int i=1;i<=N;i++){
            dp[i]=i;
            for(int j=1;i-j>=3;j++){ // i-j-3>=3?????????????? Ctrl A, Ctrl C, Ctrl V,??Ctrl V ???i-(j+1)+1>=3
                dp[i]=max(dp[i],dp[j]*(i-j+1-2)); // (i-j+1-2)? Ctrl V ???
            }
        }
        return dp.back();
    }
};