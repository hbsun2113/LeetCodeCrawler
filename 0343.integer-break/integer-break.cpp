class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return 1 * (n - 1);
        int res = 1;
        if(n%3 == 1) res = 4, n -= 4;
        else if (n % 3 == 2) res = 2, n -= 2;
        // 此时的n一定可以被3整除了
        cout<<n<<endl;
        while (n) res *= 3, n -= 3;
        return res;
    }
};