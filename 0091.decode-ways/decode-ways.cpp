class Solution {
public:
    
    // 二刷，思路不难，但是做得不利索
    int numDecodings(string s) {
        if(s.size()==0) return 0;
        if(s[0]=='0') return 0;
        if(s.size()==1) return 1;
        vector<long long> dp(s.size(),0);
        dp[0]=1;
        if(s[1]!='0') dp[1]=dp[0];
        if(s.substr(0,2)<="26") dp[1]++;
        for(int i=2;i<s.size();i++){
            if(s[i]!='0') dp[i]=dp[i-1]; // 如果自己可以独立
            if(s[i-1]!='0'  && s.substr(i-1,2)<="26") dp[i]+=dp[i-2]; // 如果自己可以和前一个字符拼接
        }
        return dp[s.size()-1];
    }
    
    
    
    
    //容易考虑不全面
    int numDecodings1(string s) {
        if(s.size()==0) return 0;
        vector<long long> vec(s.size()+1);
        vec[0]=1;
        vec[1]=1;
        if(s[0]=='0') vec[1]=0;
        for(size_t i=2;i<=s.size();i++){
            if(s[i]!='0') vec[i]+=vec[i-1];
            string tmp=s.substr(i-2,2);
            if(tmp<="26" && s[i-1]!='0') vec[i]+=vec[i-2];
        }
        return vec.back(); 
    }
};