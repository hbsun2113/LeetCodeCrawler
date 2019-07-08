class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n=A.size();
        vector<unordered_map<int,int>> dp(n);
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long long diff=A[i]+0ll-A[j];
                if(diff<INT_MIN || diff>INT_MAX) continue;
                dp[i][diff]+=1;
                if(dp[j].count(diff)){   
                    res+=dp[j][diff];
                    dp[i][diff]+=dp[j][diff];
                }
            }
        }
        return res;
    }
};