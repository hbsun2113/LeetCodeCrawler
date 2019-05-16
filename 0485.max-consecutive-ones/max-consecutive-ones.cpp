class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int result=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] && nums[i]){
                nums[i]=nums[i-1]+1;
            }
            result=max(result,nums[i]);
        }
        
        return result;
    }
};