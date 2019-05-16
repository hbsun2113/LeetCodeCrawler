class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> dict({".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."});
        int result=0;
        unordered_set<string> us;
        for(const auto &s:words){
            string tmp("");
            for(const auto &c:s){
                tmp+=dict[c-'a'];
            }
            us.emplace(tmp);
        }
        return us.size();
    }
};