class Solution {
public:
   // 二更没有做出来，自己争取做出来！
   // 看看之前的答案，似乎写的不错。
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //三刷
    int maxProfit3(int k, vector<int>& prices) {
        if(k==0) return 0;
        int len=prices.size();
        if(k>=len/2){  // 如果满足这个条件，那么k其实就相当于什么也没限制住
            int res=0;
            for(int i=1;i<len;i++)
                if(prices[i]>prices[i-1])
                    res+=(prices[i]-prices[i-1]);
            return res;
        }
        vector<int> hold(k,INT_MIN);  //hold[i]代表第k次持有时能获得的最大收益
        vector<int> sell(k,INT_MIN);  
        for(const auto &p:prices){
            hold[0]=max(hold[0],-p);
            sell[0]=max(sell[0],hold[0]+p);
            for(int i=1;i<k;i++){
                hold[i]=max(hold[i],sell[i-1]-p);  // 卖了才能再买，倒是和hold[i-1]没有什么关系
                sell[i]=max(sell[i],hold[i]+p);    // 
            }
        }
        return sell[k-1];
    }
    
    
    //完全自己做的，和discuss里面的方法不同，而我还是延照https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/的思路。
    int maxProfit1(int k, vector<int>& prices) {
        if(k==0 || prices.size()==0) return 0;
        cout<<k<<" "<<prices.size()<<endl;
        k=min(k,((int)prices.size()+1)/2);
        
        vector<int> hold(k,INT_MIN);
        vector<int> sold(k,0);
        
        for(const auto &p:prices){
            hold[0]=max(hold[0],-p);
            sold[0]=max(sold[0],hold[0]+p);
            for(int i=1;i<k;i++){
                hold[i]=max(hold[i],sold[i-1]-p);
                sold[i]=max(sold[i],hold[i]+p);
            }
        }
        
        return sold[k-1];
        
    }
    
    int maxProfit5(int k, vector<int>& prices) {
        if(prices.size()==0 || k==0) return 0;
        vector<int> hold(k,INT_MIN),sold(k);
        for(const auto &p:prices){
            hold[0]=max(hold[0],-p);
            sold[0]=max(sold[0],hold[0]+p);
            for(int i=1;i<k;i++){
                hold[i]=max(hold[i],sold[i-1]-p);
                sold[i]=max(sold[i],hold[i]+p);
            }    
        }
        return sold[k-1];
    }
    
    
    //稍微优化一下k>prices.size()的情况,提速效果明显。
    int maxProfit(int k, vector<int>& prices) {
        if(k==0 || prices.size()==0) return 0;
    
        if(k>=(prices.size()+1)/2){
            int result=0;
            for(int i=1;i<prices.size();i++) result+=max(0,prices[i]-prices[i-1]);
            return result;
        }
        
        vector<int> hold(k,INT_MIN);
        vector<int> sold(k,0);
        
        for(const auto &p:prices){
            hold[0]=max(hold[0],-p);
            sold[0]=max(sold[0],hold[0]+p);
            for(int i=1;i<k;i++){
                hold[i]=max(hold[i],sold[i-1]-p);
                sold[i]=max(sold[i],hold[i]+p);
            }
        }
        
        return sold[k-1];
    }
};