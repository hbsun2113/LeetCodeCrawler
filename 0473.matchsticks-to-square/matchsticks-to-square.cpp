class Solution {
public:
    // 二刷：
    // 解释一下为什么逆序可以节省时间：假如其中一个解是[1,2,4](target是7),然后还有其他备选例如[5]。如果我先持有4则直接把5排除了，但如果我先持有1则无法排除5。
    vector<bool> vis;
    bool makesquare(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%4!=0) return false;
        sort(nums.rbegin(),nums.rend());
        vis.resize(nums.size(),true);
        return dfs(nums,sum/4,0,0);
    }
    
    bool dfs(vector<int>& nums, int target, int sum, int count){
        if(count==4) return true;
        if(sum>target) return false;
        if(sum==target) return dfs(nums,target,0,count+1);
        for(int i=0;i<nums.size();i++){
            if(!vis[i]) continue;
            if(sum+nums[i]>target) return false; //这个没懂。
            vis[i]=false;
            if(dfs(nums,target,sum+nums[i],count)) return true;
            vis[i]=true;
        }
        return false;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //这道题目是自己写的，但是TLE。 改为逆序排列立马就过了，没懂，感觉是侥幸过的。
    vector<bool> flag;
    bool makesquare1(vector<int>& nums) {
        if(nums.size()==0) return false;
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%4!=0) return false;
        sort(nums.rbegin(),nums.rend());  //注意要逆序！！！
        // cout<<nums[0]<<" "<<nums.back()<<endl;
        flag.resize(nums.size(),true); 
        int target=sum/4;
        return helper(nums, 0,target,0);
    }
    
    bool helper(vector<int>& nums, int count, int target, int curr){
        if(count==4) return true;
        if(curr>target) return false;
        if(curr==target) return helper(nums, count+1,target,0);
        for(int i=0;i<nums.size();i++){
            if(!flag[i]) continue;
            if(curr+nums[i]>target) return false; //这个也没懂。
            flag[i]=false;
            if(helper(nums, count,target,curr+nums[i])) return true;
            flag[i]=true;
        }
        return false;
    }
};