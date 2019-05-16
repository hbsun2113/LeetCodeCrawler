class Solution {
public:
    //自己做的，比较简单，使用了recursion，不符合题意了。
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        if(n==1) return true;
        if(n%3!=0) return false;
        return isPowerOfThree(n/3);
    }
    
    //这个解法也比较有意思。先找到最大的power of three，设为x，由于x都是3组成的，因此如果n也是power of three，则n必能被x整除。
    //https://leetcode.com/problems/power-of-three/discuss/77856/1-line-java-solution-without-loop-recursion
    //但是这个方法只适用于base是质数的情况，不适用于2或者4这些数字。
    

};