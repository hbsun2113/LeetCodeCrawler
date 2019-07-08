class Solution {
public:
    // https://leetcode.com/problems/split-array-largest-sum/discuss/89817/Clear-Explanation:-8ms-Binary-Search-Java
    // 看到这道题目我首先想到数组划分的方式(比如以一个元素为起始位置，看看可以有多少个数组)，但是这样方案数恐怕太多，因此就要换种思路:寻找合适的子数组和,使得它可以将母数组恰好分为m个
    // subarrays的最小sum：nums各个元素分别为一个subarray，那么最小sum就是其中的最大值
    // subarrays的最大sum: nums为一个subarray,那么最大sum就是其中的最小值
    // 最后的结果一定是介于上述两者之间，因此可以使用二分法去搜索
    int splitArray(vector<int>& nums, int m) {
        long long l=*max_element(nums.begin(), nums.end());
        long long r=accumulate(nums.begin(),nums.end(),0ll);
        while(l<r){
            long long mid=0ll+l+r>>1; // 找到第一个符合条件的mid [l,mid] [mid+1,r]
            if(valid_array_count(nums,mid)<=m) r=mid; // 因为r=mid，所以mid也是符合条件的，因此有等于号
            else l=mid+1;
        }
        return r;
    }
    
    // 使得每个subarray尽量接近target，但是不超过target,然后返回总共的subarray数目
    // 如果数目超出了m，说明target太小了
    // 如果数目小于m，说明target太大了
    int valid_array_count(vector<int>& nums, long long target){
        int count=0;
        int i=0;
        long long sum=0;
        while(i<nums.size()){
            while(i<nums.size() && sum+nums[i]<=target) sum+=nums[i++];
            count++;
            sum=0;
        }
        return count;
    }
};