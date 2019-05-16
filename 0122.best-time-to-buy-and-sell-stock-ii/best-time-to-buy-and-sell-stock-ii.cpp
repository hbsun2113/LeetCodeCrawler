class Solution {
public:
    //四更
    
    
    
    
    
    
    
    
    
    
    
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int len=prices.size();
        vector<int> sell(len),hold(len);
        hold[0]=-prices[0];
        for(int i=1;i<prices.size();i++){
            hold[i]=max(hold[i-1],sell[i-1]-prices[i]);
            sell[i]=max(sell[i-1],hold[i-1]+prices[i]);
        }
        return sell[len-1];
    }
    
    
    
    //三更
    int maxProfit1(vector<int>& prices) {
        int len=prices.size();
        if(len==0) return 0;
        vector<int> you(len),wu(len);
        you[0]=-prices[0];
        for(int i=1;i<len;i++){
            you[i]=max(you[i-1],wu[i-1]-prices[i]);
            wu[i]=max(wu[i-1],you[i-1]+prices[i]);
        }
        return wu[len-1];
    }
};