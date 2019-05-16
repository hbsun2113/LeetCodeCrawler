class Solution {
public:
    // 自己做出来了
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int i=0,j=0;
        unordered_map<char,int> um;
        int res=1;
        while(j<s.size()){
            um[s[j]]++;
            while(um[s[j]]>1){
                um[s[i++]]--;
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
    
    // 模板题：双指针+map
    // https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
    int lengthOfLongestSubstring3(string s) {
        if(s.size()==0) return 0;
        unordered_map<char,int> um;
        int i=0;
        int res=1;
        for(int j=0;j<s.size();j++){
            um[s[j]]++;
            while(um[s[j]]>1){
                um[s[i++]]--;
            }
            res=max(res,j-i+1);
        }
        return res;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // 二刷，自己做出来了，还是map靠谱啊
    int lengthOfLongestSubstring2(string s) {
        if(s.size()==0) return 0;
        unordered_map<char,int> um;
        int res=1;
        for(int i=0,j=0;j<s.size();j++){
            um[s[j]]++;
            while(um[s[j]]>1 && i<j){ // 以j为尾部，能拿到的最长不重复字串长度
                um[s[i]]--;
                i++;
            } 
            res=max(res,j-i+1);
            
        }
        return res;
    }
    
    
    
 
    
    //https://www.acwing.com/solution/LeetCode/content/49/ 
    //思路巧妙，字符串的问题以后要多想想双指针。
    // 这个for循环的结构也可以学习一下！
    unordered_map<char,int> um;
    int lengthOfLongestSubstring1(string s) {
        if(s.size()==0) return 0;
        int res=INT_MIN;
        for(int i=0,j=0;j<s.size();j++){
            char &c=s[j];
            um[c]+=1;
            while(um[c]>=2 && i<j){
                um[s[i++]]--;
            }
            res=max(res,j-i+1);
        }
        return res;
    }
};