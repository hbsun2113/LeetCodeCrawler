class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        vector<int> nums1(nums.begin(),nums.end()-1);
        vector<int> nums2(nums.begin()+1,nums.end());
        return max(helper(nums1),helper(nums2));
    }
    
    int helper(vector<int>& nums){
        vector<int> vec(nums.size()+1);
        vec[0]=0;
        vec[1]=nums[0];
        for(int i=2;i<vec.size();i++){
            vec[i]=max(vec[i-1],vec[i-2]+nums[i-1]);
        }
        return vec.back();
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //二刷
    int rob2(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        vector<int> t1(nums.begin()+1,nums.end());
        vector<int> t2(nums.begin(),nums.end()-1);
        return max(helper(t1),helper(t2));
    }
    
    
    int helper1(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int> res(nums.size());
        res[0]=nums[0];
        res[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            res[i]=max(res[i-1],res[i-2]+nums[i]);
        }
        return res[res.size()-1];
    }
    
};