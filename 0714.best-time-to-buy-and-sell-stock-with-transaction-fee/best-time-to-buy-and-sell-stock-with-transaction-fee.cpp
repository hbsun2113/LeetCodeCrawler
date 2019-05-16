class Solution {
public:
    //自己没有做出来，这是一个系列的问题。(https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems)
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108884/JavaC++-Clean-Code-(DPGreedy)
    //在某个节点，要么是持有状态，要么是不持有状态。因此定义了两个vector。
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> hold(prices.size());
        vector<int> sold(prices.size());
        hold[0]=0-prices[0];
        sold[0]=0;
        for(int i=1;i<prices.size();i++){
            hold[i]=max(hold[i-1],sold[i-1]-prices[i]);
            sold[i]=max(sold[i-1],hold[i-1]+prices[i]-fee);
        }
        return sold[sold.size()-1];
        
            
    }
};