class Solution {
public:
    // https://www.cnblogs.com/grandyang/p/5325761.html
    unordered_map<char,string> um;
    bool wordPatternMatch(string pattern, string str) {
        return dfs(0,0,pattern,str);
    }
    
    // 1. 如果c和t匹配上了，那就都到下一个位置
    // 2. 如果c和t在um中都没有出现过，就建立新的匹配
    // 3. 其他情况都false，因为c和t是双射
    bool dfs(int p, int r, string &pattern, string &str){
        if(p==pattern.size() && r==str.size()) return true;
        if(p==pattern.size() || r==str.size()) return false;
        char &c=pattern[p];
        for(int i=r;i<str.size();i++){
            string t=str.substr(r,i-r+1);
            if(um.count(c) && um[c]==t){
                if(dfs(p+1,i+1,pattern, str)) return true;
            }
            else if(!um.count(c)){
                bool flag=false;
                for(auto &u:um)
                    if(u.second==t){
                        flag=true;
                        break;
                    }
                        
                if(!flag){
                    um[c]=t;
                    if(dfs(p+1,i+1,pattern,str)) return true;
                    um.erase(c);
                }
            }
        }
        return false;
        
    }
};