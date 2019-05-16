class Solution {
public:
    int networkDelayTime1(vector<vector<int>>& times, int N, int K) {
        //http://blog.csdn.net/u011809767/article/details/78851678
        //https://www.cnblogs.com/tanky_woo/archive/2011/01/17/1937728.html
        vector<int> distance(N+1,INT_MAX);
        distance[K]=0;
        for(int i=0;i<N;i++){//循环N次
            for(vector<int> e:times){
                int u=e[0],v=e[1],w=e[2];
                if(distance[u]!=INT_MAX && distance[v]>distance[u]+w)
                    distance[v]=distance[u]+w;
            }
        }
        int maxwait=0;
        for(int i=1;i<=N;i++){//从1开始遍历，注意点的序号是从1开始的。
            //cout<<distance[i]<<endl;
            maxwait=max(maxwait,distance[i]);
        }
        return maxwait==INT_MAX?-1:maxwait;
            
    }
    
    
    //由于边的权重没有负数，所以可以用Dijkstra
    //参考了https://discuss.leetcode.com/topic/113782/summary-of-implementation-of-single-source-shortest-paths-in-c 这个人的代码风格很好。
    //注意在graph和priority_queue中pair的区别   graph{dest,weight}  priority_queue{distance,dest_vertex}
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> wait(N,INT_MAX);
        wait[K-1]=0;
        unordered_map<int,unordered_map<int,int>> graph;//{source->{dest->weight}}
        for(auto & e:times){graph[e[0]-1][e[1]-1]=e[2];}
        auto comp=[](pair<int,int>& left,pair<int,int>& right)->bool{return left.first>right.first;};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)> q(comp);
        q.push({0,K-1});
        while(!q.empty()){
            int src=q.top().second;
            q.pop();
            for(auto & e:graph[src]){
                int desc=e.first;
                if(wait[src]+e.second<wait[desc]){
                    wait[desc]=wait[src]+e.second;
                    q.push({wait[desc],desc});
                }   
            }
        }
        int ans=0;
        for(auto & e:wait) ans=max(ans,e);
    
        return ans==INT_MAX?-1:ans;
    }
        
};