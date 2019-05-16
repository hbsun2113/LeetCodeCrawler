/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (35.63%)
 * Total Accepted:    78.7K
 * Total Submissions: 220.9K
 * Testcase Example:  '5\n7'
 *
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND
 * of all numbers in this range, inclusive.
 * 
 * Example 1:
 * 
 * 
 * Input: [5,7]
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1]
 * Output: 0
 */
class Solution {
public:
    // 暴力解法会超时
    // http://www.cnblogs.com/grandyang/p/4431646.html
    // https://www.acwing.com/solution/LeetCode/content/264/
    // 如果将m和n转换为二进制的形式，我们从左向右寻找m和n第一个不相同的位置,将左面共同的部分(设为x)保持不变，右面全置为0，就是答案。
    // 解释一下：从m上升到n的过程中，右面每个位都至少会有一次0的过程。
    int rangeBitwiseAnd(int m, int n) {
        int ind=0;
        while(m!=n){
            m>>=1;
            n>>=1;
            ind++;
        }    
        int res=m<<ind;
        // cout<<bitset<32>(res)<<" ";
        return res;
    }
};

