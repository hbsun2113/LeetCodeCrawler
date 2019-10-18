class NumMatrix {
public:
    // https://leetcode.com/problems/range-sum-query-2d-mutable/discuss/75870/Java-2D-Binary-Indexed-Tree-Solution-clean-and-short-17ms
    // https://leetcode.com/problems/range-sum-query-mutable/description/
    NumMatrix(vector<vector<int>>& matrix) {
        row=matrix.size();
        if(row==0) return ;
        col=matrix[0].size();
        m.resize(row,vector<int>(col,0));
        presum.resize(row+1,vector<int>(col+1,0));
        for(int i=1;i<=row;i++)
            for(int j=1;j<=col;j++)
                update(i-1,j-1,matrix[i-1][j-1]);
    }
    
    void update(int x, int y, int val) {
        int delta=val-m[x][y];
        m[x][y]=val;
        x++,y++;
        for(int i=x;i<=row;i+=getlowbit(i)){
            for(int j=y;j<=col;j+=getlowbit(j)){
                presum[i][j]+=delta;
            }
        }
            
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return query(row2,col2)+query(row1-1,col1-1)-query(row2,col1-1)-query(row1-1,col2);
    }
    
    int query(int x, int y){
        x++,y++;
        int sum=0;
        for(int i=x;i>0;i-=getlowbit(i)){
            for(int j=y;j>0;j-=getlowbit(j)){
                sum+=presum[i][j];
            }
        }
        return sum;
    }
    
    int getlowbit(int n){
        return n&~(n-1);
    }
    
    int row,col;
    vector<vector<int>> m,presum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */