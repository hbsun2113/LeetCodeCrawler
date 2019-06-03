class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<32;i++){
            int count=0;
            for(const auto &n:nums){
                count+=(n>>i)&1;
            }
            res+=(count%3)<<i;
        }
        return res;
    }


    //参考别人做的：https://leetcode.com/problems/single-number-ii/discuss/43294/Challenge-me-thx
    int singleNumber1(vector<int>& nums) {
        int one=0,two=0;
        for(int i=0;i<nums.size();i++){
            one=(one^nums[i])&(~two);//one只保留出现一次的数字
            two=(two^nums[i])&(~one);//two只保存出现两次的数字
            //for循环的中间结果好像是没有实际意义的？
        }
        return one;
        
    }
};


