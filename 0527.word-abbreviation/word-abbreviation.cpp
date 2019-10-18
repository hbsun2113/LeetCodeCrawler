class Solution {
public:
    // https://www.cnblogs.com/grandyang/p/6818742.html
    vector<string> res;
    vector<int> pre;
    vector<string> dict;
    vector<string> wordsAbbreviation(vector<string>& d) {
        dict=d;
        int n=dict.size();
        pre.assign(n,1);
        for(int i=0;i<n;i++)
            res.push_back(w2a(dict[i],pre[i]));
        for(int i=0;i<n;i++){
            while(true){
                set<int> s;
                for(int j=i+1;j<n;j++){
                    if(res[i]==res[j]) 
                        s.insert(j);
                }
                if(s.empty()) break;
                s.insert(i);
                for(const auto &k:s){
                    res[k]=w2a(dict[k],++pre[k]);
                }
            }
        }
        return res;
    }
    
    
    string w2a(string s, int k){ // ?????k????????
        // if(k+2>=s.size()) return s; // ????????+??(?????????)+??????
        if(s.size()-k-1<=1) return s; // ????????????????????????1???????????
        return s.substr(0,k)+to_string(s.size()-k-1)+s.back();
    }
};