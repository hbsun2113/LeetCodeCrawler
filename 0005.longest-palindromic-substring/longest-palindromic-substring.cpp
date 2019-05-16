class Solution {
public:
    // 三刷，自己做出来了
    string longestPalindrome(string s) {
        if(s.size()==0) return "";
        int res=1;
        int start=0;
        int len=s.size();
        vector<vector<bool>> dp(len,vector<bool>(len,false));
        for(int k=1;k<=len;k++){ // 需要注意最外层循环是长度
            for(int i=0;i+k-1<len;i++){
                int j=i+k-1;
                if(j-i<1) dp[i][j]=true;
                else if(j-i==1 && s[i]==s[j]) dp[i][j]=true;
                else if(j-i>1 && dp[i+1][j-1] && s[i]==s[j]) dp[i][j]=true;
                if(dp[i][j] && j-i+1>res){
                    res=j-i+1;
                    start=i;
                }
            }
        }
        return s.substr(start,res);
    }
    
    
    // 二刷，建议记这种，实现起来比较简单。但是运行慢
    int res=1;
    string tmp;
    vector<vector<bool>> dp;
    string longestPalindrome2(string s) {
        if(s.size()==0) return s;
        tmp=s[0];
        int len=s.size();
        dp.resize(len+1,vector<bool>(len+1,0));
        dp[0][0]=1;
        
        for(int i=1;i<=len;i++){
            for(int j=i;j>=1;j--){
                if(i-j<=1)
                    dp[j][i]=(s[i-1]==s[j-1]);
                else{
                    dp[j][i]=(dp[j+1][i-1] && s[i-1]==s[j-1]);
                }
                if(dp[j][i]){
                    if(i-j+1>res){
                        res=(i-j+1);
                        tmp=s.substr(j-1,res); // 注意j的下标
                    }
                }
            }
        }
        return tmp;
    }
    
    
    
    //https://www.acwing.com/solution/LeetCode/content/51/
    string longestPalindrome1(string s) {
        if(s.size()==0) return s;
        int len=0;
        string res;
        for(int i=0;i<s.size();i++){
            for(int j=0;i-j>=0 && i+j<s.size();j++){ //回文串长度为奇数
                if(s[i-j]==s[i+j]){
                    if(1+2*j>len){
                        len=1+2*j;
                        res=s.substr(i-j,1+2*j);
                    }
                }
                else break;
            }
            
            for(int j=i,k=i+1;j>=0 && k<s.size();j--,k++){ //回文串长度为偶数
                if(s[j]==s[k]){
                    if(k-j+1>len){
                        len=k-j+1;
                        res=s.substr(j,k-j+1);
                    }
                }
                else break;
            }
        }
        cout<<len<<endl;
        return res;
    }
};