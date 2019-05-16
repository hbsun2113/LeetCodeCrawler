class Solution {
public:
    //根据Spiral Matrix 直接改过来的，基本什么都没有变化。
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n,n));
        int m=n;
        if(n==0){
            return result;
        }
        vector<vector<bool>> flag(m,vector<bool>(n,false));
        int i=0,j=0;
        int flag1=0,flag2=1;//横 纵
        int count=1;
        
        while(count<=m*n){
            if(flag1==0 && flag2==1 && count<=m*n){
                while(j<n && !flag[i][j] ){
                    result[i][j]=count;
                    cout<<count<<endl;
                    flag[i][j]=true;
                    j++;
                    count++;
                }
                flag1=1;
                flag2=1;
                j-=1;
                i+=1;
            }
            if(flag1==1 && flag2==1 && count<=m*n){
                while((i<m) && !flag[i][j]){
                    result[i][j]=count;
                    cout<<count<<endl;
                    flag[i][j]=true;
                    i++;
                    count++;
                   
                }
                flag1=1;
                flag2=0;
                i-=1;
                j-=1;
            }
            if(flag1==1 && flag2==0 && count<=m*n){
                while(j>=0 && !flag[i][j]){
                    result[i][j]=count;
                    cout<<count<<endl;
                    flag[i][j]=true;
                    j--;
                    count++;
                }
                flag1=0;
                flag2=0;
                j+=1;
                i-=1;
            }
            if(flag1==0 && flag2==0 && count<=m*n){
                while(i>=0 && !flag[i][j]){
                    result[i][j]=count;
                    cout<<count<<endl;
                    flag[i][j]=true;
                    i--;
                    count++;
                }
                flag1=0;
                flag2=1;
                i+=1;
                j+=1;
            }
        }
        return result;
    }
};