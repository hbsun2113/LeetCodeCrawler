class Solution {
public:
    //4Sum和3Sum好像区别也不大。
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        if(nums.size()<4) return result;
        for(int i=0;i<nums.size()-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int a=nums[i];
            for(int j=i+1;j<nums.size()-2;j++){
                int b=nums[j];
                if(j!=i+1 && nums[j]==nums[j-1]) continue;//这个借鉴的就是上面那个大循环的条件，即第九行。
                int left=j+1;
                int right=nums.size()-1;
                while(left<right){
                    int sum=a+b+nums[left]+nums[right];
                    if(sum==target){
                        vector<int> part={a,b,nums[left],nums[right]};
                        result.push_back(part);
                        left++;
                        right--;
                        while(nums[left]==nums[left-1])left++;
                        while(nums[right]==nums[right+1])right--;
                    }
                    else if(sum<target) left++;
                    else if(sum>target) right--;
                        
                }
            }
        }
        return result;
    }
};