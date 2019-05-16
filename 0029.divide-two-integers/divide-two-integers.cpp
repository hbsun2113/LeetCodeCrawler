class Solution {
public:
    //照抄http://www.cnblogs.com/grandyang/p/4431949.html
    //自己总结一下经验，以后遇到这种可能溢出的问题，直接上long long。
    int divide(int dividend, int divisor) { 
        if(((dividend==INT_MIN)&&(divisor==-1)) || divisor==0) return INT_MAX;
        int sign=((dividend>0) ^ (divisor>0))?-1:1;
        long long a=labs(dividend),b=labs(divisor); //要使用long long，否则是INY_MIN时，会发生溢出
        // int  a=abs(dividend),b=abs(divisor);
        if(b==1) return sign*a;
        int result=0;
        while(b<=a){
            long long tmp=b; //tmp如果是int，则可能发生溢出问题。
            int count=1;
            while((tmp<<1)<=a){
                tmp<<=1;
                count<<=1;
                // cout<<a<<" "<<tmp<<" "<<count<<endl;
            }
            a-=tmp;
            result+=count;
            cout<<tmp<<" "<<result<<endl;
        }
        return sign==1?result:-result;
        
        
        
        
    }
};