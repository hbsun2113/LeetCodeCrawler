class Solution {
public:
    unordered_map<char,int> um;
    // 别人的思路
    string smallestSubsequence(string text) {
        if(text.empty()) return text;
        vector<bool> vis(26,false);
        for(const auto &c:text) um[c]++;
        string res="";
        for(int i=0;i<text.size();i++){
            um[text[i]]--;
            if(vis[text[i]-'a']) continue;
            while(!res.empty() && um[res.back()]>=1 && text[i]<=res.back()){
                vis[res.back()-'a']=false;
                res.pop_back();
            } 
        
            vis[text[i]-'a']=true;
            res.push_back(text[i]);
            
        }
        return res;
    }
    
    // 自己的思路
    string smallestSubsequence2(string text) {
        if(text.empty()) return text;
        vector<bool> vis(26,false);
        for(const auto &c:text) um[c]++;
        string res="";
        stack<char> s;
        for(int i=0;i<text.size();i++){
            
            if(vis[text[i]-'a']){
                um[text[i]]--;
                continue;
            } 
            while(!s.empty() && um[s.top()]>1 && text[i]<=s.top()){
                um[s.top()]--;
                vis[s.top()-'a']=false;
                s.pop();
            } 
            if(!vis[text[i]-'a']){
                vis[text[i]-'a']=true;
                s.push(text[i]);
            }
        }
        while(!s.empty()){
            res=s.top()+res;
            s.pop();
        }
        return res;
    }
};