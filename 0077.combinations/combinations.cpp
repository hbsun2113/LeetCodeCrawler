class Solution {
public:
    vector<vector<int>> res;
    vector<int> vec;
    int k,n;
    vector<vector<int>> combine(int nn, int kk) {
        k=kk;
        n=nn;
        dfs(1);
        return res;
    }
    
    void dfs(int start){
        if(vec.size()==k){
            res.push_back(vec);
            return;
        }
        
        for(int i=start;i<=n;i++){
            vec.push_back(i);
            dfs(i+1);
            vec.pop_back();
        }
        
    }
};