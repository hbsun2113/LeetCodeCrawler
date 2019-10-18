class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> um;
        for(auto &n:arr) um[n]++;
        vector<bool> vis(1010,false);
        for(auto &n:um){
            if(vis[n.second]) return false;
            vis[n.second]=true;
        }
        return true;
    }
};