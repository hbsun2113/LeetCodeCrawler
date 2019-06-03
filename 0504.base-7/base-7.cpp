class Solution {
public:
    // 这道题目使我清晰了如何 从低位到高位 得到一个数的10进制表示，或者2进制表示：
    // 先% 然后/
    string convertToBase7(int num) {
        if(num==0) return "0"; 
        int sign= (num>=0?1:-1);
        long long n=num;
        n=abs(n);
        int base=7;
        string res="";
        while(n){
            res.push_back('0'+n%7);
            n/=7;
        }
        if(sign==-1) res+='-';
        reverse(res.begin(),res.end());
        return res;
    }
};