class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> um;
        for(const auto &c:s) um[c]++;
        int index=0;
        for(const auto &c:s){
            if(um[c]==1) return index;
            index++;
        }
        return -1;
    }
};