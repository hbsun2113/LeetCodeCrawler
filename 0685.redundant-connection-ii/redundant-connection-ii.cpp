//参考https://leetcode.com/problems/redundant-connection-ii/discuss/108045
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1,0),candiA,candiB;//parent记录每个节点的父亲节点 candiA和candiB记录的是冗余边，他们俩要是不为空，记录的代表一个节点有两个父亲节点。
        for(auto & e:edges){
            int src=e[0],decs=e[1];
            if(parent[decs]==0)
                parent[decs]=src;
            else{
                candiA={parent[decs],decs};
                candiB=e;
                e[1]=0;//设置为0，就是消除了第二条冗余边（在下面y=findroot(e[1],parent)的时候因为e[1]==0,所以自然将这个边置为了无效），下面就以第一条冗余边为有效边，进行判断是否有环。
            }
        }
        for(int i=1;i<=edges.size();i++) parent[i]=0;//重新进行初始化,因为在做并查集的初始阶段，要将每个节点当作独立节点对待，随着算法的逐步推进，不断合并。
        for(auto & e:edges){
            int x=findroot(e[0],parent),y=findroot(e[1],parent);
            if(x==y){//出现了环路
                if(!candiB.empty())return candiA;//这种情况比较复杂，既出现了多父亲的情况，又出现了环路的情况。说明正是candiA作为有效边时出现了环路，自然将candiA删除就解决了所有问题。
                return e;//candiB为空，说明只是单纯出现了环路，此时只要按照并查集的做法单纯删除最后一条边就好了。
            } 
            else parent[x]=y;
        }
        //以candiA为有效边，没有发现环路，说明只是有一个节点出现了两个父亲的情况，此时只要删除其中一个父亲就好了，由于candiB比candiA出现得晚，所以删除candiB。
        return candiB;    
    }
    
    // int findroot(int x,vector<int> parent){//这个没有路径压缩
    //     while(parent[x]!=0){
    //         x=parent[x];
    //     }
    //     return x;
    // }
    
    int findroot(int x,vector<int> parent){
        if(parent[x]!=0){
            x=(findroot(parent[x],parent));
            parent[x]=x;//路径压缩
        }
        return x;
    }
};