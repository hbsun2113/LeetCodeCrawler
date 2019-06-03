class Solution {
public:
    // https://www.acwing.com/solution/LeetCode/content/384/
    // bitset可以输出数字的二进制表示
    // 直接对num取反是不可以的，因为前导0会变成1。而此题的含义是不反转前导0。
    // 我们要保持前导0: tot的二进制表示中，全部是0，只有num的最高位为1。(tot-1)最高位左面全是0，右面全是1。
    int findComplement(int num) {
        int tot;
        for (int i = num; i; i -= i & -i)
            tot = i & -i;
        cout<<bitset<32>(tot-1)<<endl; // 之前为1的最高位，取补后肯定为0，因此tot-1在这一位为0也没有关系，tot-1的作用是保住右面部分，舍弃左面部分。
        return ~num & (tot - 1);
    }


    int findComplement1(int num) {
        vector<int> vec;
        while(num>0){
            vec.push_back(1-(num&1));
            num=(num>>1);
        }
        long long base=1;
        long long res=0;
        for(int i=0;i<vec.size();i++){
            res+=vec[i]*base;
            base*=2;
        }
        return res;
    }
};

