class Solution {
public:
    //一把过。
    vector<int> nums;
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> combinationSum3(int k, int n) {
        for(int i=1;i<=9;i++) nums.push_back(i);
        helper(k,n,0,0,0);
        return res;
        
    }
    
    void helper(int k, int n, int index, int sum, int count){
        if(index>nums.size() || count>k || sum>n) return ;
        if(count==k && sum==n){
            res.push_back(tmp);
            return ;
        }
        for(int i=index;i<nums.size();i++){
            tmp.push_back(nums[i]);
            helper(k,n,i+1,sum+nums[i],count+1);
            tmp.pop_back();
        }
    }
};