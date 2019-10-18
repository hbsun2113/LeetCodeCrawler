class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> um;
        for(const auto &c:text) um[c]++;
        int res=text.size();
        string target="balloon";
        for(const auto &c:target) 
            if(c=='l' || c=='o') res=min(res,um[c]/2);
            else res=min(res,um[c]);
            
        return res;
    }
};