/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (27.66%)
 * Total Accepted:    159.5K
 * Total Submissions: 576.1K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * Note:
 * 
 * You can assume that you can always reach the last index.
 * 
 */
class Solution {
public:
    // https://www.cnblogs.com/lichen782/p/leetcode_Jump_Game_II.html
    int jump(vector<int>& nums) {
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
};

