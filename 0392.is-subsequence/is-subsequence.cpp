class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char,vector<int>> um; 
        for(int i=0;i<t.size();i++){
            um[t[i]].push_back(i);
        }
        int pre=-1;
        for(int i=0;i<s.size();i++){
            char &c=s[i];
            auto it=upper_bound(um[c].begin(),um[c].end(),pre);
            if(it==um[c].end()) return false;
            pre=*it;
        }
        return true;
    }
    
    bool isSubsequence2(string s, string t) {
        unordered_map<char,vector<int>> um;
        for(int i=0;i<t.size();i++){
            char &c=t[i];
            um[c].emplace_back(i);
        }
        int pre=-1;
        for(int i=0;i<s.size();i++){
            char &c=s[i];
            vector<int> tmp=um[c];
            auto it=upper_bound(tmp.begin(),tmp.end(),pre);
            if(it==tmp.end()) return false;
            pre=*it;
        }
        return true;

    }

    bool isSubsequence1(string s, string t) {
        int i=0;
        for(int j=0;j<t.size();j++){
            if(t[j]==s[i]) i++;
        }
        return i==s.size();
    }
};

