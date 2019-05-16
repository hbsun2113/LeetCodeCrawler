class Solution {
public:
    //拼接成一维数组vector。
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        if(row==0) return false;
        int col=matrix[0].size();
        int l=-1, r=row*col;
        cout<<row<<" "<<col<<endl;
        while(l+1!=r){
            int mid=l+(r-l)/2;
            // cout<<l<<" "<<r<<" "<<mid<<" "<<mid/row<<" "<<mid%row<<endl;
            if(matrix[mid/col][mid%col]<target) l=mid; //注意哦，是除以列
            else r=mid;
        }
        cout<<"search"<<endl;
        if(r==row*col || matrix[r/col][r%col]!=target) return false;
        return true;
    }
    
    
    
    
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        if(row==0) return false;
        int col=matrix[0].size();
        int i=0,j=col-1;
        while(i<row && j>=0){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target) i++;
            else j--;
        }
        return false;
    }
};