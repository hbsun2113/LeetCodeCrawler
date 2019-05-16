class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()<=1) return nums.back();
        int res=max(nums[0],nums[1]);
        nums[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            nums[i]=max(nums[i]+nums[i-2],nums[i-1]);
            res=max(nums[i],res);
        }
        return res;
    }
    
    int rob1(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> vec(nums.size()+1);
        vec[0]=0;
        vec[1]=nums[0];
        for(int i=2;i<vec.size();i++){
            vec[i]=max(vec[i-1],vec[i-2]+nums[i-1]);
        }
        return vec.back();
    }
};

