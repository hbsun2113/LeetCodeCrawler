class Solution {
public:
    //三更，注意它和II不同，只允许买卖两次，因此hold1和sell1是有顺序的、sell1和hold2是有顺序的、hold2和sell2是有顺序的。
    // for循环的形式很齐整啊，左侧都是i-1，右侧都是i。
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int len=prices.size();
        vector<int> hold1(len),hold2(len),sell1(len),sell2(len);
        hold1[0]=-prices[0];
        hold2[0]=INT_MIN;
        for(int i=1;i<len;i++){           
            hold1[i]=max(hold1[i-1],-prices[i]);
            sell1[i]=max(sell1[i-1],hold1[i]+prices[i]);
            hold2[i]=max(hold2[i-1],sell1[i]-prices[i]); // you must sell the stock before you buy again
            sell2[i]=max(sell2[i-1],hold2[i]+prices[i]);
        }
        return sell2[len-1];
    }
    
    
    //二更，直接自己做出来
    //四个数组，分别是hold1,hold2,sell1,sell2。现在写出状态方程
    // 注意其实使用数组解决这道题目能更好地理解这个题目。顺序一定是先hold，后sell，也就是说sell由hold决定。
    // 1. hold1[i]=max(hold1[i-1],sell[i-1]-prices[i])
    // 2. sell1[i]=max(sell1[i-1],hold[i-1]+prices[i])
    // 3. hold2[i]=max(hold2[i-1],sell1[i]-prices[i])
    // 4. sell2[i]=max(sell2[i-1],hold2[i]+prices[i])
    int maxProfit1(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int len=prices.size();
        vector<int> sell1(len,0),hold1(len,0),sell2(len,0),hold2(len,0);
        hold1[0]=-prices[0],hold2[0]=INT_MIN; //hold2初始化为INT_MIN，是为了保证在第一次进入循环时就可以被sell1赋值。
        for(int i=1;i<len;i++){
            hold1[i]=max(hold1[i-1],-prices[i]);
            sell1[i]=max(sell1[i-1],hold1[i-1]+prices[i]);
            hold2[i]=max(hold2[i-1],sell1[i]-prices[i]);
            sell2[i]=max(sell2[i-1],hold2[i]+prices[i]);
        }
        return sell2[len-1];
    }
    
    
    
    
    //完全参考了https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39611/Is-it-Best-Solution-with-O(n)-O(1).
    int maxProfit2(vector<int>& prices) {
        int hold1=INT_MIN,hold2=INT_MIN;
        int sold1=0,sold2=0;
        for(const auto &p:prices){
            hold1=max(hold1,-p);
            sold1=max(sold1,hold1+p);
            hold2=max(hold2,sold1-p);
            sold2=max(sold2,hold2+p);
        }
        return sold2;
    }
};