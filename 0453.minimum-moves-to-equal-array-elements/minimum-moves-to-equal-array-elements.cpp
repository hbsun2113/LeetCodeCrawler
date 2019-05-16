class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=*min_element(nums.begin(),nums.end());
        int len=nums.size();
        int res=0;
        for(const auto &num:nums)
            res+=(num-n);
        return res;
    }
};