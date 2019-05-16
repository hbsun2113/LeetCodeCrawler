class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> um={'a','e','i','o','u','A','E','I','O','U'};
        vector<char> vec;
        vector<int> pos;
        for(int i=0;i<s.size();i++){
            if(um.find(s[i])!=um.end()){
                vec.push_back(s[i]);
                pos.push_back(i);
            }
        }
        reverse(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            s[pos[i]]=vec[i];
        }
        return s;
    }
};