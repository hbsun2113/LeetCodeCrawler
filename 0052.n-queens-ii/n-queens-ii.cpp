class Solution {
public:
    vector<bool> shun,ni,lie;
    int res;
    int totalNQueens(int n) {
        res=0;
        shun.resize(2*n,true);
        ni.resize(2*n,true);
        lie.resize(n,true);
        dfs(0,n);
        return res;
        
    }
    
    void dfs(int row, int n){
        if(row==n){
            res++;
            return;
        };
        for(int col=0;col<n;col++){
            int id1=row+col;
            int id2=row-col+n;
            if(!(shun[id1] && ni[id2] && lie[col])) continue;
            shun[id1]=ni[id2]=lie[col]=false;
            dfs(row+1,n);
            shun[id1]=ni[id2]=lie[col]=true;
        }
    }
    
    
    
    
    
    
    
    /*
    //二刷了，还是要看题解。
    vector<bool> shun;
    vector<bool> ni;
    vector<bool> lie;
    int res;
    int totalNQueens(int n) {
        shun.resize(n+n,true);
        ni.resize(n+n,true);
        lie.resize(n,true);
        helper(0,n);
        return res;
    }
    
    void helper(int row, int n){
        if(row==n){
            res++;
            return ;
        }
        for(int col=0;col<n;col++){
            int id1=row+col;
            int id2=row-col+n;
            if(!(shun[id1] && ni[id2] && lie[col])) continue;
            shun[id1]=ni[id2]=lie[col]=false;
            helper(row+1,n);
            shun[id1]=ni[id2]=lie[col]=true;
        }
    }
    
    */
    
    
    
    
    
/*
(0,0) (0,1) (0,2) (0,3)
(1,0) (1,1) (1,2) (1,3)
(2,0) (2,1) (2,2) (2,3)
(3,0) (3,1) (3,2) (3,3) 

这么 ／ 是x+y 的值相等
这么 \  是x-y 的值相等
*/    
    //比这道题目简单些https://leetcode.com/problems/n-queens/description/    
    //copy了这个：https://leetcode.com/problems/n-queens-ii/discuss/20048/Easiest-Java-Solution-(1ms-98.22)
    int count;
    int totalNQueens1(int n) {
        count=0;
        vector<bool> cols(n);
        vector<bool> shun(n+n);
        vector<bool> ni(n+n);
        helper1(0,n,cols,shun,ni);
        return count;
    }
    
    
    void helper1(int row, int n, vector<bool> &cols, vector<bool> &shun, vector<bool> &ni){
        if(row==n){
            count++;
        }
        for(int col=0;col<n;col++){ //在该行，看看这个queue可以放在哪列
            int id1=row+col;
            int id2=row-col+n;
            if(cols[col] || shun[id1] || ni[id2]) continue;
            cols[col]=shun[id1]=ni[id2]=true;
            helper1(row+1,n,cols,shun,ni);
            cols[col]=shun[id1]=ni[id2]=false;
        }
    }
    
    
       
    
    
};