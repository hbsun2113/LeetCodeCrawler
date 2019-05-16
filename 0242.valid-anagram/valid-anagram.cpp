class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> um;
        for(const auto &c:s){
            um[c]+=1;
        }
        for(const auto &c:t){
            if(um.find(c)!=um.end()){
                um[c]-=1;
                if(um[c]==0) um.erase(c);
            }
            else return false;
        }
        if(um.size()==0) return true;
        return false;
    }
};