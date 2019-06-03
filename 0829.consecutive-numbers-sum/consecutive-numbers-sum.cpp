class Solution {
public:
    // https://leetcode.com/problems/consecutive-numbers-sum/discuss/209317/topic
    // https://www.acwing.com/solution/LeetCode/content/621/
    int consecutiveNumbersSum(int N) {
        int ans=0;
        for(int m=1;;m++){
            int mx=N-m*(m-1)/2;
            if(mx<=0) break;
            if(mx%m==0) ans++;
        }
        return ans;   
    }
};