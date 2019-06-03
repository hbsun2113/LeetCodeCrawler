
class Solution {
public:
    // 位操作
    int missingNumber(vector<int>& nums) {
        int res=0;
        for(int i=1;i<=nums.size();i++)
            res^=i;
        for(int i=0;i<nums.size();i++)
            res^=nums[i];
        return res;
    }
    
    // 数学做法
    int missingNumber1(vector<int>& nums) {
        int len=nums.size();
        int res=(1+len)*len/2;
        return res-accumulate(nums.begin(),nums.end(),0);
    }


};

