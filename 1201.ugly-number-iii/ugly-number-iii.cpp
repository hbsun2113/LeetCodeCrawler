class Solution {
public:
    // https://leetcode.com/problems/ugly-number-iii/discuss/387539/cpp-Binary-Search-with-picture-and-Binary-Search-Template
    // ?????????????[0,N]????x?????????N/x ??
    int nthUglyNumber(int n, int aa, int bb, int cc) {
        long long a=aa,b=bb,c=cc;
        long long ab=a*b/__gcd(a,b);
        long long ac=a*c/__gcd(a,c);
        long long bc=b*c/__gcd(b,c);
        long long abc=a*bc/__gcd(a,bc);
        long long l=1,r=2*1e9+3;
        while(l<r){
            auto mid=l+r>>1;
            int cnt=mid/a+mid/b+mid/c-mid/ab-mid/ac-mid/bc+mid/abc;
            if(cnt>=n) r=mid; // [l,mid] [mid+1,r]
            else l=mid+1;
        }
        return l;
    }
};