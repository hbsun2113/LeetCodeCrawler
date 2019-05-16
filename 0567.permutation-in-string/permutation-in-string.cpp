class Solution {
public:
    // 虽然自己做出来了，但是如下的解释更好：https://leetcode.com/problems/permutation-in-string/discuss/102644/C++-Java-Clean-Code-with-Explanation
    
/**
 * 1. try find a window (i, j) where s2.substr(i, j + 1 - i) contains all chars in s1;
 * 2. once found, try reduce window(i, j) such that j + 1 - i == s1.size() while the window still contains all chars in s1 by moving i, return true;
 * 3. if windows no longer contain all chars in s1, keep moving j forward;
 */
    
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        unordered_map<char,int> um;
        for(const auto &c:s1) um[c]++;
        int count=s1.size();
        for(int i=0,j=0;j<s2.size();j++){
            if(um[s2[j]]-->=1) count--;
            while(count==0){
                if(j-i+1==s1.size()) return true;
                if(um[s2[i++]]++>=0) count++;
            }
        }
        return false;
    }
};