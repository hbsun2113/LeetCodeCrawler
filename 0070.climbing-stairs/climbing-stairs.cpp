class Solution {
//水题 不解释。看上一道题目的解释就可以了。
public:
    int climbStairs(int n) {
        int sum[10000];
        sum[1]=1;
        sum[2]=2;
        for(int i=3;i<1000;i++)
            sum[i]=sum[i-1]+sum[i-2];
        return sum[n];
    
        
    }
};