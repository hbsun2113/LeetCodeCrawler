class Solution {
public:
    // 三刷
    int findMin(vector<int>& nums){
        if(nums.size()==0) return 0;
        if(nums.back()>=nums[0]) return nums[0]; // 这行注意啊！！
        int l=0,r=nums.size();
        while(l+1!=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[0]) l=mid;
            else r=mid;
        }
        return nums[r];
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // 二刷了，还是没有做出来，https://www.acwing.com/solution/LeetCode/content/247/
    // 原来以为二分法的要求是序列必然有序，其实不然
    // 二分本质上是找分界点，分界点左边不满足某个性质，分界点右边满足某个性质, 不一定需要有序。
    // 这道题目中我们是要寻找第一个小于(等于)nums[0]的位置。注意我们这个写法是把分界点放到了右区间。
    int findMin1(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.back()>=nums[0]) return nums[0];
        // 注意这道题目的特殊性，由于nums[0]肯定不是最小值，所以是不在我们的搜索空间中的。
        // 原本l=-1,现在l=0就好了
        int l=0, r=nums.size();  
        int b=nums[0];  //baseline
        while(l+1!=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>b) l=mid; //左区间不满足条件，因此我们要调整左边界。
            else r=mid;  //左区间满足条件，因此我们只能调整右边界。
        }
        return nums[r];
    }
};