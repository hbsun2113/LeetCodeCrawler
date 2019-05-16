class Solution {
public:
    //最下面是自己做的，TLE。与AC的代码相比，是缺少了剪枝。
    //参考了http://www.cnblogs.com/grandyang/p/4944875.html
    //需要记录需要删除的左右括号数目用来剪枝。eg.当当前处理的字符是左括号的时候，并且需要删除左括号，我们才去删除并往下处理。
    //需要记录start，不必每次都从头遍历字符串。start的作用是使得我们可以直接往下处理。
    set<string> reset;
    vector<string> removeInvalidParentheses(string s) {
        int l=0,r=0; //分别记录需要删除的左右括号数目
        for(const auto &c:s){
            if(c=='(') l++;
            else if(c==')'){
                if(l>0) l--;
                else r++;
            }
        }
        helper(s,l,r,0);
        vector<string> vec(reset.begin(), reset.end());
        return vec;
    }
    
    
    void helper(string s,int l, int r, int start){
        if(l==0 && r==0 && check(s)){ 
            reset.emplace(s);
            return ;
        }
        for(int i=start;i<s.size();i++){
            if(i!=start && s[i]==s[i-1]) continue;  //如果相邻字符相同，删除哪个都一样，所以我们设置为只删除第一个。
            if(s[i]=='(' && l>0){
                helper(s.substr(0,i)+s.substr(i+1),l-1,r,i); //注意这个i:之前的i+1在下一层变成了i
            }
            if(s[i]==')' && r>0){
                helper(s.substr(0,i)+s.substr(i+1),l,r-1,i);
            }
        }
        
    }
    
    
    
    
    
    
    
    
    
    
    unordered_map<int,set<string>> res;
    int min_c=INT_MAX;
    vector<string> removeInvalidParentheses1(string s) {
        helper1(s,0);
        vector<string> vec(res[min_c].begin(), res[min_c].end());
        return vec;
    }
    //这么做过不了，没有剪枝。
    void helper1(string s,int count){
        if(count>min_c) return ;
        if(check(s)){
            min_c=min(min_c,count);
            if(res.find(count)==res.end())
                res[count]=set<string>();
            res[count].emplace(s);
            return ;
        }
        
        for(int i=0;i<s.size();i++){
            if(i!=0 && s[i]==s[i-1]) continue;
            string tmp=s;
            tmp.erase(i,1);
            helper1(tmp,count+1);
        }
    }
    
    
    bool check(string s){
        int l=0,r=0;
        for(const auto &c:s){
            if(c=='(') l++;
            else if(c==')') r++;
            if(r>l) return false;
        }
        if(l==r) return true;
        return false;
    }
};