class Solution {
public:
    // 还是一刷做得好
    bool wordPattern(string pattern, string str) {
        unordered_map<string,char> s2c;
        unordered_map<char,string> c2s;
        istringstream ins(str);
        string s;
        int i=0;
        while(ins>>s){
            char c=pattern[i];
            // cout<<c<<" "<<s<<endl;
            if(s2c.count(s) && c2s.count(c)){
                if(s2c[s]!=c || c2s[c]!=s) return false;
                i++;
                continue;
            }
            else if(s2c.count(s) || c2s.count(c)) return false;
            s2c[s]=c;
            c2s[c]=s;
            i++;
        }
        if(i!=pattern.size()) return false;
        return true;
    }
    
    
    bool wordPattern1(string pattern, string str) {
        istringstream in(str);
        unordered_map<char,string> um1;
        unordered_map<string,char> um2;
        int i=0;
        for(string part;in>>part;i++){ //in肯定会被遍历完
            if(um1.find(pattern[i])==um1.end() && um2.find(part)==um2.end()){
                um1[pattern[i]]=part;
                um2[part]=pattern[i];
            }
                
            else if(um1[pattern[i]]!=part || um2[part]!=pattern[i]) return false;
        }
        if(i!=pattern.size()) return false;
        return true;
    }
};