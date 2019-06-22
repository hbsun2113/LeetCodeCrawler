class Solution {
public:
    // 这道题目之所以不能直接使用二分法，是因为鸡蛋数量的限制，我们要确保一定可以找到F。
    // 直接使用二分，可能还没找到F，鸡蛋就使用没了。
    int NN,KK;
    
    // 这个会TLE
    // https://blog.csdn.net/u013457382/article/details/49035821
    int superEggDrop1(int K, int N) {
        vector<vector<int>> dp(N+1,vector<int>(K+1,INT_MAX)); // 有N层，K个鸡蛋，需要的最小次数
        
        // 只有一个鸡蛋，最坏情况下，可能全部试了一遍。因为怕碎，所以只能从最低的开始测试，直到破碎。最坏的情况下可能到第N层都没碎。
        
        for(int n=0;n<=N;n++){
            dp[n][1]=n;
            dp[n][0]=0;
        }
        
        // N==0不用测试，N==1,无论鸡蛋有几个，测试一次就行。
        for(int k=0;k<=K;k++){
            dp[0][k]=0;
            dp[1][k]=1;
        }
        
        for(int n=1;n<=N;n++){
            for(int k=2;k<=K;k++){
                for(int j=1;j<=n;j++) 
                    // 如果该层破了，则只测试下面j-1层就行了，剩下k-1个鸡蛋。
                    // 没有破，则只测试上面n-j层，剩下k个鸡蛋
                    // 取最坏的情况
                    dp[n][k]=min(dp[n][k],max(dp[j-1][k-1],dp[n-j][k])+1);
            }
        }
        
        return dp[N][K];
    }    
    
    
    // 针对superEggDrop1进行二分优化：第三层循环没有必要，可以使用二分法
    // https://leetcode.com/problems/super-egg-drop/discuss/159055/Java-DP-solution-from-O(KN2)-to-O(KNlogN)
    // https://leetcode.com/articles/super-egg-drop/
    // 解释一下这个图片：因为dp[N][K]随着N增大而增大，所以T1开始一定是小于T2的，因为T1是从X-1开始，而T2是从N-X开始，而X是从小到大的。
    // 同理最后一定是T2小于T1。
    // 为保证max(T1,T2)最小，我们只要找到一个点，使得T1和T2最为接近。就找到了minmax
    // 因此我们使用二分法代替最后一层的j循环
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N+1,vector<int>(K+1,INT_MAX)); // 有N层，K个鸡蛋，需要的最小次数
        
        for(int n=0;n<=N;n++){
            dp[n][1]=n;
            dp[n][0]=0;
        }
        
        for(int k=0;k<=K;k++){
            dp[0][k]=0;
            dp[1][k]=1;
        }
        
        for(int n=1;n<=N;n++){
            for(int k=2;k<=K;k++){
                int l=1, r=n;
                while(l<r){  // 找到第一个dp[n-1][k-1]>=dp[n][k] 
                    int mid=l+r>>1;
                    int left=dp[mid-1][k-1];
                    int right=dp[n-mid][k];
                    if(left>=right) r=mid;
                    else l=mid+1;
                    
                    //dp[n][k]=min(dp[n][k], max(left,right)+1); // minmax
                    // cout<<mid-1<<" "<<k-1<<" "<<left<<" | "<<n-mid<<" "<<k<<" "<<right<<endl;
                }
                dp[n][k]=dp[r-1][k-1]+1;  // 或者不使用minmax，直接这样
            }
        }
        
        return dp[N][K];
    }
};