class Solution {
public:
    // https://leetcode.com/problems/poor-pigs/discuss/94266/Another-explanation-and-solution
    // https://www.acwing.com/solution/LeetCode/content/131/
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int res=0;
        while(  pow((minutesToTest/minutesToDie+1),res) < buckets ) res++;
        return res;
    }
};