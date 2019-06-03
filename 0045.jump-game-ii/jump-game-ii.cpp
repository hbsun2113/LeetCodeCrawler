class Solution {
public:
    // https://www.cnblogs.com/lichen782/p/leetcode_Jump_Game_II.html
    int jump1(vector<int>& nums) {
        int last=0;
        int curr=0;
        int step=0;
        for(int i=0;i<nums.size();i++){
            if(i>last){
                last=curr;
                step++;
            }
            curr=max(curr,i+nums[i]);
        }
        return step;
    }
    
    // https://www.acwing.com/solution/LeetCode/content/107/
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size());
        int last=0;
        for(int i=1;i<dp.size();i++){
            while(i>last+nums[last]) last++;
            dp[i]=dp[last]+1;
        }
        return dp.back();
    }
};

