/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 *
 * https://leetcode.com/problems/number-complement/description/
 *
 * algorithms
 * Easy (62.12%)
 * Total Accepted:    102.4K
 * Total Submissions: 164.8K
 * Testcase Example:  '5'
 *
 * Given a positive integer, output its complement number. The complement
 * strategy is to flip the bits of its binary representation.
 * 
 * Note:
 * 
 * The given integer is guaranteed to fit within the range of a 32-bit signed
 * integer.
 * You could assume no leading zero bit in the integer’s binary
 * representation.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits),
 * and its complement is 010. So you need to output 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits), and
 * its complement is 0. So you need to output 0.
 * 
 * 
 */
class Solution {
public:
    // https://www.acwing.com/solution/LeetCode/content/384/
    // bitset可以输出数字的二进制表示
    // 直接对num取反是不可以的，因为前导0会变成1。而此题的含义是不反转前导0。
    // 我们要保持前导0:tot的二进制表示中，全部是0，只有num的最高位为1。(tot-1)最高位左面全是0，右面全是1。
    int findComplement(int num) {
        int tot;
        for (int i = num; i; i -= i & -i)
            tot = i & -i;
        // cout<<bitset<32>(tot-1)<<endl;
        return ~num & (tot - 1);
    }


    int findComplement1(int num) {
        vector<int> vec;
        while(num>0){
            vec.push_back(1-(num&1));
            num=(num>>1);
        }
        long long base=1;
        long long res=0;
        for(int i=0;i<vec.size();i++){
            res+=vec[i]*base;
            base*=2;
        }
        return res;
    }
};

