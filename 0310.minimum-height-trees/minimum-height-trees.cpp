//这道题目理解得不好，需要重新做
//http://www.cnblogs.com/grandyang/p/5000291.html
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(n,vector<int>(0));
        vector<int> result;
        vector<int> degree(n,0);
        queue<int> q;
        if(n==1) return {0};
        for(auto & e:edges){
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
            degree[e.first]+=1;
            degree[e.second]+=1;
        }
        for(int i=0;i<n;i++){
            if(degree[i]==1)
                q.push(i);
                
        }
        int count=n;
        while(count>2){
            count-=q.size();
            int size=q.size();
            for(int i=0;i<size;i++){
                int v=q.front();
                q.pop();
                for(auto e:graph[v]){
                   degree[e]-=1;
                   if(degree[e]==1){
                       q.push(e);
                   } 
                }
            }
        }
        while(!q.empty()){
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};