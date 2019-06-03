class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
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
            res.push_back(n);
            auto des=um[n];
            for(const auto &d:des){
                if(--in_degree[d]==0)
                    q.push(d);
            }
        }
        
        for(int i=0;i<in_degree.size();i++){
            if(in_degree[i]!=0) return vector<int>();
        }
        
        return res;
    }
};