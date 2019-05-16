class Solution {
public:
    //自己硬写的解法会超时
    //参考了https://leetcode.com/problems/binary-subarrays-with-sum/discuss/186683/C++JavaPython-Straight-Forward
    //看看人家！前序和的思想运用得很好！
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int,int> um;
        um[0]=1;
        int presum=0,result=0;
        for(const auto &a:A){
            presum+=a;
            result+=um[presum-S];
            um[presum]++;
        }
        return result;
    }
};