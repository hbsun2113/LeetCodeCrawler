#define dbv(v) cout << #v << "="; for (auto _x : v) cout << _x << ", "; cout << endl
class Solution {
public:
    // ??Weekly Contest 156  ????????????????????????????????????????0?
    // ??????????
    unordered_map<string,int> vis;
    int row,col;
    int minimumMoves(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        queue<vector<int>> q;
        q.push({0,0,0,1,0});
        vis[helper(q.front())]=0;
        string target=to_string(row-1)+to_string(col-2)+to_string(row-1)+to_string(col-1);
        while(!q.empty()){
            auto v=q.front();
            q.pop();
            auto a=v[0],b=v[1],c=v[2],d=v[3],e=v[4];
            if(a==c && b==d-1){  // ??
                if(d+1<col && grid[c][d+1]==0){ // ??
                    auto w=v;
                    w[1]++;
                    w[3]++;
                    w[4]++;
                    string flag=helper(w);
                    if(flag==target) return w[4];
                    if(vis.find(flag)==vis.end() || vis[flag]>w[4]){
                        vis[flag]=w[4];
                    q.push(w);
                    }
                    
                }
                if(c+1<row && d-1>=0 && grid[c+1][d-1]==0  && a+1<row && b+1<col && grid[a+1][b+1]==0){ // ??
                    auto w=v;
                    w[2]++;
                    w[3]--;
                    w[4]++;
                    string flag=helper(w);
                    if(flag==target) return w[4];
                    if(vis.find(flag)==vis.end()){
                        vis[flag]=w[4];
                    q.push(w);
                    }
                    
                }
                if(a+1<row && grid[a+1][b]==0 && grid[c+1][d]==0){ // ????
                    auto w=v;
                    w[0]++;
                    w[2]++;
                    w[4]++;
                    string flag=helper(w);
                    if(flag==target) return w[4];
                    if(vis.find(flag)==vis.end() || vis[flag]>w[4]){
                        vis[flag]=w[4];
                        q.push(w);
                    }
                    
                }
            }
            else if(a==c-1 && b==d){   // ??
                if(c+1<row && grid[c+1][d]==0){ // ??
                    auto w=v;
                    w[0]++;
                    w[2]++;
                    w[4]++;
                    string flag=helper(w);
                    if(flag==target) return w[4];
                    if(vis.find(flag)==vis.end() || vis[flag]>w[4]){
                        vis[flag]=w[4];
                        q.push(w);
                    }
                    
                }
                if(c-1>=0 && d+1<col && grid[c-1][d+1]==0  && a+1<row && b+1<col && grid[a+1][b+1]==0){ // ??
                    auto w=v;
                    w[2]--;
                    w[3]++;
                    w[4]++;
                    string flag=helper(w);
                    if(flag==target) return w[4];
                    if(vis.find(flag)==vis.end()  || vis[flag]>w[4]){
                        vis[flag]=w[4];
                        q.push(w);
                    }
                    
                }
                if(b+1<col && grid[a][b+1]==0 && grid[c][d+1]==0){ // ????
                    auto w=v;
                    w[1]++;
                    w[3]++;
                    w[4]++;
                    string flag=helper(w);
                    if(flag==target) return w[4];
                    if(vis.find(flag)==vis.end()  || vis[flag]>w[4]){
                        vis[flag]=w[4];
                    q.push(w);
                    }
                }
            }
        }
        return -1;
        
    }
    
    string helper(vector<int>& vec){
        string res="";
        for(int i=0;i<4;i++)
            res+=to_string(vec[i]);
        return res;
    }
};