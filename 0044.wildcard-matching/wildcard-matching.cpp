class Solution {
public:
    // https://www.cnblogs.com/grandyang/p/4401196.html
    bool isMatch(string s, string p) {
        // if(s.size()==0 && p.size()!=0 && p[0]!='*') return false;
        // if(p.size()==0 && s.size()!=0) return false;
        // if(s.size()==0 && p.size()==0) return true;
        int lens=s.size();
        int lenp=p.size();
        vector<vector<int>> dp=vector<vector<int>>(lens+1,vector<int>(lenp+1,0));
        dp[0][0]=1;
        for(int j=1;j<=lenp;j++){
            if(p[j-1]=='*') 
                dp[0][j]=dp[0][j-1]; // 当s为空，p为连续的星号时的情况
        }
        for(int i=1;i<=lens;i++){
            for(int j=1;j<=lenp;j++){
                if(p[j-1]==s[i-1] || p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j]=dp[i-1][j] | dp[i][j-1];  // dp[i-1][j]是使用了*。而dp[i][j-1]是忽略了*，即j的位置是空串。
            }
        }
        return dp[lens][lenp];  
    }
};

/*
s: abccc
p: abc*

j=3,在*位置
s中三个c分别对应了：
i=2  [i][j-1]
i=3  [i-1][j-1]
i=4  [i-1][j]
其中后两者情况可以合并为[i-1][j]，因为如果[i-1][j-1]为true,则[i-1][j]肯定也为true。
*/