class Solution {
public:
    const int mod=1e9+7;
    // https://leetcode.com/problems/sum-of-subsequence-widths/discuss/161267/C++Java1-line-Python-Sort-and-One-Pass
    // 先排序
    // 每个数组贡献的力量是: 右边界-左边界
    // 选取A[i],则以A[i]为右边界的数组有2^(i)个,则A[i]贡献的力量为 +A[i]*(2^(i))
    // 以A[i]为左边界的数组有2^(n-i-1)个,则A[i]贡献的力量为 -A[i]*(2^(n-i-1))
    // A[n - i - 1] * 2 ^ i 等价于 A[i] * 2 ^ (n - i - 1)
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(),A.end());
        int n=A.size();
        int res=0;
        long long base=1;
        for(int i=0;i<n;i++){
            // 方式1：
            res+=(A[i]*base)%mod;
            res%=mod;
            
            res-=(A[n - i - 1]*base)%mod;
            res%=mod;
            
            // 方式2：
            // res=(res+A[i]*base-A[n - i - 1]*base)%mod;
            
            base*=2;
            base%=mod;
        }
        
        // 错误，可能返回负数：
        // return res; 
        
        // 正确，保证了一定是正数：
        // Q. why do we plus mod before return?
        // A: in Cpp and Java, mod on negative number will still get a negative number.
        return (res + mod) % mod; // 这个trick要记住
    }
};