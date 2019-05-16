class Solution {
public:
    //二刷自己做出来了
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int len=prices.size();
        vector<int> hold(len),sell(len);
        hold[0]=-prices[0];
        hold[1]=max(-prices[0],-prices[1]);
        sell[0]=0;
        sell[1]=max(0,hold[0]+prices[1]);
        for(int i=2;i<len;i++){
            hold[i]=max(hold[i-1],sell[i-2]-prices[i]);
            sell[i]=max(sell[i-1],hold[i-1]+prices[i]);
        }
        return sell[len-1];
    }
    
    
    
    
    
    
    
    
    
    //参考了https://soulmachine.gitbooks.io/algorithm-essentials/java/dp/best-time-to-buy-and-sell-stock-with-cooldown.html
    //首先定义两个状态：当前持有状态you和当前未持有状态wu。
    //最后肯定是未持有状态才能实现利益最大化，因此return wu[wu.size()-1];
    //难点在于是如何想到要定义两个状态的，靠！
    //我猜测一下应该是这么想的：先确定我们要求的是最后的最大利益，因此定义的状态是当前的最大利益。
    //                      最后一个状态要么是无操作(没有什么可卖的)，要么是现在卖了。
    //                      所以我们发现其实可以衍生出两个新的状态进行求解：“当前持有”和“当前未持有”。
    //哈哈哈，随便解释一下，求一个心理安慰，感觉好难啊。
    int maxProfit1(vector<int>& prices) {
        if(prices.size()==0) return 0;
        vector<int> you(prices.size());//持有股票时得到的最大利润
        vector<int> wu(prices.size());//未持有股票时得到的最大利润
        
        wu[0]=0; 
        wu[1]=(prices[1]-prices[0]>=0)?prices[1]-prices[0]:0;
        you[0]=-1*prices[0];
        you[1]=max(-1*prices[0],-1*prices[1]);
        
        for(int i=2;i<wu.size();i++){
            you[i]=max(wu[i-2]-prices[i],you[i-1]);//现在是持有状态，1.昨天就持有 2.今天买了
            wu[i]=max(wu[i-1],you[i-1]+prices[i]);//现在是未持有状态，1.昨天就未持有 2.今天卖了
        }
        
        return wu[wu.size()-1];
        
    }
};