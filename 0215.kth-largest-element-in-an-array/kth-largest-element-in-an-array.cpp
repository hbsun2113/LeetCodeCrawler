class Solution {
public:
    // 三刷
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> p; // 最小堆
        for(const auto &n:nums){
            p.emplace(n);
            while(p.size()>k) p.pop();
        }
        return p.top();
    }
    
    int findKthLargest1(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }

    //讲解得很好，但我没有看完。
    int findKthLargest2(vector<int>& nums, int k) {
        //关于nth_element的解释：https://blog.csdn.net/dylan_frank/article/details/77893811
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
};