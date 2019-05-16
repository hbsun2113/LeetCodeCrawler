class Solution {
public:
    // https://leetcode.com/problems/partition-array-for-maximum-sum/discuss/290863/JavaC++Python-DP
    // dp[i]代表当有i+1个元素时，我们能取到的最大sum
    // 每增加一个元素i，我们只考虑它带来的影响：i所在数组是否会发生变化，进而是否会影响sum
    // 千万注意，可能i的值不改变，才是最优解）
    // lee215的提示：只要有array和max,就往dp上想
    // 我之前的想法是真正地去改数组中的元素，然后求和，那样会特别麻烦！！！
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int> dp(A.size());
        for(int i=0;i<A.size();i++){
            int mv=0;
            for(int k=1;k<=K && i-k+1>=0;k++){
                mv=max(mv,A[i-k+1]);
                dp[i]=max(dp[i],(i-k>=0?dp[i-k]:0)+mv*k);
            }
        }
        return dp.back();
    }
};