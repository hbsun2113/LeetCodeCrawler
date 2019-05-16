class Solution {
public:
    // 模板题:https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems?orderBy=most_votes
    string minWindow(string s, string t) {
        string res="";
        if(s.size()<t.size()) return res;
        unordered_map<char,int> um;
        for(const auto &c:t) um[c]++;
        int i=0;
        int count=t.size();
        int d=INT_MAX;
        int start;
        for(int j=0;j<s.size();j++){
            if(um[s[j]]-->0) count--;
            while(count==0){
                if(d>j-i+1){
                    d=j-i+1;
                    start=i;
                }
                if(um[s[i++]]++==0) count++;
            }
        }
        if(d!=INT_MAX) res=s.substr(start,d);
        return res;
    }
    
    
    
    
    
    // https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
    string minWindow1(string s, string t) {
        unordered_map<char,int> um;
        for(const auto &c:t) um[c]++; // 还需要的数量
        int i=0,j=0,d=INT_MAX,res,count=t.size();
        while(j<s.size()){
            if(um[s[j]]>0) count--;
            um[s[j]]--;
            j++;
            
            while(count==0){
                if(d>j-i){
                    d=j-i;
                    res=i;
                }
                um[s[i]]++;
                if(um[s[i]]>0) count++;
                i++;
            }
        }
        cout<<res<<" "<<d<<endl;
        if(d==INT_MAX) return "";
        return s.substr(res,d);
    }
};