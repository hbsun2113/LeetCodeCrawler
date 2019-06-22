class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream ins(text);
        vector<string> vec;
        string t;
        while(ins>>t){
            vec.push_back(t);
        }
        vector<string> res;
        for(int i=0;i+2<vec.size();i++){
            if(vec[i]==first && vec[i+1]==second) res.push_back(vec[i+2]);
        }
        return res;
    }
};