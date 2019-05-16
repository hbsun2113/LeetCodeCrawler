class Solution {
public:
    // 三刷做得不好，希望以后自己能直接做出来
    int maxCoins3(vector<int>& nums) {
        return 0;
    }
    
    
    
    
    
    
    
    
    //二刷没有想出来。感觉这个好难
    // 1.https://www.acwing.com/solution/LeetCode/content/297/
    // 2.http://www.cnblogs.com/grandyang/p/5006441.html
    int maxCoins(vector<int>& nums) {
        int length=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(length+2,vector<int>(length+2));
        for(int len=1;len<=length;len++){ //和其他题目不同，最外层循环是子区间长度。(因为大区间的解是由小区间的解构成的)
            for(int l=1;l<=length-len+1;l++){ //极限情况下len==length
                int r=l+len-1;
                for(int k=l;k<=r;k++) //k可以理解成[i,j]范围里最后戳破的一个气球。
                    dp[l][r]=max(dp[l][r],dp[l][k-1]+nums[l-1]*nums[k]*nums[r+1]+dp[k+1][r]);
            }
        }
        return dp[1][length];
    }
    
    
    
    //参考了http://www.cnblogs.com/grandyang/p/5006441.html，自己没有做出来。
    int maxCoins1(vector<int>& nums) {
        int n=nums.size();//保留原始长度
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        vector<vector<int>> result(nums.size(),vector<int>(nums.size(),0));
        
        for(int i=1;i<=n;i++){ //长度
            for(int l=1;l<=n-i+1;l++){ //左边界
                int r=l+i-1; //右边界：[1,nums.size()]
                for(int f=l;f<=r;f++){
                    result[l][r]=max(result[l][r],result[l][f-1]+result[f+1][r]+nums[l-1]*nums[f]*nums[r+1]);
                }
            }
        }
        
        return result[1][n];
    }
};