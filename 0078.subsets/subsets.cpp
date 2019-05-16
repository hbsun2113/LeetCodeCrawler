class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(nums,0);
        return res;
    }
    
    void helper(vector<int>& nums,int index){
        res.push_back(tmp);
        if(tmp.size()==nums.size()) return;
        for(int i=index;i<nums.size();i++){
            tmp.push_back(nums[i]);
            helper(nums,i+1);
            tmp.pop_back();
        }
    }
};