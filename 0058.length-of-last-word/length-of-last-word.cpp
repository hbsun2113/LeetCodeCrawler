class Solution {
public:
    int lengthOfLastWord(string s) {
        int res=0;
        int i=s.size()-1;
        while(i>=0 && s[i]==' ')
            i--;
        while(i>=0 && s[i--]!=' ')
            res++;
        return res;
    }
    
    
    //这道题目都用STL，感觉自己有点无耻了，下回用朴素的方法再做一遍吧。
    int lengthOfLastWord1(string s) {
        s.erase(s.find_last_not_of(" ") + 1);//实现trim功能，去除尾部的空格。
        int pos=s.find_last_of(" ");
        return s.size()-1-pos;
    }
};