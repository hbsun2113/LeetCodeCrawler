class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n==1) return x;
        unsigned long long absn=abs(n);
        if(n<0) cout<<absn<<endl;
        double mul=1;
        if(n<0) x=1/x;
        return (absn%2 == 0) ? pow(x*x, absn/2) : x*pow(x*x, absn/2);
        // if((absn%2)==1) return x*myPow(x, absn/2)*myPow(x, absn/2);
        // else return myPow(x, absn/2)*myPow(x, absn/2);
        // return (absn%2)==1?x*myPow(x, absn/2)*myPow(x, absn/2):myPow(x, absn/2)*myPow(x, absn/2);
        // return (absn%2)==1?x*pow(x, absn/2)*pow(x, absn/2):pow(x, absn/2)*pow(x, absn/2);
    }
};


// 0.00001
