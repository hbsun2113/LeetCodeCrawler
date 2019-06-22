class Solution {
public:
    
    // dp[i][j]代表str1中前i个字符和str2中前j个字符中最多有多少个相同的部分
    // 参考自：https://leetcode.com/problems/shortest-common-supersequence/discuss/312776/ChineseC%252B%252B-1092.-LCS()/290711
    string shortestCommonSupersequence1(string &str1, string &str2){
        if(str1.size()<str2.size()) swap(str1,str2);
        int len1=str1.size(),len2=str2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1));
        //vector<pair<int,int>> vec; 
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                /*
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+(str1[i-1]==str2[j-1]));
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
                */
                // 注意上面的代码是不对的，没有显示LCS的本质：即`str1[i-1]==str2[j-1]`和`str1[i-1]!=str2[j-1]`是互斥的
                // 因为dp[i-1][j]或dp[i][j-1]至多比dp[i-1][j-1]多一位
                if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<<dp[len1][len2]<<endl;
        
        string res;
        int i=len1,j=len2;
        while(i!=0 || j!=0){
            if(i==0){
                res+=str2[--j];
                continue;
            }
            if(j==0){
                res+=str1[--i];
                continue;
            }
            if(str1[i-1]==str2[j-1]){
                res+=str1[i-1];
                i--;
                j--;
                continue;
            }
            else{ // 都到这一步了，说明此时的i或者j至少有一个不是最长公共子序列的一部分，接下来要去看看到底哪个不是
                if(dp[i][j]==dp[i][j-1]){ // 说明dp[i][j]来源于dp[i][j-1]，所以j没有用来构造最优解，但我们要把它加上
                    res+=str2[--j];
                }
                else{
                    res+=str1[--i];
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    // https://leetcode.com/problems/shortest-common-supersequence/discuss/312710/C++Python-Find-the-LCS
    string shortestCommonSupersequence(string &str1, string &str2){
        int len1=str1.size(),len2=str2.size();
        vector<vector<string>> dp(len1+1,vector<string>(len2+1,""));
        // 求最长公共子序列
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+str1[i-1];
                }
                else{
                    if(dp[i-1][j].size()>dp[i][j-1].size()) dp[i][j]=dp[i-1][j];
                    else dp[i][j]=dp[i][j-1];
                }
            }
        }
        cout<<dp[len1][len2]<<endl;
        
        string res="";
        int i=0,j=0;
        // 只要没碰到公共部分，就加到res里面
        for(const auto &c:dp[len1][len2]){
            while(str1[i]!=c) res+=str1[i++];
            while(str2[j]!=c) res+=str2[j++];
            res+=c;
            i++,j++;
        }
        res+=str1.substr(i);
        res+=str2.substr(j);
        return res;
    }
};