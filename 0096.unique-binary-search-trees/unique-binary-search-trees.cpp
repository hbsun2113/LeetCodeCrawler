
class Solution {
public:
    //三更，终于自己做出来了
    int numTrees(int n) {
        vector<int> vec(n+1);// vec[i]代表当树中有n个节点时，我们有vec[i]种排列
        vec[0]=1;
        vec[1]=1;
        for(int i=2;i<=n;i++){ // 按顺序求解
            for(int j=0;j<=i-1;j++){ // 左子树的数目肯定在[0,i-1]区间。
                vec[i]+=(vec[j]*vec[i-j-1]);
            }
        }
        return vec[n];
    }
    
    
    // 二更，没有做出来.
    // 树本应该用递归解，但这里同样使用了dp来优化时间。
    // 不用考虑谁是root,直接考虑左右子树的数目就行了。
    int numTrees2(int n) {
        if(n<=1) return 1;
        vector<int> dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++){ //i是子树的节点数目
            dp[i]=0;
            for(int j=0;j<=i-1;j++){ //左子树：[0,i-1] 右子树：[i-1,0]
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
    
    
    //http://blog.csdn.net/linhuanmars/article/details/24761459
//这道题目的入手点和树的结构关系不大。当节点数目为n的时候，左子树的节点数目和右子树的节点数目之和为n-1。其中，左子树的节点数目的可能性就为[0,n-1]，可以对应求出右子树节点的数目。所以总节点数目固定时，其实就是看看左子树和右子树一共有多少组合(即二者相乘)。
//DP问题。
    int numTrees1(int n) {
        vector<int> result(n+1);
        result[0]=1;
        result[1]=1;
        for(int i=2;i<=n;i++){//i是总的节点数目
            for(int j=0;j<i;j++)//j是左子树的节点数目
                result[i]+=result[j]*result[i-1-j];
        }
        return result[n];
    }
};