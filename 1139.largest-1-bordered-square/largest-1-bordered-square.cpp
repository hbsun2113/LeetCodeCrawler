class Solution {
public:
    vector<vector<int>> b;
    int row,col;
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        b=grid;
        row=b.size();
        if(row==0) return 0;
        col=b[0].size();
        int res=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                for(int k=1;(i+k-1<row && j+k-1<col);k++){
                    // cout<<i<<" "<<j<<" "<<k<<" "<<check(i,j,k)<<endl;
                    if(check(i,j,k)){
                        res=max(res,k);
                    } 
                }
            }
        }
        // return res;
        return res*res;
    }
    
    
    bool check(int x,int y, int l){
        int xx=x+l-1;
        int yy=y+l-1;
        if(xx>=row || yy>=col) return false;
        for(int i=x;i<=xx;i++){
            if(b[i][y]!=1) return false;
            if(b[i][yy]!=1) return false;
        }
            
        for(int j=y;j<=yy;j++){
            if(b[x][j]!=1) return false;
            if(b[xx][j]!=1) return false;
        }
            
        return true;
    }
};