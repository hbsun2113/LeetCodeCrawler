/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (46.76%)
 * Total Accepted:    271.2K
 * Total Submissions: 578.6K
 * Testcase Example:  '3\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * How many possible unique paths are there?
 * 
 * 
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 7, n = 3
 * Output: 28
 * 
 */
class Solution {
public:
    // 二刷，dp
    int uniquePaths3(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1 || j==1){
                    dp[i][j]=1;
                    continue;
                }
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
    }
    
    // 数学解法
    // https://www.acwing.com/solution/LeetCode/content/54/ 
    int uniquePaths(int m, int n) {
        long long res=1;
        long long total=m+n-2;
        int base=min(m-1,n-1);
        for(int i=1;i<=base;i++)
            res*=(total--);
        for(int i=1;i<=base;i++)
            res/=i;
        return res;
    }



    int uniquePaths2(int m, int n) {
        int sum[100][100];
        sum[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!(i==0&&j==0)){
                    sum[i][j]=0;
                    if(i-1>=0){
                       sum[i][j]+=sum[i-1][j];
                    }
                    if(j-1>=0){
                       sum[i][j]+=sum[i][j-1];
                    }
                }
            }
        }
        return sum[m-1][n-1];
    }
//比较简单的DP问题，用sum数组记录到达该块的路径数目。由于只能向下或者向右走，因此每个块的来源就一定要么来源与上面，要么来源于左面，因此只要把这俩个sum对应的值进行相加就可以了。
//这道题独立完成，没有借鉴什么资料，好像这道题目在哪里见过。
//另外 这道题目进行暴力求解(递归)会堆栈溢出。
    int uniquePaths1(int m, int n) {
        int sum=0;
        path(1,1,sum,m,n);
        return sum;
    }
    
    void path(int x,int y,int& sum,int &m,int &n){
        if(x==m && y==n){
            sum+=1;
            return ;
        }
        if(x==m){
            path(x,y+1,sum,m,n);
        }
        else if(y==n){
            path(x+1,y,sum,m,n);
        }
        else{
            path(x,y+1,sum,m,n);
            path(x+1,y,sum,m,n);
        }
    }
};

