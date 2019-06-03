
class Solution {
public:
    // https://www.acwing.com/solution/LeetCode/content/279/
    // 二刷，法一
    bool isPowerOfTwo2_1(int n) {
        if(n<=0) return false;
        long long t=n;
        t=(t&(-t));
        cout<<n<<" "<<t<<endl;
        return n==t;
    }
    
    
    // 二刷，法一
    bool isPowerOfTwo2_2(int n) {
        if(n<=0) return false;
        return (n&(n-1))==0;
    }
    
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return (n&(-n))==n;
    }
    
    

    //自己的理解，有点做麻烦了。
    bool isPowerOfTwo2(int n) {
        if(n<=0) return false;
        int bit;
        while(n!=0){
            bit=n%2;
            n=(n>>1);
            if(bit==1) break;
        }
        if(n==0) return true;
        return false;
    }
};

