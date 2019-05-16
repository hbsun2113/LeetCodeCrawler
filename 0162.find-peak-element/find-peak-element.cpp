class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int l=-1,r=nums.size();
        while(l+1!=r){
            int mid=l+(r-l)/2;
            if(mid==0 || nums[mid]>nums[mid-1]) l=mid;
            else r=mid;
        }
        return r-1;
        if(r-1<0) return 0;
        if(r==nums.size()) return r-1;
        if(nums[r]<nums[r-1]) return r-1;
        else return r;
        
        
        
    }
};