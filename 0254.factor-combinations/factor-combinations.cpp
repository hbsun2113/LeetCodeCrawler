#define dbv(v) cout << #v << "="; for (auto _x : v) cout << _x << ", "; cout << endl
class Solution {
public:
    // https://leetcode.com/problems/factor-combinations/discuss/68040/My-Recursive-DFS-Java-Solution
    // ????
    vector<vector<int>> res;
    vector<vector<int>> getFactors(int n) {
        vector<int> tmp;
        dfs(n,2,tmp);
        return res;
    }
    
    void dfs(int n, int i, vector<int> &tmp){
        if(n<=1){
            if(tmp.size()>1) res.push_back(tmp);
            return;
        }
        for(int j=i;j<=n;j++){
            if(n%j==0){
                tmp.push_back(j);
                dfs(n/j,j,tmp);
                tmp.pop_back();
            }
        }
    }
    
    
    // ????
    vector<vector<int>> getFactors1(int n) {
        vector<vector<int>> res;
        if(n<=3) return res;
        vector<vector<vector<int>>> vec(n+1);
        vec[0]={};
        vec[1]={};
        vec[2]={};
        vec[3]={};
        for(int i=4;i<=n;i++){
            for(int j=2;j<i;j++){
                if(i%j==0){
                    auto v=vec[i/j];
                    // cout<<i<<" "<<j<<" "<<i/j<<endl;
                    if(j<=i/j) vec[i].push_back({j,i/j});
                    for(auto t:v){
                        if(j<t.back()) continue;
                        t.push_back(j);
                        vec[i].push_back(t);
                    }
                }
            }
        }
        return vec.back();
    }
};