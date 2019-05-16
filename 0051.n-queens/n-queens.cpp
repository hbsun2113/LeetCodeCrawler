class Solution {
public:
    //和https://leetcode.com/problems/n-queens-ii/description/统一了一下解法，感觉这个更好记忆
    vector<vector<string>> res;
    vector<bool> shun,ni,lie;
    vector<string> m;
    vector<vector<string>> solveNQueens(int n) {
        string tmp=string(n,'.');
        m.resize(n,tmp);
        shun.resize(2*n,true);
        ni.resize(2*n,true);
        lie.resize(n,true);
        dfs(0,n);
        return res;
    }
    
    void dfs(int row, int n){
        if(row==n){
            res.push_back(m);
            return;
        }
        for(int c=0;c<n;c++){
            int id1=row+c;
            int id2=row-c+n;
            if(!(shun[id1] && ni[id2] && lie[c])) continue;
            m[row][c]='Q';
            shun[id1]=ni[id2]=lie[c]=false;
            dfs(row+1,n);
            shun[id1]=ni[id2]=lie[c]=true;
            m[row][c]='.';
        }
    }
    /*
    //二刷，竟然还是要看答案呐
    vector<vector<string>> res;
    vector<string> m;
    vector<vector<string>> solveNQueens(int n) {
        string tmp=string(n,'.');
        m.resize(n,tmp);
        helper(n,0);
        return res;
    }
    
    void helper(int n,int row){
        if(row==n){
            res.push_back(m);
            return ;
        }
        for(int j=0;j<n;j++){
            m[row][j]='Q';
            if(check(row,j,n)){
                helper(n,row+1);
            }
            m[row][j]='.';
        }
    }
    
    bool check(int row, int col,int n){
        for(int i=0;i<row;i++)
            if(m[i][col]=='Q') return false;
        
        for(int i=row-1,j=col-1;(i>=0 && j>=0);i--,j--)
            if(m[i][j]=='Q') return false;
        
        for(int i=row-1,j=col+1;(i>=0 && j<n);i--,j++)
            if(m[i][j]=='Q') return false;
        
        return true;
    }*/
};