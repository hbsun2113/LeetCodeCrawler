class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        for(const auto &n:nums) um[n]++;
        vector<pair<int,int>> vec;
        for(const auto u:um){
            vec.push_back({u.second,u.first});
        }
        sort(vec.rbegin(),vec.rend());
        vector<int> res;
        for(int i=0;i<k;i++)
            res.push_back(vec[i].second);
        return res;
    }
};