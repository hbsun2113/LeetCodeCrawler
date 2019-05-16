class Solution {
public:
    //O(m + n) space
    void setZeroes1(vector<vector<int>>& matrix) {
        int row=matrix.size();
        if(row==0) return;
        int col=matrix[0].size();
        vector<bool> flagr(row,false);
        vector<bool> flagc(col,false);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    flagr[i]=true;
                    flagc[j]=true;
                }
                    
            }
        }
        for(int i=0;i<row;i++){
            if(flagr[i]) fillrow(matrix,i,row,col);
        }
        for(int j=0;j<col;j++){
            if(flagc[j]) fillcol(matrix,j,row,col);
        }
        return;
    }
    
    void fillrow(vector<vector<int>>& matrix,int m,int row,int col){
        for(int j=0;j<col;j++)
            matrix[m][j]=0;
        return ;
    }
    
    void fillcol(vector<vector<int>>& matrix,int n,int row,int col){
        for(int i=0;i<row;i++)
            matrix[i][n]=0;
        return ;
    }
    
    //a constant space solution
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        if(row==0) return;
        int col=matrix[0].size();
        if(col==0) return;
        bool first_row_has_0=false,first_col_has_0=false;
        for(int i=0;i<col;i++){
            if(matrix[0][i]==0){
                first_row_has_0=true;
                break;
            }
        }
        for(int j=0;j<row;j++){
            if(matrix[j][0]==0){
                first_col_has_0=true;
                break;
            }
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
            }
        }
        if(first_row_has_0){
            for(int i=0;i<col;i++){
                matrix[0][i]=0;
            }
        }
        if(first_col_has_0){
            for(int i=0;i<row;i++){
                matrix[i][0]=0;
            }
        }
        return;
    }
    
    
};