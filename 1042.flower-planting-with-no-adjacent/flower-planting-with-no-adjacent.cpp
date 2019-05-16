class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> res(N+1);
        vector<vector<int>> nei(N+1,vector<int>());
        vector<int> color={1,2,3,4};
        for(const auto &p:paths){
            nei[p[0]].push_back(p[1]);
            nei[p[1]].push_back(p[0]);
        }
        dfs(N,paths,nei,1,color,res);
        vector<int> tmp;
        for(int i=1;i<res.size();i++) tmp.push_back(res[i]);
        return tmp;
    }
    
    bool dfs(int N, vector<vector<int>>& paths, vector<vector<int>> &nei, int i, vector<int> &color,vector<int> &res){
        // cout<<i<<endl;
        if(i>N) return true;
        for(int c=0;c<color.size();c++){
            res[i]=color[c];
            if(!judge(i,nei,res)) continue;
            if(dfs(N,paths,nei,i+1,color,res)) return true;
        }
        res[i]=0;
        return false;
    }
    
    
    bool judge(int i, vector<vector<int>> &nei, vector<int> &res){
        int color=res[i];
        for(const auto &n:nei[i]){
            if(color==res[n]) return false;
        }
        return true;
    }
};