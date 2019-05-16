class Solution {
public:
    
    //还是别人的解法牛啊！双指针法。每次给定右边界j，去寻找左边的极限。
    int minSubArrayLen(int s, vector<int>& nums) {
        if(s>accumulate(nums.begin(),nums.end(),0)) return 0;
        int i=0,j=0,result=INT_MAX,sum=0;
        while(j<nums.size()){
            sum+=nums[j++];
            while(sum>=s){
                result=min(result,j-i);
                sum-=nums[i++]; //对于j以及大于j的右边界来说，当前的左边界i已经没有保存的意义了。
            }
        }
        return result;
    }
    
    
    
    
    //暴力解法竟然也可以过？！
    int minSubArrayLen1(int s, vector<int>& nums) {
        if(s>accumulate(nums.begin(),nums.end(),0)) return 0;
        int result=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int tmp=0;
            int sum=s;
            while(sum>0 && i+tmp<nums.size()){
                sum-=nums[i+tmp++];
            }
            if(sum<=0) result=min(result,tmp);
        }
        return result;
    }
};