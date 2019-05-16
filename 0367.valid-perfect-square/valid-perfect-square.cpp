class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l=-1,r=num;
        while(l+1<r){
            long long mid=l+(r-l)/2;  //mid*mid可能会溢出int，所以使用long long。
            if(mid*mid==num) return true;
            else if(mid*mid<num) l=mid;
            else r=mid;
        }
        if(r*r==num) return true; //这步别拉下！
        return false;
    }
};