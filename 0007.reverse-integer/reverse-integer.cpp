class Solution {
public:
    //http://www.cnblogs.com/grandyang/p/4125588.html
    int reverse(int x) {
        int result=0;
        while(x!=0){
            if(abs(result)>INT_MAX/10) return 0;  //是>不是>=,因为等于没有问题。
            result=result*10+x%10;
            x/=10;
        }
        return result;
         
    }
};