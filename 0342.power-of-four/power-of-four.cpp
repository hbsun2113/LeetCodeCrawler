class Solution {
public:
    //https://www.cnblogs.com/grandyang/p/5403783.html
    bool isPowerOfFour(int num) {
        if(!(num&(num-1)) && (num&0x55555555)) return true;
        return false;
    }
};