class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> us;
        vector<string> res;
        for(int i=0;i+10<=s.size();i++){
            string tmp=s.substr(i,10);
            if(us[tmp]==1)
                res.push_back(tmp);
            us[tmp]+=1;
        }
        return res;
    }
};