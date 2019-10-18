#define dbv(v) cout << #v << "="; for (auto _x : v) cout << _x << ", "; cout << endl
class Solution {
public:
    // https://www.cnblogs.com/grandyang/p/5184698.html
    bool isOneEditDistance(string s, string t) {
        int lens=s.size();
        int lent=t.size();
        if(lens>lent) return isOneEditDistance(t,s);
        int diff=lent-lens;
        if(diff>=2) return false;
        if(diff==0){
            int cnt=0;
            for(int i=0;i<s.size();i++) cnt+=(s[i]!=t[i]);
            return cnt==1;
        }
        else if(diff==1){
            for(int i=0;i<s.size();i++){
                if(s[i]!=t[i]) return s.substr(i)==t.substr(i+1);
            }
            return true; // ?????:??s?t???
        }
        assert(false);
        return false;
    }
    
    
};