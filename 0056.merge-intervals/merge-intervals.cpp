class Solution {
public:
    // 不可以使用染色法，因为我们染色只能针对节点进行染色，但这道题目要处理的是interval，下面就是典型的不适用场景：
    /*
Input:
[[1,4],[5,6]]
Output:
[[1,6]]
Expected:
[[1,4],[5,6]]
   */
    
    // 然后自己重新做了一下
    // 先排序，其实只要去看前一个interval的尾是否比后一个interval的头大就可以了，如果是那他俩可以合并；否则前一个的处理就完成了。
    vector<vector<int>> res;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return res;
        sort(intervals.begin(),intervals.end());
        int s=intervals[0][0],e=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(e<intervals[i][0]){
                res.push_back({s,e}); // 注意这里不可以使用emplace_back((s,e)) ，因为这样会调用vector的构造函数(大小，初始值)
                s=intervals[i][0];
                e=intervals[i][1];
            }
            else
                e=max(e,intervals[i][1]);
        }
        res.push_back({s,e});
        return res;
    }
    // 镜像问题：https://leetcode.com/problems/non-overlapping-intervals/description/
};