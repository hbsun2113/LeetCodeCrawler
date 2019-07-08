class Solution {
public:
    // 一开始我想的是建立一个图，图的节点是站点，然后进行BFS搜索，但是这样会TLE。(https://leetcode.com/submissions/detail/241081541/)
    // 后来参照discuss(https://leetcode.com/problems/bus-routes/discuss/122712/Simple-Java-Solution-using-BFS)，发现根本没有必要建图，只要建立"站点到路线的映射"，就可以直接BFS搜索，AC了。
    // 说白了routeid就是一个中间人，看看每个站点通过它都可以到达哪些其他站点
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S==T) return 0;
        unordered_map<int,vector<int>> um; // stopid->set(routeid) 站点到路线的映射
        for(int i=0;i<routes.size();i++)
            for(const auto &j:routes[i]) 
                um[j].push_back(i);
        
        vector<bool> vis(routes.size(),false); // 如果之前访问过，那肯定比当前更优，这是BFS的特点。注意标记的是哪些route访问过了，这比标记stopid要快
        queue<int> q;
        q.push(S);
        int res=1;
        while(!q.empty()){
            for(int i=(int)q.size();i>=1;i--){
                auto routeset=um[q.front()];
                q.pop();
                for(auto &routeid:routeset){
                    if(vis[routeid]) continue;
                    vis[routeid]=true;
                    for(auto &j:routes[routeid]){
                        if(j==T) return res;
                        q.push(j);
                    }
                    // routes[routeid].clear(); // 这行提速明显：
                }
            }
            res++;
        }
        
        
        return -1;
    }
};