class Solution {
public:
    //(1+num)*num/2; 自己写的
    int arrangeCoins1(int n) {
        long long l=-1,r=n;
        while(l+1!=r){
            long long mid=l+(r-l)/2;
            long long sum=(1+mid)*mid/2;
            if(sum==n) return mid;
            else if(sum<n) l=mid;
            else r=mid;
        }
        if((1+r)*r/2==n) return r;
        else return r-1;
    }
    
    
    //使用数学方法，试验发现它最快，但是我没有去读这个代码。
    int arrangeCoins(int n) {
        return floor(-0.5+sqrt((double)2*n+0.25));
    }



};