class Solution {
public:
    //自己的解法，很水。（DFS）
    int findTargetSumWays1(vector<int>& nums, int S) {
        int index=0;
        int sum=0;
        int count=0;
        cal(nums,S,index,sum,count);
        return count;
    }
    
    void cal(const vector<int>& nums, const int &S, const int index, int sum,int &count){
        if(index==nums.size()){
            if(sum==S) count++;
            return ;
        }
        cal(nums,S,index+1,sum+nums[index],count);
        cal(nums,S,index+1,sum-nums[index],count);
        return ;
    }
    
    
    //DP：https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C++-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum<S) return false; //注意元素都是整数，因此如果全体加起来都不如S,肯定达不到要求。
        int target=S+sum;
        if(target%2==1) return 0;
        target>>=1;
        
        vector<int> flag(target+1);//flag[i]代表i可以被组成的次数。
        flag[0]=1;//首先0只能有一种选项，就是大家都不选。
        
        for(const auto &n:nums){
            //for(int i=n;i<=target;i++){
            for(int i=target;i>=n;i--){//注意顺序，是从后往前遍历，这样考虑：这次添加的是n,flag[i-n]代表的是之前没有n的情况下，i-n被组成的次数。
                    flag[i]+=flag[i-n];
            }
        }
        
        return flag[target];
    }
    
    
};