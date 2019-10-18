class Solution {
public:
    vector<string> res;
    unordered_map<char,char> um;
    unordered_map<char,char> single;
    vector<string> findStrobogrammatic(int n) {
        if(n==1) return {"1","0","8"};
        
        um.insert({'1','1'});
        um.insert({'0','0'});
        um.insert({'8','8'});
        um.insert({'9','6'});
        um.insert({'6','9'});
        
        single.insert({'1','1'});
        single.insert({'0','0'});
        single.insert({'8','8'});
        
        string tmp=string(n,' ');
        dfs(0,n-1,tmp);
        
        return res;
    }
    
    void dfs(int i,int j,string tmp){
        if(i>j){
            res.push_back(tmp);
            return;
        }
        if(i==j){
            for(const auto &n:single){
                if(i==0 && n.first=='0') continue;
                auto w=tmp;
                w[i]=n.first;
                w[j]=n.second;
                dfs(i+1,j-1,w);
            }
            return ;
        }
        for(const auto &n:um){
            if(i==0 && n.first=='0') continue;
            auto w=tmp;
            w[i]=n.first;
            w[j]=n.second;
            dfs(i+1,j-1,w);
        }
    }
};