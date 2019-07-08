class Solution {
public:
    // https://www.cnblogs.com/grandyang/p/7617017.html 中的法2
    bool checkValidString(string s) {
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='*') c++;
            else c--;
            if(c<0) return false;
        }
        if(c==0) return true;
        
        c=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')' || s[i]=='*') c++;
            else c--;
            if(c<0) return false;
        }
        return true;
    }
    
    
    // 自己写的，暴力dfs
    bool checkValidString1(string s) {
        return dfs(s,0,0,0);
    }
    
    bool dfs(string &s, int l, int r, int i){
        if(i==s.size() ){
            if(l==r) return true;
            else return false;
        }
        if(l<r) return false;
        if(s[i]=='(') return dfs(s,l+1,r,i+1);
        if(s[i]==')') return dfs(s,l,r+1,i+1);
        else return dfs(s,l+1,r,i+1) || dfs(s,l,r+1,i+1) || dfs(s,l,r,i+1);
    }
};