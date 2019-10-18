class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res=0;
        unordered_map<char,int> um;
        for(const auto &c:chars) um[c]++;
        for(const auto &s:words){
            auto t=um;
            bool flag=true;
            for(const auto &c:s){
                if(t[c]==0){
                    flag=false;
                    break;
                }
                else t[c]--;
            }
            // cout<<s<<endl;
            if(flag) res+=s.size();
        }
        return res;
    }
};