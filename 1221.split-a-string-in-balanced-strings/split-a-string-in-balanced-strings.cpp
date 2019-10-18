class Solution {
public:
    int balancedStringSplit(string s) {
        int res=0;
        int l=0,r=0;
        for(const auto &c:s){
            if(c=='L') l++;
            else if(c=='R') r++;
            if(l==r) res++;
        }
        return res;
    }
};