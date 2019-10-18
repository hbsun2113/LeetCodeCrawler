class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char,int> um;
        int res=0;
        int i=0;
        int cnt=0;
        for(int j=0;j<s.size();j++){
            const auto &c=s[j];
            if(um[c]++==0) cnt++;  
            while(i<j && cnt>2){
                if(um[s[i++]]--==1) cnt--;
            }
            res=max(res,j-i+1);
        }
        return res;
    }
};