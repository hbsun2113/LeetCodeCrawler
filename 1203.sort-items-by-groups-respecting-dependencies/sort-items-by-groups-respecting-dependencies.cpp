class Solution {
public:
    // contest-155???????????????????????????AC?????????????????????
    // ???????
    // 1. ?????
    // 2. ????????????????????????groupinsort
    // 2. ???????????????????????????????? ???????groupinsort????????
    unordered_map<int,set<int>> um;
    unordered_map<int,set<int>>  out,in;
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<int> res;
        
        set<int> tmp;
        for(int i=0;i<n;i++){
            if(group[i]==-1) tmp.insert(i);
            else um[group[i]].insert(i);
        }
        
        
        for(int i=0;i<n;i++){
            for(auto j:beforeItems[i]){  // j->i
                out[j].insert(i);
                in[i].insert(j);
            } 
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<i<<": ";
        //     for(auto j:in[i])
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        // cout<<"___________________"<<endl;
        
        unordered_map<int,vector<int>> groupinsort;
        for(int i=0;i<m;i++){
            vector<int> tmp;
            
            unordered_set<int> vis;
            for(auto j:um[i]) vis.insert(j);
            
            queue<int> q;
            for(auto j:um[i]){
                bool flag=true;
                for(auto from:in[j]){
                    if(vis.find(from)!=vis.end()){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    q.push(j);
                } 
            }
            
            while(!q.empty()){
                auto n=q.front();
                q.pop();
                tmp.push_back(n);
                for(auto j:out[n]){
                    if(vis.find(j)!=vis.end()){
                        in[j].erase(n);
                        bool flag=true;
                        for(auto from:in[j]){
                            if(vis.find(from)!=vis.end()){
                                flag=false;
                                break;
                            }
                        }
                        if(flag){
                            q.push(j);
                        }                        
                    }
                }
            }
            
            groupinsort[i]=tmp;
            // cout<<i<<":";
            // for(auto j:groupinsort[i])
            //     cout<<j<<" ";
            // cout<<endl;
            // cout<<"___________________"<<endl;
        }
        
        
        
        
        unordered_set<int> tt;
        queue<int> q;
        unordered_set<int> finishedgroup;
        for(auto &y:tmp){
            if(in[y].size()==0){
                q.push(y);
                tt.insert(y);
            } 
        }
        for(auto &y:tt){
            tmp.erase(y);
        }
        
        for(int i=0;i<m;i++){
            if(degree(i)){
                for(auto &y:groupinsort[i]) 
                    q.push(y);
                um.erase(i);
                finishedgroup.insert(i);
            }
        }
        
        while(!q.empty()){
            auto v=q.front();
            q.pop();
            // cout<<v<<endl;
            res.push_back(v);
            um.erase(group[v]);
            groupinsort.erase(group[v]);
            tmp.erase(v);
            
            for(auto x:out[v]){
                // out[v].erase(x);
                in[x].erase(v);
            }
            
            for(auto g:um){
                int i=g.first;
                if(finishedgroup.find(i)==finishedgroup.end() && degree(i)){
                    for(auto &y:groupinsort[i]){
                        // cout<<i<<":"<<y<<endl;
                        q.push(y);
                    }
                    finishedgroup.insert(i);
                }
            }
            
            unordered_set<int> tt;
            for(auto &y:tmp){
                if(in[y].size()==0){
                    tt.insert(y);
                    q.push(y);
                }
            }
            for(auto &y:tt){
                tmp.erase(y);
            }
            
            
        }
        
        // cout<<res.size()<<" "<<n<<endl;
        // for(auto j:res)
        //     cout<<j<<" ";
        // cout<<endl;
        if(res.size()!=n) return {};
        else return res;
        
        
    }
    
    int degree(int key){
        if(um.find(key)==um.end()) return false;
        bool flag=true;
        for(const auto x:um[key]){
            if(in[x].size()!=0) return false;
        }
        return true;
    }
};