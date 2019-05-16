class Solution {
public:
    //dp[i][j]代表前i个数可以组成金额j的最小消耗。
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,INT_MAX));
        for(int i=0;i<dp.size();i++)
            dp[i][0]=0;
        for(int i=1;i<=coins.size();i++){
            for(int j=0;j<=amount;j++){
                dp[i][j]=min(dp[i][j],dp[i-1][j]);
                if(j>=coins[i-1] && dp[i][j-coins[i-1]]!=INT_MAX){
                    dp[i][j]=min(dp[i][j],dp[i][j-coins[i-1]]+1);
                }
            }
        }
        if(dp[coins.size()][amount]==INT_MAX) return -1;
        return dp[coins.size()][amount];
        
    }
    
    // 四刷，dfs暴力求解没有AC，超时了
    int res;
    int coinChange4_dfs(vector<int>& coins, int amount) {
        res=INT_MAX;
        dfs(coins,0,amount,0,0);
        if(res==INT_MAX) return -1;
        return res;
    }
    
    void dfs(vector<int>& coins, int count, int amount, long long curr, int start){
        // cout<<start<<" "<<curr<<" "<<count<<endl;
        if(start>=coins.size() || curr>amount) return;
        if(curr==amount){
            res=min(res,count);
            return;
        }
        for(int i=start;i<coins.size();i++){
            dfs(coins,count+1,amount,curr+0l+coins[i],i);
        }
    }
    
    
    
    //三刷还是不熟练，dp[i][j]代表前i个数可以组成金额j的最小消耗。
    int coinChange3(vector<int>& coins, int amount) {
        int len=coins.size();
        vector<vector<int>> vec(len+1,vector<int>(amount+1,INT_MAX));
        for(int i=0;i<len+1;i++){
            vec[i][0]=0;
        }
        for(int i=1;i<len+1;i++){
            for(int j=0;j<=amount;j++){
                vec[i][j]=min(vec[i-1][j], vec[i][j]);
                if(j>=coins[i-1] && vec[i][j-coins[i-1]]!=INT_MAX)
                    vec[i][j]=min(vec[i][j],vec[i][j-coins[i-1]]+1);
            }
        }
        if(vec[len][amount]==INT_MAX) return -1;
        return vec[len][amount];
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //二刷，做了很久很久。虽然一刷是自己做的，但是初始化为-1是非常不明智的。
    int coinChange1(vector<int>& coins, int amount) {
        vector<vector<int>> vec(coins.size()+1,vector<int>(amount+1,INT_MAX-1));  //使用max初始化，因为我们后面都是要找最小值
        for(int i=0;i<=coins.size();i++) vec[i][0]=0;
        for(int i=1;i<=coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(j<coins[i-1])
                    vec[i][j]=vec[i-1][j];
                else
                    vec[i][j]=min(vec[i-1][j],vec[i][j-coins[i-1]]+1);
                
                // vec[i][j]不会超过INT_MAX-1
            }
        }
        if(vec[coins.size()][amount]==INT_MAX-1) return -1;
        return vec[coins.size()][amount];
    }
    
   

    
};