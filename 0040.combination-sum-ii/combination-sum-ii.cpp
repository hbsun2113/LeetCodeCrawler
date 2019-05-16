class Solution {
public:
    //忘记几刷了，自己AC的。
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int sum=0;
        helper(candidates,target,0,0);
        return res;
    }
    
    void helper(vector<int>& candidates, int target, int sum, int index){
        if(sum>target || index>candidates.size()) return;
        if(sum==target){
            res.push_back(tmp);
            return ;
        }
        for(int i=index;i<candidates.size();i++){
            if(i!=index && candidates[i]==candidates[i-1]) continue;  //这条规则可以记一下。头部节点不使用重复值，也就是当前层不使用重复值。
            tmp.push_back(candidates[i]);
            sum+=candidates[i];
            helper(candidates,target,sum, i+1);
            sum-=candidates[i];
            tmp.pop_back();
        }
    }
};