class Solution {
public:
    // ????????????????
    // ?????BFS
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> um; // ?? ????string???????
        vector<vector<string>> res;
        for(const auto w:wordList) um.insert({w,INT_MAX});
        if(um.find(endWord)==um.end()) return res;
        um[beginWord]=0;  
        queue<pair<string,vector<string>>> q;
        q.push({beginWord,{beginWord}});
        while(!q.empty()){
            auto n=q.front();
            q.pop();
            string w=n.first;
            auto v=n.second;
            if(w==endWord){
                res.push_back(v);
                continue;
            }
            for(int i=0;i<w.size();i++){
                string t=w;
                for(char c='a';c<='z';c++){
                    t[i]=c;
                    if(t==w) continue;
                    if(um.find(t)==um.end()) continue;  // ????????
                    if(um[t]<(int)v.size()) continue; // continue??????????????
                    um[t]=(int)v.size();
                    v.push_back(t);
                    q.push({t,v});
                    v.pop_back();
                }
            }
        }
        return res;
    }

    
};