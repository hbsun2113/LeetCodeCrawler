class Solution {
public:
    vector<vector<string>> res;
    vector<string> vec;
    vector<vector<string>> partition(string s) {
        dfs(s);
        return res;
    }
    
    void dfs(string s){
        if(s.empty()){
            res.push_back(vec);
            return ;
        }
        for(int i=1;i<=s.size();i++){
            string first=s.substr(0,i);
            string second=s.substr(i);
            if(isp(first)){
                // cout<<first<<endl;
                vec.push_back(first);
                dfs(second);
                vec.pop_back();
            }
        }
    }
    
    bool isp(string s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
};