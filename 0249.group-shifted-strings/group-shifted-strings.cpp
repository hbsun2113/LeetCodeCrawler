class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>> um;
        for(auto s:strings){
            string tmp="";
            for(int i=1;i<s.size();i++){
                int dis=s[i]-s[i-1];
                if(dis<0) dis+=26;
                tmp+=to_string(dis);
            }
            um[tmp].push_back(s);
        }
    
        vector<vector<string>> res;
        for(auto n:um) res.push_back(n.second);
        return res;
    }
};