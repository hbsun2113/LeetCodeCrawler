class Solution {
public:
    // 三刷，没做出来
    int minCut(string s) {
        int len=s.size();
        vector<vector<bool>> dp(len,vector<bool>(len,false));
        for(int i=0;i<len;i++){
            for(int j=i;j>=0;j--){
                if(i-j<=1){
                    if(s[i]==s[j]) dp[j][i]=true;
                    continue;
                }
                else if(s[i]==s[j] && dp[j+1][i-1])
                    dp[j][i]=true;
            }
        }
        vector<int> f(len+1,0);
        for(int i=1;i<=len;i++){
            f[i]=INT_MAX;
            for(int j=0;j<i;j++){
                if(dp[j][i-1])
                    f[i]=min(f[i],f[j]+1);
            }
        }
        return f[len]-1;
    }
    
    
    // https://www.acwing.com/solution/LeetCode/content/227/
    int minCut2(string s) {
        int len=s.size();
        vector<vector<int>> dp(len,vector<int>(len));
        for(int i=0;i<len;i++)
            for(int j=i;j>=0;j--){
                if(i-j<=1) dp[j][i]=(s[i]==s[j]);
                else dp[j][i]=(dp[j+1][i-1] && s[i]==s[j]);
            }
        // cout<<1<<endl;
        // for(int i=0;i<len;i++)
        //     for(int j=0;j<len;j++)
        //         cout<<dp[j][i]<<" \n"[j==len-1];  //http://codeforces.com/blog/entry/15643
        
        vector<int> f(len+1,INT_MAX); //这个是为了处理整个字符串恰好是回文串的情况
        f[0]=0;
        for(int i=1;i<=len;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j][i-1])
                    f[i]=min(f[i],f[j]+1);
            }
        }
        
        
        return max(0,f.back()-1);
    }
    
    
    int minCut1(string s) {
        int len=s.size();
        vector<int> result(len+1); //多存一个位置，我猜是为了保证：如果当前位置到末尾是一个回文串，则不必切割。
        for(int i=0;i<len;i++) result[i]=len-i;
        vector<vector<bool>> mat(len,vector<bool>(len));
        for(int i=len-1;i>=0;i--){
            for(int j=i;j<len;j++){
                if((i==j) || (s[i]==s[j] && j-i<2) || (s[i]==s[j] && mat[i+1][j-1])){
                    mat[i][j]=true;
                    result[i]=min(result[i],result[j+1]+1);
                }
            }
        }
        return result[0]-1;
        
        
    }
    
  

    
};