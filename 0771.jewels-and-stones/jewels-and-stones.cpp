class Solution {
public:
    int numJewelsInStones1(string J, string S) {
        unordered_map<int,char> mm;
        for(const auto& s:S){
            mm[s]+=1;
        }
        int result=0;
        for(const auto& j:J){
            result+=mm[j];
        }
        
        return result;
    }
    
    
    int numJewelsInStones(string J, string S) {
        unordered_set<char> setJ(J.begin(),J.end());
        int result=0;
        for(const auto& s:S){
            if(setJ.count(s))
            result++;
        }
        
        return result;
    }
};