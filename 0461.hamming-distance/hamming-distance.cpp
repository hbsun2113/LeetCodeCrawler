class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp=(x^y);
        int res=0;
        while(tmp!=0){
            res+=(tmp & 1);
            tmp>>=1;
        }
        return res;
    }
    
    
    // log(n解法)
    // https://blog.csdn.net/zheng0518/article/details/8882394
    int hammingDistance1(int x, int y) {
        int dist = 0, n = x ^ y;
        while (n) {
            ++dist;
            n &= n - 1;
        }
        return dist;
    }
    
    
    int hammingDistance2(int x, int y) {
        return __builtin_popcount(x ^ y);
    }
};