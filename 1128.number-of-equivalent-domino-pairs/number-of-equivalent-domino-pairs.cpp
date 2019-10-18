class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int> um;
        for(const auto &v:dominoes){
            auto m=max(v[0],v[1]);
            auto n=min(v[0],v[1]);
            auto t=10*m+n;
            um[t]++;
        }
        int res=0;
        for(const auto &u:um){
            auto c=u.second;
            res+=c*(c-1)/2;
        }
        
        return res;
    }
    
    
};