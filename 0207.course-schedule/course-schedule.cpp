class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> pre(numCourses,0);
        vector<vector<int>> nei(numCourses,vector<int>());
        
        for(const auto &v:prerequisites){
            pre[v[0]]++;
            nei[v[1]].push_back(v[0]);
        }
        
        queue<int> q;
        for(int i=0;i<pre.size();i++){
            if(pre[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            
            for(const auto &n:nei[t]){
                pre[n]--;
                if(pre[n]==0) q.push(n);
            }
        }
        
        for(int i=0;i<pre.size();i++)
            if(pre[i]!=0) return false;
        return true;
    }
};