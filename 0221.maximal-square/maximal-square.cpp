class Solution {
public:
    //二刷，还是看了discuss
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        if(row==0) return 0;
        int col=matrix[0].size();
        vector<vector<int>> len(row,vector<int>(col,0));
        int area=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 || j==0) len[i][j]=matrix[i][j]-'0';
                else{
                    if(matrix[i][j]=='0') len[i][j]=0;
                    else{
                        len[i][j]=min(len[i-1][j],min(len[i][j-1],len[i-1][j-1]))+1; // 取上、下、对角最小，然后加一。
                    }
                }
                area=max(area,len[i][j]*len[i][j]);
            }
        }
        return area;
    }
};