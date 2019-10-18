class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return helper(s,t) && helper(t,s);
    }
    
    bool helper(string s, string t) {
        unordered_map<char,char> um;
        if(s.size()!=t.size()) return false;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(um.find(s[i])==um.end()) 
                um[s[i]]=t[i];
            else if(um[s[i]]!=t[i]) return false;
        }
        return true;
    }
};