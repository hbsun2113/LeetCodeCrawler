class Solution {
public:
    vector<bool> vis;
    unordered_set<string> us;
    int n;
    int numTilePossibilities(string tiles) {
        n=tiles.size();
        if(n==0) return 0;
        vis.clear();
        vis.resize(n,false);
        dfs(tiles,"");
        // for(const auto &c:us) cout<<c<<" ";
        return us.size();
    }
    
    void dfs(string &tiles, string cur){
        if(!cur.empty()) us.emplace(cur);
        if(cur.size()==n){
            return ;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=true;
                dfs(tiles, cur+tiles[i]);
                vis[i]=false;
            }
        }
    }
    
    
};