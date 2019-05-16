class Solution {
public:
    // https://www.acwing.com/blog/content/31/#comment_226
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1,-1};
        if(nums.size()==0) return res;
        int l=0,r=nums.size()-1;
        while(l!=r){
            int mid=r+l>>1;
            if(nums[mid]>=target) r=mid;
            else l=mid+1;
        }
        if(nums[l]!=target) return res;
        res[0]=r;
        
        l=0,r=nums.size()-1;
        while(l!=r){
            int mid=r+l+1>>1;
            if(nums[mid]<=target) l=mid;
            else r=mid-1;
        }
        res[1]=r;
        return res;
    }
    
    
    //使用STL
    vector<int> searchRange2(vector<int>& nums, int target) {
        vector<int> res{-1,-1};
        if(nums.size()==0) return res;
        auto it1=lower_bound(nums.begin(),nums.end(),target); //寻找第一个等于或者“大于”target的位置
        if(it1==nums.end() || *it1!=target) return res;
        auto it2=upper_bound(nums.begin(),nums.end(),target); //寻找第一个“大于”target的位置
        res[0]=it1-nums.begin();
        res[1]=it2-nums.begin()-1;
        return res;
    }
    
    
    
    
    //标准的二分法。不对，这个解法不符合题目要求，是O(n)的解法
    vector<int> searchRange1(vector<int>& nums, int target) {
        vector<int> res{-1,-1};
        if(nums.size()==0) return res;
        long long l=-1, r=nums.size();
        while(l+1!=r){
            long long mid=l+(r-l)/2;
            // cout<<l<<" "<<r<<" "<<mid<<endl;
            if(nums[mid]<target) l=mid;
            else r=mid;
        }
        if(r==nums.size() || nums[r]!=target) return res;
        res[0]=r;
        while(r<nums.size() && nums[r]==nums[res[0]]) r++;
        r--;
        res[1]=r;
        return res;
    }
};