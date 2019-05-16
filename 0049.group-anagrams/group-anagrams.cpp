class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        for(const auto &str:strs){
            string tmp(str);
            sort(tmp.begin(),tmp.end());
            um[tmp].push_back(str);
        }
        vector<vector<string>> res;
        for(const auto u:um)
            res.push_back(u.second);
        return res;
    }
};