class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        if(s==t) return s.size();
        int res=0;
        int i=0;
        for(int j=0;j<s.size();j++){
            maxCost-=abs(s[j]-t[j]);
            while(maxCost<0){
                maxCost+=abs(s[i]-t[i]);
                i++;
            }
            res=max(res,j-i+1);
        }
        return res;
    }
};