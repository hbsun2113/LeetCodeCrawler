class Solution {
public:
    int len;
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        len=nums.size();
        vector<int> tmp;
        vector<bool> flag(len,true);
        helper(nums,flag,tmp);
        return res;
    
    }
    
    void helper(vector<int>& nums, vector<bool> &flag, vector<int> tmp){
        if(tmp.size()==len){
            res.push_back(tmp);
            return ;
        }
        for(int i=0;i<len;i++){
            if(flag[i]){
                tmp.push_back(nums[i]);
                flag[i]=false;
                helper(nums,flag,tmp);
                flag[i]=true;
                tmp.pop_back();
            }
        }
    }
};