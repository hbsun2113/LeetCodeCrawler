class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,0,0);
        return res;
    }
    
    void helper(vector<int>& candidates, int target, int sum, int index){
        if(sum>target) return;
        if(sum==target){
            res.push_back(tmp);
            return ;
        }
        for(int i=index;i<candidates.size();i++){
            tmp.push_back(candidates[i]);
            helper(candidates,target,sum+candidates[i], i);  // code review: 我估计是因为可以重复，所以是i，而不是i+1。
            tmp.pop_back();
        }
    }
};