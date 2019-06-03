class Solution {
public:
    
    bool canWinNim(int n) {
        return (n & 3) != 0;
    }
    
    bool canWinNim2(int n) {
        if(n>=134882061) return n%4 != 0;
        if(n<=3) return true;
        bool a,b,c;
        a=b=c=true;
        bool t;
        for(int i=4;i<=n;i++){
            if(!a || !b || !c) t=true;
            else t=false;
            a=b,b=c,c=t;
        }
        return c;
    }
    
    
    bool canWinNim1(int n) {
        if(n>=134882061) return n%4 != 0;
        if(n<=3) return true;
        vector<int> vec(n+1);
        for(int i=1;i<=3;i++) vec[i]=true;
        for(int i=4;i<=n;i++){
            if(!vec[i-1] || !vec[i-2] || !vec[i-3]) vec[i]=true;
            else vec[i]=false;
        }
        return vec[n];
    }
};