class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if(N==0) return 0; // 这个可别忘了~
        vector<vector<vector<long long>>> dp(N+1, vector<vector<long long>>(m+1, vector<long long>(n+1,0))); //注意类型要是long!
        long long C=1000000007;
        for(int i=0;i<m;i++){
            dp[1][i][0]++;
            dp[1][i][n-1]++;
        }
        for(int i=0;i<n;i++){
            dp[1][0][i]++;
            dp[1][m-1][i]++;
        }
        
        vector<int> dx{0,0,1,-1};
        vector<int> dy{1,-1,0,0};
        for(int k=2;k<=N;k++){
            for(int x=0;x<m;x++){
                for(int y=0;y<n;y++){
                    for(int t=0;t<4;t++){
                        int xx=x+dx[t];
                        int yy=y+dy[t];
                        if(xx<0 || xx>=m || yy<0 || yy>=n) continue;
                        dp[k][x][y]=(dp[k][x][y]+dp[k-1][xx][yy])%C;
                    }
                }
            }
        }
    
        long long res=0;
        for(int k=1;k<=N;k++)
            res=(res+dp[k][i][j])%C;
        return res;
    }
    
    
    
    //https://www.acwing.com/solution/LeetCode/content/457/
    int findPaths1(int m, int n, int N, int i, int j) {
        if(N==0) return 0;
        long long mod=1000000007;
        vector<vector<vector<long>>> vec(N+1,vector<vector<long>>(m,vector<long>(n,0)));
        for(int i=0;i<m;i++){
            vec[1][i][0]++;
            vec[1][i][n-1]++;
        }
        for(int i=0;i<n;i++){
            vec[1][0][i]++;
            vec[1][m-1][i]++;
        }
        cout<<1<<endl;
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        cout<<2<<endl;
        for(int k=2;k<=N;k++)
            for(int i=0;i<m;i++)
                for(int j=0;j<n;j++)
                    for(int t=0;t<4;t++){
                        int x=i+dx[t];
                        int y=j+dy[t];
                        if(x<0 || x>=m || y<0 || y>=n) continue;
                        vec[k][i][j]=(vec[k][i][j]+vec[k-1][x][y])%mod;
                    }
        cout<<3<<endl;
        int res=0;
        for(int k=1;k<=N;k++)
            res=(res+vec[k][i][j])%mod;
        cout<<res<<endl;
        return res;
    }
};