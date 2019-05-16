/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (47.78%)
 * Total Accepted:    258.3K
 * Total Submissions: 539.9K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */
class Solution {
public:
    // 位操作
    int missingNumber1(vector<int>& nums) {
        int res=0;
        for(int i=1;i<=nums.size();i++)
            res^=i;
        for(int i=0;i<nums.size();i++)
            res^=nums[i];
        return res;
    }
    
    // 数学做法
    int missingNumber(vector<int>& nums) {
        int len=nums.size();
        int res=(1+len)*len/2;
        return res-accumulate(nums.begin(),nums.end(),0);
    }


};

