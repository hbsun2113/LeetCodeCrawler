// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long l=-1,r=n;
        while(l+1<r){
            long mid=l+(r-l)/2;
            int index=mid+1;
            if(!isBadVersion(index)) l=mid;
            else r=mid;
        }
        return r+1;
    }
};