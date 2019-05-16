class Solution {
public:
    // https://www.acwing.com/solution/LeetCode/content/352/
    // 所需要飞镖的个数就是交集的个数
    
    // 这个更好理解：http://www.cnblogs.com/grandyang/p/6050562.html
    
    // 贪心策略。既然每个空间都要照顾到，那就挨个遍历并且贪心吧。每个新区间都尽量和前面的区间共用一个飞镖。
    int findMinArrowShots(vector<pair<int, int>>& points) {
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