class Solution {
public:
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row=matrix.size();
        if(row==0) return 0;
        int col=matrix[0].size();
        vector<vector<int>> vec(row,vector<int>(col,-1));
        int res=1;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                res=max(res,dfs(matrix,vec,i,j,row,col));
            }
        }
        return res;
    }
    
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& vec, int i, int j, int row, int col){
        if(vec[i][j]!=-1) return vec[i][j];
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};
        vec[i][j]=1;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && x<row && y>=0 && y<col && matrix[x][y]<matrix[i][j]) 
                vec[i][j]=max(vec[i][j],dfs(matrix,vec,x,y,row,col)+1);
        }
        return vec[i][j];
    }
    
    
    
    
    
    
    
    // 二刷了，感觉思路还不如一刷。
    // 这题注意啊，好像不是常规的dfs，应该叫做“记忆化搜索”？https://www.acwing.com/solution/LeetCode/content/356/
    // 和正常的dfs不一样，好像主函数里必须有for循环？
    /*int row,col;
    vector<vector<int>> vec;
    vector<int> dx;
    vector<int> dy;
    vector<vector<int>> m;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return 0;
        int res=0;
        row=matrix.size();
        col=matrix[0].size();
        vec=vector<vector<int>>(row,vector<int>(col,-1));
        m=matrix;
        dx={0,0,1,-1};
        dy={1,-1,0,0};
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                res=max(res,dfs(i,j));
        return res;
    }
    
    int dfs(int x,int y){
        if(vec[x][y]!=-1) return vec[x][y];
        int tmp=0;
        for(int i=0;i<4;i++){
            int a=x+dx[i];
            int b=y+dy[i];
            if(a>=0 && a<row && b>=0 && b<col && (m[a][b]<m[x][y]))
                tmp=max(tmp,dfs(a,b));
        }
        vec[x][y]=tmp+1;
        return vec[x][y];
    }*/
};