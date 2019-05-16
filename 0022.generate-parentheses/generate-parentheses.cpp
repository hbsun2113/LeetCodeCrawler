class Solution {
public:
    
    // 三刷，终于记住了
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        int l=0,r=0;
        if(n==0) return res;
        string tmp="";
        dfs(n,tmp,l,r);
        return res;
    }

    void dfs(int n,const string &tmp, int l, int r){
        if(l==n && r==n){
            res.push_back(tmp);
            return ;
        }
        if(l<n) dfs(n,tmp+"(",l+1,r);
        if(r<l) dfs(n,tmp+")",l,r+1);
            
    }
    
    /*
    //二刷，还是看了答案，有些细节没有记清楚。
    //https://www.acwing.com/solution/LeetCode/content/70/ 和 之前的AC代码都可以看看，思路是一样的：
    // 1. 要想到使用递归解决  2.可以添加左括号的条件是数目小于n  3.可以添加右括号的条件是右括号的数目小于左括号的数目。
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string curr="";
        helper(curr,0,0,n);
        return res;
    }
    
    void helper(string curr, int left, int right,int n){
        if(left==n && right==n){
            res.push_back(curr);
            return ;
        }
        if(left<n) helper(curr+"(",left+1,right,n);
        if(right<left) helper(curr+")",left,right+1,n);
    }*/
};