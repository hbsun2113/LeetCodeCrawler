class Solution {
public:
    //如此简单实现的问题都没有想出来，最近有点浮躁啊！
    //https://leetcode.com/problems/increasing-triplet-subsequence/discuss/78993/Clean-and-short-with-comments-C++
    bool increasingTriplet(vector<int>& nums) {
        int c1=INT_MAX,c2=INT_MAX;
        for(const auto &n:nums){
            if(n<=c1){
                c1=n;
            }else if(n<=c2){
                c2=n;
            }else{
                return true; //此时c1、c2都确定了，x是c3。
            }
        }
        return false;
    }
};