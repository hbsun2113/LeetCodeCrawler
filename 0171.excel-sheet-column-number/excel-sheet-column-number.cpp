class Solution {
public:
//这道题目其实很简单，但是我做了比较久的时间。其实看成是进制转换的问题就好了。    
    int titleToNumber(string s) {
        int result=0;
        int base=1;
        for(int i=s.size()-1;i>=0;i--){
            char c=s[i];
            int tmp=c-'A'+1;
            result+=(tmp*base);
            base*=26;
        }
        return result;
    }
};