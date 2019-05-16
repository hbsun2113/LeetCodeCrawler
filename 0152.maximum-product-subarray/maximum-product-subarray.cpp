class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxproduct(nums.size()),minproduct(nums.size());
        maxproduct[0]=minproduct[0]=nums[0];
        int maxnum=nums[0];
        for(int i=1;i<nums.size();i++){
            maxproduct[i]=max(maxproduct[i-1]*nums[i],max(nums[i],minproduct[i-1]*nums[i]));
            minproduct[i]=min(maxproduct[i-1]*nums[i],min(nums[i],minproduct[i-1]*nums[i]));
            maxnum=max(maxnum,maxproduct[i]);
        }
        return maxnum;
    }
};