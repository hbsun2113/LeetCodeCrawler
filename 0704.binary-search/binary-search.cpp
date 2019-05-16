class Solution {
public:
    //自己写的，但感觉不规范
    int search1(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int low=0,high=nums.size();
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) low=mid+1;
            else high=mid;
        }
        return -1;
    }
    
    
    int search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int low=-1,high=nums.size();
        while(low+1!=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) low=mid;
            else high=mid;
        }
        return -1;
        
    }
};