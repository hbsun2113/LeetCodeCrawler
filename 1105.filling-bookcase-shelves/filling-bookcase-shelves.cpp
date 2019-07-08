class Solution {
public:
    // 比赛题目，自己没有想到如何使用dp做
    // https://leetcode.com/problems/filling-bookcase-shelves/discuss/323315/Java-DP-solution
    // dp[i]代表前i本书需要的最小高度
    // 如果第i本书另起炉灶，则dp[i]=dp[i-1]+h
    // 否则第i本书就可以和前面的书籍放在同一层，那我们就从第i-1本向前遍历，直到超出了shelf_width。每次向前考虑一本书，然后比较一下是否更优
    // 这道题目一开始我认为无法使用dp做，因为没有最优子结构，比如如果只看前2本书，那么最优的安排是把第2本书和1放在同一层；但是如果看前3本书，那么最优的安排是第二本应该另起炉灶。这样就不是局部最优解构成了全局最优解。
    // 现在我想明白了，上面的推导没有问题，但是结论错了。这道题目是不能使用贪心解，但是可以使用dp解，我之前是把它俩搞混了。
    
    // 我觉得动归的本质就是：暴力搜索+记忆化
    // 贪心是每步走最优，但最后不一定是全局最优。而动归是看全局最优。
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n=books.size();
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            int w=books[i-1][0];
            int h=books[i-1][1];
            
            dp[i]=dp[i-1]+h;// 另起一行
            
            int curw=w;
            int curh=h;              // 第i个可以和第j个放在一层
            for(int j=i-1;j>=1 && curw+books[j-1][0]<=shelf_width; j--){
                curw+=books[j-1][0];
                curh=max(curh,books[j-1][1]);
                dp[i]=min(dp[i],dp[j-1]+curh); // 对于示例：当i=3时，遍历到j=2时，就会发现第2本书和第三本书放在一下更优
            }
            
        }   
        
        return dp[n];
    
    }
    
    
    
    // 这个做法不是很好，主要是定义不清，但是memorisize的思想倒是可以学习一下
    // 参考了https://leetcode.com/problems/filling-bookcase-shelves/discuss/323305/C++-4-lines-DFS-+-Memo
    // 这个做法太trick了
    // 首先暴力DFS会TLE：https://leetcode.com/contest/weekly-contest-143/submissions/detail/239638061/
    // 我们的思路肯定是通过memorisize进行优化
    // 如果当前处理到第i本书，已有宽度是curw，已有高度是h。我们发现它被处理过了，那就不必再进行处理了
    // 但这样的话就是有三个key：i、curw、h，内存需求太大了
    // 我们转换一下思路，mem[i][curw]是，已占有宽度是curw时，要将[i...n]本书放置完毕，还需要的最小高度，
    // 即mem关注的是[i,i+1,i+2....n]需要的高度。那么已有的高度h就不再重要了。
    // 
    int res=INT_MAX;
    vector<vector<int>> mem;
    int minHeightShelves1(vector<vector<int>>& b, int s) {
        mem.resize(1010,vector<int>(1010,0));
        if(b.size()==0 || s==0) return 0;
        dfs(b,s,0,0,0);
        res=mem[0][0];
        if(res==INT_MAX) return 0;
        return res;
    }
    
    
    // i是书的索引号，curw是在某层已用的宽度，tmp是第i-1本书所在层的高度
    int dfs(vector<vector<int>>& b, int s, int i, int curw, int tmp){
        if(i>=b.size()) return tmp;
        if(mem[i][curw]!=0) return mem[i][curw];
        
        // 第i本书，另起一个新层
        mem[i][curw]=tmp+dfs(b,s,i+1,b[i][0],b[i][1]); 
        
        // 把第i本书和之前的书放在同一层
        if(curw+b[i][0]<=s){
            mem[i][curw]=min(dfs(b,s,i+1,curw+b[i][0],max(tmp,b[i][1])),mem[i][curw]);
        }
        
        return mem[i][curw];
    }
    
};