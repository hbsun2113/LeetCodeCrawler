class Solution {
public:
    // 更清晰
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int s:stones)
            sum += s;
        const int m = sum / 2;
        bitset<1501> dp = {1};
        for (int st:stones)
            for (int i = m; i >= st; --i)
                dp[i] = dp[i] + dp[i - st];
        for (int i = m; i >= 0; --i)
            if (dp[i]) return sum - 2 * i;
        return 0;
    }
    
    // 分成两组A、B
    // smallest:abs(A-B)
    // abs(A-B+A+B)->abs(2A)
    // smallest:abs(2A-sum)
    // 现在开始寻找A的可能值,假设A是小的那组，即A的和不会超过1500, 这样可以节省空间
    int lastStoneWeightII2(vector<int>& stones) {
        int sum=accumulate(stones.begin(),stones.end(),0);
        cout<<"sum="<<sum<<endl;
        vector<bool> dp(1501,0); // dp[i]=true代表有一组数字可以达成i,否则不可以
        dp[0]=true;
        for(const auto &s:stones){
            for(int i=1500;i>=s;i--)
                dp[i] = dp[i] || dp[i-s];
        }
        
        int res=INT_MAX;
        for(int i=0;i<dp.size();i++){
            if(dp[i]){
                cout<<i<<" ";
                res=min(res,abs(sum-2*i));
            }
        }
        return res;
    }
    // https://leetcode.com/problems/last-stone-weight-ii/discuss/294888/JavaC%2B%2BPython-Easy-Knapsacks-DP/277437
    // https://leetcode.com/problems/last-stone-weight-ii/discuss/294881/Another-kind-of-coin-change-problem
};