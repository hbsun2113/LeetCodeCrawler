class Solution {
public:
    //忘记了是几刷了，反正是一把过
    vector<vector<int>> res;
    vector<bool> flag;
    vector<int> tmp;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        flag.resize(nums.size(),true);
        helper(nums);
        return res;
    }
    
    void helper(vector<int>& nums){
        if(tmp.size()==nums.size()){
            res.push_back(tmp);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(!flag[i]) continue;
            if(i!=0 && nums[i-1]==nums[i] && flag[i-1]) continue;
            flag[i]=false;
            tmp.push_back(nums[i]);
            helper(nums);
            tmp.pop_back();
            flag[i]=true;
        }
    }
};