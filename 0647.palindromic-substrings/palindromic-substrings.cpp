class Solution {
public:
    // 二刷，自己做出来的，没有使用DP:构造了如下例子 cbabccbad.
    // 可以看出有两个最长回文串cbabc和abccba。其实只要知道了每个最长回文串的情况，就知道了它包含了多少个回文子串，所以我们只要找到每个最长回文串就好了。
    // 以每个元素为中心，搜索回文串。
    int res=0;
    
    int countSubstrings1(string s) { 
        for(int i=0;i<s.size();i++)
            ispalindromic(s,i);
        return res;
    }
    
    void ispalindromic(string &s, int i){  // 以i为中心
        for(int k=1;i-k+1>=0 && i+k-1<s.size() && s[i-k+1]==s[i+k-1];k++){ // 长度奇数：cbabc
            res++;
        }
        
        for(int m=i,n=i+1;m>=0 && n<s.size() && s[m]==s[n]; m--,n++){ // 长度偶数：abccba
            res++;
        }
    }
    
    
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        // DP原则：我们利用已知的小问题的解来求大问题的解的时候，小问题的解必须已经得到了。
        // 不可以是for (int i = 0; i<dp.size(); i++) ，因为下面需要dp[i + 1][j - 1]，所以i必须从大到小，j必须从小到大。
        for (int i = n - 1; i >= 0; i--) {  
            for (int j = i; j < n; j++) {
                dp[i][j] = s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1]); // 这个好像不太好记忆，不如我二刷的思路：按照长度的奇偶性分别判断
                if(dp[i][j]) ++res; //如果[i,j]可以构成回文串
            }
        }
        return res;
    }
    
    
};