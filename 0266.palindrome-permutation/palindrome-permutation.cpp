class Solution {
public:
    // ??????????????
    bool canPermutePalindrome1(string s) {
        unordered_map<char,int> um;
        for(const auto &c:s) um[c]++;
        if(s.size()%2==0){
            for(auto &n:um){
                if(n.second%2==1) return false;
            }
        }
        else{
            bool flag=false;
            for(auto &n:um){
                if(n.second%2==1){
                    if(flag==true) return false;
                    flag=true;
                }
            }
        }
        return true;
    }
    
    // https://leetcode.com/problems/palindrome-permutation/discuss/69582/Java-solution-wSet-one-pass-without-counters.
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> um;
        for(const auto &c:s){
            if(um.find(c)!=um.end()) um.erase(c);
            else um[c]++;
        }
        return um.size()<=1;
    }
};