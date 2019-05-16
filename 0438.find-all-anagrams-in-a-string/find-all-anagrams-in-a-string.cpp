class Solution {
public:
    // 规范一下模板，for循环代替while更容易理解
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size()<p.size()) return res;
        unordered_map<char,int> um;
        for(const auto &c:p) um[c]++; // 需要的数量
        int count=p.size(); // 需要的数量
        for(int i=0,j=0;j<s.size();j++){
            if(um[s[j]]-->=1) count--;
            while(count==0){
                if(j-i+1==p.size()) res.push_back(i);
                if(um[s[i++]]++>=0) count++;
            }
        }
        return res;
    }
    
    
    // 模板题：https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
    vector<int> findAnagrams2(string s, string p) {
        vector<int> res;
        if(s.size()<p.size()) return res;
        unordered_map<char,int> um;
        for(const auto &c:p) um[c]++;
        int start=0,end=0,count=p.size();
        while(end<s.size()){
            if(um[s[end++]]-->0) count--;
            while(count==0){
                if(end-start==p.size()) res.push_back(start); // 注意此时end已经+1了，所以不是end-start+1
                if(um[s[start++]]++==0) count++;
            }
        }
        return res;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // 暴力解法，已经过不了了,忽略掉它
    vector<int> findAnagrams1(string s, string p) {
        vector<int> result;
        if(s.size()<p.size()) return result;
        // for(int i=0;i<=s.size()-p.size();i++){
        for(int i=0;i+p.size()-1<s.size();i++){
            string tmp=s.substr(i,p.size());
            if(issame(tmp,p)) result.push_back(i);
        }
        return result;
    }
    
    bool issame(string s, string p){
        if(s.size()!=p.size()) return false;
        vector<int> sv(26);
        vector<int> pv(26);
        for(const auto &c:s){
            sv[c-'a']+=1;
        }
        for(const auto &c:p){
            pv[c-'a']+=1;
        }
        return sv==pv;
    }
    
};