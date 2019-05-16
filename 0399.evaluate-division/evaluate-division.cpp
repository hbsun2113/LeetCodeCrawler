class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string,unordered_map<string,double>> graph;
        for(int i=0;i<values.size();i++){
            string a=equations[i].first;
            string b=equations[i].second;
            graph[a][b]=values[i];
            graph[b][a]=1.0/values[i];
        }
        vector<double> result(queries.size());
        for(int i=0;i<result.size();i++){
            set<string> now;
            result[i]=dfs(queries[i].first,queries[i].second,1.0,graph,now);
            if(result[i]==0.0) result[i]=-1.0;
        }
        return result;
    }
    
    double dfs(string begin,string end,double value,unordered_map<string,unordered_map<string,double>> & graph,set<string>& now){
        if(now.count(begin)!=0) return 0.0;
        if(graph.count(begin)==0) return 0.0;
        if(begin==end) return value;
        now.insert(begin);
        for(auto e:graph[begin]){
            double parResult=dfs(e.first,end,e.second*value,graph,now);
            if(parResult!=0.0)  return parResult;
        }
        //now.erase(begin);
        return 0.0;
    }
};