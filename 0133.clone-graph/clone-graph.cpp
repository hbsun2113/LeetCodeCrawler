/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
//https://www.cnblogs.com/grandyang/p/4267628.html
//这道题目的题意一开始没有弄清楚，其实就是将一个连通图进行深拷贝。原图怎么样，运行完程序返回一个一模一样的图就可以了。
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int,UndirectedGraphNode*> graph;
        return clone(graph,node);
    }
    UndirectedGraphNode * clone(unordered_map<int,UndirectedGraphNode*> &graph,UndirectedGraphNode *node){
        if(!node) return NULL;//null不是关键字 但是NULL是关键字。
        if(graph.count(node->label))
           return graph[node->label];
        UndirectedGraphNode * copy=new UndirectedGraphNode(node->label);
        graph[node->label]=copy;
        for(auto e:node->neighbors){
            copy->neighbors.push_back(clone(graph,e));
        }
        return copy;
        
    }
};