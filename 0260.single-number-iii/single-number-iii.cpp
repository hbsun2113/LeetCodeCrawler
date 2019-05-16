class Solution {
public:
    // 这是一个比较难的经典题目，自己凭空做肯定是做不出来的，记录一下。
    // 0. 定义最终的结果是a和b
    // 1. 首先我们把所有数字都抑或起来，得到的结果res==a^b；（其他的都成对抵消了：一个数抑或自己为0）
    // 2. res的二进制表示中所有为1的位都代表a和b在这个位置不同，假设a在这个位置为0，那b在这个位置就为1。
    // 3. 这个位置我们可以通过low_bit操作(https://www.acwing.com/solution/LeetCode/content/279/)得到(res_xor &= (-res_xor))，此时res_xor的二进制表示中只有1位为1，是原始res_xor中最右侧的1.
    // 4. 我们利用a和b的不同把他们区分出来。因此我们可以把整个集合分为两个阵营：一个阵营中该位置都为1,另一个阵营中该位置都为0。如此a和b肯定各在不同阵营。
    // 5. 我们在此遍历每个数，然后分情况抑或，最终得到了a和b。
    
    // 以上参考自： https://leetcode.com/problems/single-number-iii/discuss/68900/Accepted-C++Java-O(n)-time-O(1)-space-Easy-Solution-with-Detail-Explanations
     // Let a and b be the two unique numbers
     // XORing all numbers gets you (a xor b)
     // (a xor b) must be non-zero otherwise they are equal
     // If bit_i in (a xor b) is 1, bit_i at a and b are different.（bit_i指的是任意为1的位置）
     // Find bit_i using the low bit formula m & -m
     // Partition the numbers into two groups: one group with bit_i == 1 and the other group with bit_i == 0.
     // a is in one group and b is in the other.
     // a is the only single number in its group.
     // b is also the only single number in its group.
     // XORing all numbers in a's group to get a
     // XORing all numbers in b's group to get b
     // Alternatively, XOR (a xor b) with a gets you b.
    
     // http://www.cnblogs.com/grandyang/p/4741122.html
    vector<int> singleNumber(vector<int>& nums) {
        int res_xor=accumulate(nums.begin(), nums.end(), 0, bit_xor<int>()); // bit_xor<int>()这个操作要记住
        res_xor &= (-res_xor);  // low_bit操作，得到的数字的二进制表示中只有一个1，就是原始res中最右边的1
        int a=0, b=0;  //在我的认知内，任何数字和自己抑或之后都是本身
        for(const auto n:nums){
            if(n&res_xor)
                a ^= n;
            else
                b ^= n;
        }
        vector<int> res{a,b};
        return res;
    }
};