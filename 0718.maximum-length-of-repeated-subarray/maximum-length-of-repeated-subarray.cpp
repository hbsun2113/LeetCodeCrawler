class Solution {
public:
    //自己没有做出来，看了discuss做出来的
     /**
    * dp[i][j] = a[i] == b[j] ? 1 + dp[i + 1][j + 1] : 0;
    * dp[i][j] : max lenth of common subarray start at a[i] & b[j];
     */
    int findLength(vector<int>& A, vector<int>& B) {
        int result=0;
        vector<vector<int>> dp(A.size()+1,vector<int>(B.size()+1));
        dp[A.size()][B.size()]=0;
        for(int i=A.size()-1;i>=0;i--){
            for(int j=B.size()-1;j>=0;j--){
                dp[i][j]=(A[i]==B[j])?dp[i+1][j+1]+1:0;
                result=max(result,dp[i][j]);
            }
        }
        return result;
    }
    
    
    
    
    
    
    
    //暴力解法会超时
    int findLength1(vector<int>& A, vector<int>& B) {
        int result=0;
        for(int i=0;i<A.size();i++){
            vector<int> tmp;
            for(int j=0;j<B.size();j++){
                if(A[i]==B[j]) tmp.emplace_back(j);
            }
            for(int k=0;k<tmp.size();k++){
                int len=0;
                int aindex=i;
                int bindex=tmp[k];
                while(aindex<A.size() && bindex<B.size() && A[aindex]==B[bindex]){
                    aindex++,bindex++,len++;
                }
                result=max(result,len);
            }
        }
        return result;
    }
};