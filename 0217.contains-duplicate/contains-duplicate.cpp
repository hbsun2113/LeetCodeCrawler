class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> um;
        for(const auto &num:nums){
            if(um.find(num)!=um.end()) return true;
            else um[num]++;
        }
        return false;
    }
};