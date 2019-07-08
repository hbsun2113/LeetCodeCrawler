class Solution {
public:
    //总共两种解法：DFS、Unionfind 
    
    // https://leetcode.com/problems/friend-circles/discuss/101338/Neat-DFS-java-solution
    int m;
    int findCircleNum0(vector<vector<int>>& M) {
        m=M.size();
        vector<bool> vis(m,false); // 标志是否已经被访问过了
        int count=0;
        for(int i=0;i<m;i++){
            if(!vis[i]){
                vis[i]=true;
                dfs(M,vis,i);
                count++;
            } 
        }
        return count;
    }
    
    void dfs(vector<vector<int>>& M, vector<bool> &vis, int i){ // 对于i,找到它所有的朋友
        for(int j=0;j<m;j++){
            if(M[i][j] && !vis[j]){
                vis[j]=true;
                dfs(M,vis,j);
            }
        }
    }
    
    // UnionFind: https://leetcode.com/problems/friend-circles/discuss/101354/C++-Clean-Code-DFSorUnionFind
    vector<int> parents;
    int findCircleNum3(vector<vector<int>>& M) {
        int m=M.size();
        parents.resize(m,0);
        for(int i=0;i<m;i++) parents[i]=i;
        int res=m;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++){
                if(M[i][j]==1){
                    auto a=findparents(i);
                    auto b=findparents(j);
                    if(a!=b){
                        parents[a]=b;
                        res--;
                    }
                }
            }
        }
        
        return res;
        
    }
    int findparents(int i){
        while(i != parents[i])
        {
            parents[i] = parents[parents[i]];
            i = parents[i];
        }
        return i;
    }
    
    
    // 栈实现更快
    int findCircleNum(vector<vector<int>>& M) {
        bool check[M.size()] {};
        queue<int> q;
        int sol = 0;
        for(int i = 0; i < M.size(); i++){
            if(!check[i]) sol++, q.push(i), check[i] = 1;
            while(!q.empty()){
                int res = q.front();
                q.pop();
                for(int n = 0; n < M.size(); n++)
                    if(M[res][n] && !check[n]) q.push(n), check[n] = 1;
            }
        }
        return sol;
    }
    
    
    
    
    // 自己做的
    int row,col,res;
    int findCircleNum1(vector<vector<int>>& M) { // M先天就是对称的
        res=0;
        row=M.size();
        if(row==0) return 0;
        col=M[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<=i;j++){
                if(M[i][j]==1){
                    res++;
                    dfs1(M,i,j);
                } 
            }
        }
        return res;
    }
    
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    void dfs1(vector<vector<int>>& M, int xx, int yy){
        if(xx<0 || xx>=row || yy<0 || yy>=col || M[xx][yy]==0) return;
        M[xx][yy]=0;
        dfs1(M,xx,yy);
        for(int m=0;m<row;m++) if(M[m][yy]) dfs1(M,m,yy);
        for(int n=0;n<col;n++) if(M[xx][n]) dfs1(M,xx,n);
        for(int k=0;k<4;k++){
            int x=xx+dx[k];
            int y=yy+dy[k];
            dfs1(M,x,y);
        }
    }
};