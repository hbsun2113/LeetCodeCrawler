class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //并查集求解
        vector<int> parent(edges.size()+1,-1);//注意点的序号是从1开始的
        for(auto & e:edges){
            int x=findroot(e[0],parent),y=findroot(e[1],parent);
            if(x==y) return e;
            else
                parent[x]=y;  //不在同一个集合中，就是要进行合并。  
        }
    }
    int findroot(int x,vector<int>& parent){
        while(parent[x]!=-1){
            x=parent[x];
        }
        return x;//parent[x]==-1 说明x自己就已经是根结点了，所以直接返回这个集合中的根结点，用来代表这个集合。
        
    }
};