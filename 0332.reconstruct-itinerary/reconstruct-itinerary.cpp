class Solution {
public:
    // ??????????
    
    // ?????????https://leetcode.com/problems/reconstruct-itinerary/discuss/78768/Short-Ruby-Python-Java-C++/83576
    // https://leetcode-cn.com/problems/reconstruct-itinerary/solution/javadfsjie-fa-by-pwrliang/
    // ?????????????????????????????
    vector<string> res;
    unordered_map<string,vector<string>> um;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(const auto &t:tickets)
            um[t[0]].push_back(t[1]);
        
        auto cmp=[](string &a, string &b){
            return a>b;
        };
        for(auto &n:um)
            sort(n.second.begin(),n.second.end(),cmp);
        
        string cur="JFK";
        res.push_back(cur);
        dfs(tickets.size()+1,cur);
        
        return res;
    }
    
    bool dfs(int target, string cur){
        // cout<<cur<<" "<<res.size()<<" "<<target<<endl;
        if(res.size()==target) return true;
        if(um[cur].empty()) return false;
        auto tmp=um[cur];
        for(int i=um[cur].size()-1;i>=0;i--){
            string next=um[cur][i];
            um[cur].erase(um[cur].begin()+i);
            res.push_back(next);
            if(dfs(target,next)) return true;
            res.pop_back();
            um[cur].insert(um[cur].begin()+i,next);
        }
        return false;
    }
};