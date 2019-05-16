class Solution {
public:
    //自己没有做出来。答案也是有点不能完全理解。https://blog.csdn.net/taoyanqi8932/article/details/52129450
    int trailingZeroes(int n) {
        int result=0;
        while(n>0){
            result+=n/5;
            n/=5;
        }
        return result;
    }
};