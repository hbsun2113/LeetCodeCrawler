/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (45.38%)
 * Total Accepted:    160.5K
 * Total Submissions: 353.7K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given a non-empty array of integers, every element appears three times
 * except for one, which appears exactly once. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,3,2]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
 * 
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<32;i++){
            int count=0;
            for(const auto &n:nums){
                count+=(n>>i)&1;
            }
            res+=(count%3)<<i;
        }
        return res;
    }


    //参考别人做的：https://leetcode.com/problems/single-number-ii/discuss/43294/Challenge-me-thx
    int singleNumber1(vector<int>& nums) {
        int one=0,two=0;
        for(int i=0;i<nums.size();i++){
            one=(one^nums[i])&(~two);//one只保留出现一次的数字
            two=(two^nums[i])&(~one);//two只保存出现两次的数字
            //for循环的中间结果好像是没有实际意义的？
        }
        return one;
        
    }
};


