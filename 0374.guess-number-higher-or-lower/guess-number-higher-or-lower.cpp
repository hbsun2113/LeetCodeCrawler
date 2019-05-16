// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long l=0,r=n+1ll;
        while(l+1!=r){
            int mid=(r+0ll+l)/2;
            if(guess(mid)==0) return mid;
            else if(guess(mid)==1) l=mid;
            else r=mid;
        }
        return INT_MAX;
    }
};