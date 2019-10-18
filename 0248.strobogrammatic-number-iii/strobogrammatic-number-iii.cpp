class Solution {
public:
    // ?????https://leetcode.com/problems/strobogrammatic-number-ii/
    int strobogrammaticInRange(string low, string high) {
        int lenl=low.size();
        int lenh=high.size();
        this->low=low;
        this->high=high;
        for(int i=lenl;i<=lenh+1;i++){
            findStrobogrammatic(i);
        }
        
        // for(const auto &r:res)
        //     cout<<r<<" ";
        // cout<<endl;
        
        return res.size();
    }
    
    string low,high;
    vector<string> res;
    unordered_map<char,char> um;
    unordered_map<char,char> single;
    vector<string> findStrobogrammatic(int n) {
        if(n==1){
            vector<string> tmp={"1","0","8"};
            for(auto &t:tmp){
                dfs(1,0,t);
            }
            return tmp;
        }
        
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
        auto cmp=[](string &a, string &b){  // ??a???b?
            if(a.size()!=b.size()) return a.size()>b.size();
            for(int i=0;i<a.size();i++){
                if(a[i]!=b[i]) return a[i]>b[i];
            }
            return true;
        };
        
        if(i>j){
            if(cmp(tmp,low) && cmp(high,tmp)) res.push_back(tmp);
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