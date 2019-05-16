class Solution {
public:
    int row;
    int col;
    int numEnclaves(vector<vector<int>>& A) {
        row=A.size();
        col=A[0].size();
        for(int i=0;i<row;i++){
            dfs(A,i,0);
            dfs(A,i,col-1);
        }
        for(int i=0;i<col;i++){
            dfs(A,0,i);
            dfs(A,row-1,i);
        }
        int res=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(A[i][j]==1) res++;
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& A, int x, int y){
        if(A[x][y]!=1) return ;
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};
        A[x][y]=2;
        for(int k=0;k<4;k++){
            int xx=x+dx[k];
            int yy=y+dy[k];
            if(xx>=0 && xx<row && yy>=0 && yy<col && A[xx][yy]==1) dfs(A,xx,yy);
        }
        return ;
    }
};