class Solution {
public:
    //双指针使得问题由O(n^3)变成了O(n^2),这个思想要学会啊！已经不止遇到一次了呀。
    int threeSumClosest(vector<int>& nums, int target) {
        int result=nums[0]+nums[1]+nums[2];
        int diff=abs(result-target);
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size()-3;i++){
            int a=nums[i];
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                int sum=a+nums[left]+nums[right];
                if(abs(sum-target)<diff){
                    diff=abs(sum-target);
                    result=sum;
                }
                if(sum>target) right--;
                else if(sum<target) left++;
                else return sum;
            }
        }
        return result;
    }
};