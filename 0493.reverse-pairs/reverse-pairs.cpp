class Solution {
public:
    // 模板题：https://leetcode.com/problems/reverse-pairs/discuss/97268/General-principles-behind-problems-similar-to-%22Reverse-Pairs%22?orderBy=most_votes
    int reversePairs(vector<int>& nums) {
        return merge(nums,0,nums.size()-1);
    }
    
    int merge(vector<int>& nums, int l, int r){
        if(l>=r) return 0;
        int mid=l+r>>1;
        int res=merge(nums,l,mid)+merge(nums,mid+1,r);
        vector<int> tmp(r-l+1);
        int i=l,j=mid+1,k=0,p=mid+1;
        while(i<=mid){
            while(p<=r && nums[i]>2ll*nums[p]) p++;
            res+=(p-(mid+1));
            while(j<=r && nums[j]<=nums[i]) tmp[k++]=nums[j++];
            tmp[k++]=nums[i++];
        }
        while(j<=r) tmp[k++]=nums[j++];
        copy(tmp.begin(), tmp.end(), nums.begin() + l); 
        return res;
    }
    
    
};