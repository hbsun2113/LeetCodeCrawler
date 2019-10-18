class Solution {
public:
    // ??????max?res?????while??
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.size()==0 || k<=0) return 0;
        unordered_map<int,int> um;
        int i=0;
        int res=0;
        for(int j=0;j<s.size();j++){
            if(++um[s[j]]==1) k--;
            while(k<0){
                if(--um[s[i++]]==0) k++;
            }
            res=max(res,j-i+1);
        }
        return res;
    }
};