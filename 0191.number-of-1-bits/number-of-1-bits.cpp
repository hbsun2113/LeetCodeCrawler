class Solution {
public:
    int hammingWeight1(uint32_t n) {
        int result=0;
        while(n!=0){
            result+=(n&1);
            n>>=1;
        }
        return result;
    }
    
    
    //总有人的解法比我好，还是太菜了
    //https://leetcode.com/problems/number-of-1-bits/discuss/55255/C++-Solution:-n-and-(n-1)
    //每次消除最右边的1，直到自己为0。
    int hammingWeight(uint32_t n) {
        int result=0;
        while(n!=0){
            n&=(n-1);
            result++;
        }
        return result;
    }
};