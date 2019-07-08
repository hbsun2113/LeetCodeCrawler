#define dbv(v) cout << #v << "="; for (auto _x : v) cout << _x << ", "; cout << endl
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> vec(110);  //vec[i]代表从i出发可以到达的目的地集合{目的地id,i到目的地的费用}
        for(const auto &f:flights){
            int src=f[0],dst=f[1],price=f[2];
            vec[src].push_back({dst,price});
        }
        
        queue<pair<int,int>> q;
        q.push({src,0});
        vector<int> minv(110,INT_MAX); //minv[i]代表从src出发到i的最小费用
        minv[src]=0;
        while(!q.empty()){
            if(K--<0) break;
            int size=q.size(); // 层序遍历
            for(int i=0;i<size;i++){
                auto t=q.front();
                q.pop();
                int cur_position=t.first;
                int cur_price=t.second;
                for(const auto v:vec[cur_position]){
                    int next_position=v.first;
                    int next_price=v.second;
                    if(minv[next_position]<cur_price+next_price) continue; // 如果已经拿到了更小值，就不必再入队了
                    minv[next_position]=cur_price+next_price;
                    q.push({next_position,cur_price+next_price});
                }
            }   
        }
        
        if(minv[dst]==INT_MAX) return -1;
        else return minv[dst];
    }
    
    
    // dp超慢:https://leetcode.com/problems/cheapest-flights-within-k-stops/discuss/115548/C++-solution-using-Dynamic-Programming
    // 注意原贴中先对K++了
    int findCheapestPrice1(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> dp(110,vector<int>(K+2,INT_MAX)); // dp[i][j] 代表从src到i，在中转次数小于等于j时，的最小费用
        dp[src][0]=0;
        for(int k=1;k<=K+1;k++){
            for(int i=0;i<110;i++) dp[i][k]=dp[i][k-1];
            for(const auto f:flights){
                if(dp[f[0]][k-1]!=INT_MAX){
                    dp[f[1]][k]=min(dp[f[1]][k], dp[f[0]][k-1]+f[2]);
                }
                    
            }
        }
        if(dp[dst][K+1]==INT_MAX) return -1;
        else return dp[dst][K+1];
    }
};