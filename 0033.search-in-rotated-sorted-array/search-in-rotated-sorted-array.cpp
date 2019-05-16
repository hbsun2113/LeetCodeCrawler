class Solution {
public:
    // 还是老模板好用啊
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        if(nums[0]<=nums.back()) return binary_search(nums,-1,nums.size(),target); // 有顺序的，直接二分即可
        
        int v=nums[0];
        int l=0,r=nums.size();
        while(l+1!=r){
            int mid=(r+l)/2;
            if(nums[mid]>v) l=mid;
            else r=mid;
        }
        cout<<nums[r]<<endl;
        
        if(target<nums[r]) return -1;
        if(target<v)
            return binary_search(nums,r-1,nums.size(),target);
        else 
            return binary_search(nums,-1,r,target);
        
    }
    
    int binary_search(vector<int>& nums, int l, int r, int target){
        while(l+1!=r){
            int mid=(l+r)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) l=mid;
            else r=mid;
        }
        return -1;
    }
};