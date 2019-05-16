class Solution {
public: 
    // 二刷，一勺过，现在感觉比一刷清晰点
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> um;
        vector<int> in_degree(numCourses);
        for(const auto e:prerequisites){
            int des=e[0],src=e[1];
            um[src].push_back(des);
            in_degree[des]++;
        }
        
        queue<int> q;
        for(int i=0;i<in_degree.size();i++){
            if(in_degree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            auto n=q.front();
            q.pop();
            auto des=um[n];
            for(const auto &d:des){
                if(--in_degree[d]==0)
                    q.push(d);
            }
        }
        
        for(int i=0;i<in_degree.size();i++){
            if(in_degree[i]!=0) return false;
        }
        
        return true;
    }
    
    // https://www.acwing.com/solution/LeetCode/content/266/
    // 经典拓扑排序判断是否有环，这个题目一定要会!
    bool canFinish1(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> vec(numCourses,vector<int>());
        vector<int> in_degree(numCourses,0);
        vector<int> visit(numCourses,false);
        for(const auto n:prerequisites){
            vec[n.second].emplace_back(n.first);
            in_degree[n.first]++;
        }
        
        queue<int> q;
        for(int i=0;i<in_degree.size();i++){
            if(in_degree[i]==0) 
                q.emplace(i);
        }
        
        while(!q.empty()){
            auto n=q.front();
            q.pop();
            visit[n]=true;
            for(int i=0;i<vec[n].size();i++){
                if(--in_degree[vec[n][i]]==0)
                    q.emplace(vec[n][i]);
            }
        }
        
        for(int i=0;i<numCourses;i++){ // 环的visit为false,因为环中的节点没有办法进入队列中，所有点的入度都不会为0。
            if(visit[i]==false) return false;
        }
        return true;
    }
};