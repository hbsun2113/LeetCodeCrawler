class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int upA=A[0];
        int bottomA=B[0];
        
        int result1=0;
        bool flag1=true;
        for(int i=1;i<n;i++){
            if(upA!=A[i]){
                if(upA==B[i]) result1++;
                else{
                    flag1=false;
                    break;
                }
            }
        }
        
        int result2=1;
        bool flag2=true;
        for(int i=1;i<n;i++){
            if(bottomA!=A[i]){
                if(bottomA==B[i]) result2++;
                else{
                    flag2=false;
                    break;
                }
            }
        }
        
        int result3=0;
        bool flag3=true;
        for(int i=1;i<n;i++){
            if(bottomA!=B[i]){
                if(bottomA==A[i]) result3++;
                else{
                    flag3=false;
                    break;
                }
            }
        }
        
        int result4=1;
        bool flag4=true;
        for(int i=1;i<n;i++){
            if(upA!=B[i]){
                if(upA==A[i]) result4++;
                else{
                    flag4=false;
                    break;
                }
            }
        }
        
        int res=INT_MAX;
        if(flag1) res=min(res,result1);
        if(flag2) res=min(res,result2);
        if(flag3) res=min(res,result3);
        if(flag4) res=min(res,result4);
        
        if(res==INT_MAX) return -1;
        else return res;   
    }
};