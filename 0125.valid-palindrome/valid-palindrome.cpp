//这个好像没什么难度，但是我用了很多现成的工具。
class Solution {
public:
    bool isPalindrome(string s) {
        int length=s.size();
        if(length==0) return true;
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        string r;
        for(int i=0;i<length;i++){
            if(((s[i]>='a') && (s[i]<='z')) || ((s[i]>='0') && (s[i]<='9'))){
                r.push_back(s[i]);
            }
        }
        length=r.size();
        for(int i=0;i<=length/2;i++){
            if(r[i]!=r[length-i-1])
                return false;
        }
        return true;
    }
    
    
};