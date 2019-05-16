class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int,int> um;
        for(const auto &a:A){
            if(um.find(a)!=um.end()) return a;
            else um[a]++;
        }
        return -1;
    }
};