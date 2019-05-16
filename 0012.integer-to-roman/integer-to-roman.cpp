class Solution {
public:
    //这道题目不是自己写的 感觉没必要 因为主要是了解规则 下次有时间再自己做一下吧 不过这个解法还挺巧妙的
    string intToRoman(int num) {
        vector<string> M = { "", "M", "MM", "MMM" };
        vector<string> C = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
        vector<string> X = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
        vector<string> I = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
        return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
    }
};