class Solution {
public:
    //我的解法很朴素 倒是提醒了自己要看看KMP算法 下回再做这道题的时候 还是先复习一下KMP吧
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        for(int i=0;i<haystack.size();i++){
            string part=haystack.substr(i);
            if(find(part,needle)) return i;
        }
        return -1;
    }
    
    bool find(string haystack, string needle){
        int len=needle.size();
        for(int i=0;i<len;i++){
            if(haystack[i]!=needle[i]) return false;
        }
        return true;
    }
};