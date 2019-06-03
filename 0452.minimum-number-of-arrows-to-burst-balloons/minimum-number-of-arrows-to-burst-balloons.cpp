class Solution {
public:
    // 二刷
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        auto cmp=[](vector<int> &a, vector<int> &b){
            return a[1]<b[1];
        };
        sort(points.begin(),points.end(),cmp);
        int res=1;
        int c=points[0][1];
        for(int i=1;i<points.size();i++){
            if(c<points[i][0]){
                res++;
                c=points[i][1];
            }
        }
        return res;
    }
    
    
    // https://www.acwing.com/solution/LeetCode/content/352/
    // 所需要飞镖的个数就是交集的个数
    
    // 这个更好理解：http://www.cnblogs.com/grandyang/p/6050562.html
    
    // 贪心策略。既然每个空间都要照顾到，那就挨个遍历并且贪心吧。每个新区间都尽量和前面的区间共用一个飞镖。
    int findMinArrowShots1(vector<pair<int, int>>& points) {
        int res=1;
        if(points.size()==0) return 0;
        sort(points.begin(),points.end());
        int start=points[0].first;  // 当前飞镖可置的起点
        int end=points[0].second;   // 当前飞镖可置的终点
        for(int i=1;i<points.size();i++){
            if(end<points[i].first){
                res++;
                start=points[i].first;
                end=points[i].second;
            }
            else{
                start=max(start,points[i].first);
                end=min(end,points[i].second);
            }
        }
        return res;
    }
};