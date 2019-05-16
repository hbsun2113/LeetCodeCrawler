/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (41.71%)
 * Total Accepted:    217.4K
 * Total Submissions: 521.2K
 * Testcase Example:  '1'
 *
 * Given an integer, write a function to determine if it is a power of two.
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: true 
 * Explanation: 2^0 = 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 16
 * Output: true
 * Explanation: 2^4 = 16
 * 
 * Example 3:
 * 
 * 
 * Input: 218
 * Output: false
 * 
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return (n&(-n))==n;

    }

    //自己的理解，有点做麻烦了。
    bool isPowerOfTwo2(int n) {
        if(n<=0) return false;
        int bit;
        while(n!=0){
            bit=n%2;
            n=(n>>1);
            if(bit==1) break;
        }
        if(n==0) return true;
        return false;
    }
};

