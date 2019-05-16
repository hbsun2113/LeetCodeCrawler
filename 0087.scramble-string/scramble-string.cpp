class Solution {
public:
    // 三更，做得不好
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        if(s1==s2) return true;
        unordered_map<char,int> um;
        for(const auto &c:s1) um[c]++;
        for(const auto &c:s2) um[c]--;
        for(const auto &c:um){
            if(c.second!=0) return false;
        }
        int len=s1.size();
        for(int i=1;i<len;i++){ // 至少一个字符,因此子串的长度是[1,len-1]。
            // 1.要么是头对头、尾对尾。 2.要么是头对尾、尾对头。
            if(isScramble(s1.substr(0,i),s2.substr(len-i)) && isScramble(s1.substr(i),s2.substr(0,len-i))) return true;
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i))) return true;
            //if(isScramble(s1.substr(),s2.substr()) && isScramble(s1.substr(),s2.substr())) return true;
        }
        return false;
    }
    
    
    //二更，自己没有做出来，是看答案做的
    bool isScramble2(string s1, string s2) {
        if(s1==s2) return true;
        if(s1.size()!=s2.size()) return false;
        vector<int> count(26);
        int len=s1.size();
        for(int i=0;i<len;i++){
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        for(int i=0;i<count.size();i++){
            if(count[i]!=0) return false;
        }
        for(int i=1;i<len;i++){
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i))) return true;
            if(isScramble(s1.substr(0,i),s2.substr(len-i))   && isScramble(s1.substr(i),s2.substr(0,len-i))) return true;
        }
        return false;
    }
    
    
    
    
    //前半部分是自己做的 后面的递归是参考discuss第一做的。感觉这个解法没有什么理论证明，只能说是一种节省时间的“遍历”方法吧。
    bool isScramble1(string s1, string s2) {
        if(s1==s2) return true;//这行非加不可，因为后面的递归其实无法应对这种情况。
        if(s1.size()!=s2.size()) return false;
        if(s1.size()==0) return true;
        unordered_map<int,int> result1;
        unordered_map<int,int> result2;
        for(auto c:s1){
            result1[c-'a']+=1;
        }
        for(auto c:s2){
            result2[c-'a']+=1;
        }
        
        for(auto r:result1){
            if(result1[r.first]!=result2[r.first]){
                // cout<<r.first<<" "<<r.second<<endl;
                return false;
            }
                
        }
        for(auto r:result2){
            if(result1[r.first]!=result2[r.first]){
                // cout<<r.first<<" "<<r.second<<endl;
                return false;
            }
                
        }
        for(int i=1;i<s1.size();i++){//i必须从1开始，要是从零开始就会陷入死循环。
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)))
                return true;
            if(isScramble(s1.substr(0,i),s2.substr(s1.size()-i)) && isScramble(s1.substr(i),s2.substr(0,s1.size()-i)))
                return true;
        }
        return false;
    }
};