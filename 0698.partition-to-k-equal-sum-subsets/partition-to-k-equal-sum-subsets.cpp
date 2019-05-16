class Solution {
public:
    //常规题目要么只需要start,因为可以按顺序求解，所以可以减枝。要么只需要visit，因为无顺序求解，所以需要记录是否已经被访问过。
    //此题start和visit都需要。因为对于一个子解来说是按顺序求解，所以可以使用start来减少搜索空间。同时，visit记录的是是否当前位置已经组成了满足条件的子解了。
    //我觉得这道题目挺难的。
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0) return false;
        int target=sum/k;
        vector<bool> visit(nums.size(),false);
        return helper(nums,k,target,visit,0,0);
    }
    
    
    bool helper(vector<int>& nums, int k, int target, vector<bool> &visit, int partSum,int start){
        if(k==0) return true;
        if(partSum==target) return helper(nums,k-1,target,visit,0,0);
        for(int i=start;i<nums.size();i++){
            if(visit[i]) continue;
            if(target-partSum<nums[i]) continue;
            visit[i]=true;
            if(helper(nums,k,target,visit,partSum+nums[i],i+1)) return true; //只要有一个成功了就行了
            visit[i]=false;
        }
        return false;
    }
    
    

    /*int count;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        count=k;
        for(const auto &num:nums) sum+=num;
        if(sum%k!=0) return false;
        int part=sum/k;
        vector<bool> flags(nums.size(),false);
        return helper(nums,flags,0,part,0,k);
    }
    
    //起始点index是保证从每一个点都开始求解，这样避免了总是从0位置开始的贪心策略有问题。(我觉得这个才是本题的关键，是增大了搜索空间，解决了贪心策略的局限性。本题所有言论都是自己想的，我觉得网上的答案都没有get到这个点)------再次更新，这个点想错了。因为这个代码还是按照顺序进行搜索的，所以是需要start的。
    
    bool helper(vector<int>& nums, vector<bool>& flags, int partSum, int target, int index, int count){
        if(count==0) return true; //只有在所有子集都满足条件的时候才返回true。
        if(partSum==target) return helper(nums,flags,0,target,0,count-1); //有一个子组满足条件了，现在要去寻找其他满足条件的子组
        for(int i=index;i<nums.size();i++){
            if(flags[i]) continue;
            if(nums[i]>target-partSum) continue;
            flags[i]=true;
            if(helper(nums,flags,partSum+nums[i],target,i+1,count)) return true;
            flags[i]=false; //如果不是满足终极条件了，就要尝试其他，因此flags要重置。
        }
        return false;
    }*/
    
};