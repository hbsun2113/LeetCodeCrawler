class Solution {
public:
    //太难了，字符串的题不乐意做！！！！！！！！！！！ https://www.acwing.com/solution/LeetCode/content/557/
    bool isMatch(string s, string p) {
        int slen=s.size(),plen=p.size();
        vector<vector<bool>> dp(slen+1,vector<bool>(plen+1,false));
        dp[0][0]=true;
        s=" "+s;
        p=" "+p;
        for(int i=0;i<=slen;i++){
            for(int j=0;j<=plen;j++){
                if(i>0 && (s[i]==p[j] || p[j]=='.')) // 直接匹配
                    dp[i][j] =  dp[i][j] | dp[i-1][j-1];
                if(p[j]=='*'){
                    dp[i][j] = dp[i][j] | dp[i][j-2]; // 丢弃j-1和j,即'*' Matches zero
                    if(i>0){
                        if(s[i]==p[j-1] | p[j-1]=='.') // 它俩一个效果
                            dp[i][j] = dp[i][j] | dp[i-1][j]; // 1. dp[i-1][j-2]利用一次*   2. dp[i-1][j]利用多次*。
                                                              // 我自己认为dp[i-1][j]包含了dp[i-1][j-2]
                    }    
                }
            }
        }
        return dp[slen][plen];
    }
    
    // 稍微解释一下dp[i-1][j]：
    // s是SSS, p是S*
    // 如果s[2]=p[0],则S[2]肯定可以被匹配--不足为虑了，我们直接去看之前可不可以匹配就行了--即dp[i-1][j]。
};