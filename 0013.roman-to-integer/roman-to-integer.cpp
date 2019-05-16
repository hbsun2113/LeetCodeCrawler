class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
        int result=T[s.back()];//最后一个位肯定是加
        //需要判断其他的数字是加还是减。
        for(int i=0;i<s.size()-1;i++){
            if(T[s[i]]<T[s[i+1]])
                result-=T[s[i]];
            else 
                result+=T[s[i]];
        }
        return result;
    }
};