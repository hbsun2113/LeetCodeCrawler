class Solution {
public:
    
    // 三刷，又是自己做的
    // top-down
    /*unordered_set<string> us;
    unordered_map<string,vector<string>> um;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(const auto &w:wordDict)
            us.emplace(w);
        return dfs(s);;
    }
    
    vector<string> dfs(string s){
        if(um.find(s)!=um.end()) return um[s];
        if(s.empty()){
            return vector<string>();
        }
        vector<string> tmp;
        for(int i=1;i<=s.size();i++){
            string first=s.substr(0,i);
            if(us.find(first)==us.end()) continue;
            
            string second=s.substr(i);
            if(second.size()==0){
                tmp.push_back(first);
                continue;
            }
            
            const auto &svec=dfs(second);
            if(svec.size()==0) continue;
            for(const auto &sv:svec){
                tmp.push_back(first+" "+sv);
            }
        }
        
        um[s]=tmp;
        return um[s];
    }*/
    
    
    
    //二刷，自己花了很长时间做了出来。感觉比一更的别人解法要方便一些。还得是自己做啊。
    unordered_set<string> us;
    unordered_map<string,vector<string>> um;
    
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        copy(wordDict.begin(),wordDict.end(),std::inserter(us,us.end()));
        cout<<wordDict.size()<<endl;
        return helper(s);
    }
    
    
    
    vector<string> helper(string s){
        if(um.find(s)!=um.end()) return um[s];
        vector<string> tmp;
        if(us.find(s)!=us.end()) tmp.push_back(s); //这里别忘了！！！
        for(int i=0;i<=s.size();i++){
            string first=s.substr(0,i);
            if(us.find(first)!=us.end()){
                string second=s.substr(i);
                vector<string> second_v=helper(second);
                for(const auto &v:second_v){
                    string cmb=first+" "+v;
                    tmp.push_back(cmb);
                }
            }
        }
        um[s]=tmp;
        return um[s];
    }
    
    
};