class Solution {
public:
    
    
    
    // 三刷，递推式还是没有想出来
    // dp[i][j]是s[i]中有多少个符合条件的t[j]
    int numDistinct(string s, string t) {
        int lens=s.size();
        int lent=t.size();
        vector<vector<long long>> dp(lens+1,vector<long long>(lent+1,0));
        for(int i=0;i<=lens;i++) dp[i][0]=1;
        for(int i=1;i<=lens;i++){
            for(int j=1;j<=lent;j++){
                dp[i][j]=dp[i-1][j];
                if(s[i-1]==t[j-1]) dp[i][j]+=dp[i-1][j-1];
            }
        }
        return dp[lens][lent];

    }
    
    
    // 二刷，还是没有做出来，其实很常规，也不难想
    // 二维矩阵vec[i][j],用来保存s[0...i]中有多少个符合条件的t[j]
    // 递推式：
    // 如果不使用s[i]，则vec[i][j]=vec[i-1][j]；
    // 如果想使用s[i],则看看s[i]是否等于t[j],如果相等，则vec[i][j]+=vec[i-1][j-1]，就是都不看最后一个字符。如果不等，则自然无法使用。
    
    int numDistinct3(string s, string t) {
        int m=s.size(),n=t.size();
        vector<vector<long long>> vec(m+1,vector<long long>(n+1,0));
        for(int i=0;i<=m;i++) vec[i][0]=1;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                vec[i][j]=vec[i-1][j];
                if(s[i-1]==t[j-1]) vec[i][j]+=vec[i-1][j-1];
            }
        return vec[m][n];
    }
    
    
    
    //没做出来，copy的https://leetcode.com/problems/distinct-subsequences/discuss/37412/Any-better-solution-that-takes-less-than-O(n2)-space-while-in-O(n2)-time
    //一个坑是count要long long类型
    int numDistinct2(string s, string t) {
        int m=s.size();
        int n=t.size();
        if(m<n) return 0;
        vector<vector<long long>> count(m+1,vector<long long>(n+1));
        for(int i=0;i<=m;i++) count[i][0]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                count[i][j]=count[i-1][j]+(s[i-1]==t[j-1]?count[i-1][j-1]:0);
                //cout<<count[i][i]<<endl;
            }
        }
        
        return count[m][n];
    }
    
    
    // 节省空间的做法
    int numDistinct1(string s, string t) {
        long long m=s.size();
        long long n=t.size();
        if(m<n) return 0;
        vector<long long> count(n+1);
        count[0]=1;
        
        for(long long i=1;i<=m;i++){
            for(long long j=n;j>=1;j--){
               if(s[i-1]==t[j-1])
                   count[j]+=count[j-1];
            }
        }
        
        return count[n];
    }
};