class Solution {
public:
    string reverseString1(string s) {
        string result("");
        for(int i=s.size()-1;i>=0;i--)
            result+=s[i];
        return result;
    }
    
    
    string reverseString(string s) {
        int l=0,r=s.size()-1;
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
        return s;
    }
};