#define dbv(v) cout << #v << "="; for (auto _x : v) cout << _x << ", "; cout << endl
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> res(n,-1);
        // res[0]=0;
        unordered_map<int,set<int>> ori_red_graph;
        unordered_map<int,set<int>> ori_blue_graph;
        queue<int> rq;
        queue<int> bq;
        for(const auto &v:red_edges){
            ori_red_graph[v[0]].insert(v[1]);
            if(v[0]==0){
                res[v[1]]=1;
                rq.push(v[1]);
            } 
        }
            
        for(const auto &v:blue_edges){
            ori_blue_graph[v[0]].insert(v[1]);
            if(v[0]==0){
                res[v[1]]=1;
                bq.push(v[1]);
            } 
        }
        res[0]=0;
        
        auto red_graph=ori_red_graph;
        auto blue_graph=ori_blue_graph;
        queue<int> redq=rq; // ?????????????????
        queue<int> blueq=bq;
        bool flag=true;
        int j=1;
        while(1){
            if(redq.size()==0 && flag==true) break;
            if(blueq.size()==0 && flag==false) break;
            if(flag){
                flag=false;
                while(!redq.empty()){
                    auto t=redq.front();
                    redq.pop();
                    for(const auto &v:blue_graph[t]){
                        if(res[v]==-1 || res[v]>j+1){
                            res[v]=j+1;
                        }
                        blueq.push(v);
                        blue_graph[t].erase(v);
                    }
                }
                j++;
            }
            else{
                flag=true;
                while(!blueq.empty()){
                    auto t=blueq.front();
                    blueq.pop();
                    // cout<<t<<endl;
                    for(const auto &v:red_graph[t]){
                        if(res[v]==-1 || res[v]>j+1){
                            res[v]=j+1;
                        }
                        redq.push(v);
                        red_graph[t].erase(v);
                    }
                }
                j++;
            }
        }
        dbv(res);
        
        
        redq=bq;
        blueq=rq;
        red_graph=ori_red_graph;
        blue_graph=ori_blue_graph;
        flag=true;
        j=1;
        while(1){
            if(redq.size()==0 && flag==true) break;
            if(blueq.size()==0 && flag==false) break;
            if(flag){
                flag=false;
                while(!redq.empty()){
                    auto t=redq.front();
                    redq.pop();
                    // cout<<t<<" "<<flag<<endl;
                    for(const auto &v:red_graph[t]){
                        if(res[v]==-1 || res[v]>j+1){
                            res[v]=j+1;
                        }
                        blueq.push(v);
                        red_graph[t].erase(v);
                    }
                }
                j++;
            }
            else{
                flag=true;
                while(!blueq.empty()){
                    auto t=blueq.front();
                    blueq.pop();
                    // cout<<t<<" "<<flag<<endl;
                    for(const auto &v:blue_graph[t]){
                        if(res[v]==-1 || res[v]>j+1){
                            res[v]=j+1;
                        }
                        redq.push(v);
                        blue_graph[t].erase(v);
                    }
                }
                j++;
            }
        }
        
        return res;
    }
};