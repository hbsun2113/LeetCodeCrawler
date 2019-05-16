class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<bool> flag;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        flag.resize(nums.size(),true);
        helper(nums,0);
        return res;
    }
    
    void helper(vector<int>& nums, int index){
        res.push_back(tmp);
        if(index==nums.size()) return ;
        for(int i=index;i<nums.size();i++){
            if(i!=0 && nums[i]==nums[i-1] && flag[i-1]) continue;
            tmp.push_back(nums[i]);
            flag[i]=false;
            helper(nums,i+1);
            flag[i]=true;
            tmp.pop_back();
        }
    }
};