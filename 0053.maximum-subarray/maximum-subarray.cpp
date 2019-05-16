class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result=nums[0];
        int tmp=nums[0];
        for(int i=1;i<nums.size();i++){
            if(tmp<0) tmp=nums[i];
            else tmp+=nums[i];
            result=max(result,tmp);
        }
        return result;
    }
    
    // 还有分治法需要掌握：https://www.acwing.com/activity/content/problem/content/43/1/
    // 目前还理解得不透彻
};