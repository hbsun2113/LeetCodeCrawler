class Solution {
public:
    // https://leetcode.com/problems/insert-interval/discuss/21602/Short-and-straight-forward-Java-solution
    // 其实感觉这种解法容易写错，边界问题，但是算是一个新问题吧，这种解法也稍微记着点吧
    
    // 很elegant的写法：https://leetcode.com/problems/insert-interval/discuss/21599/Elegant-C++-STL-solution-using-%22equal_range%22-to-find-overlapped-intervals.
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i=0;
        while(i<intervals.size() && intervals[i][1]<newInterval[0])
            res.push_back(intervals[i++]);
        
        int newstart=newInterval[0];
        int newend=newInterval[1];
        while(i<intervals.size() && intervals[i][0]<=newInterval[1]){
            newstart=min(newstart,intervals[i][0]);
            newend=max(newend,intervals[i++][1]);
        }
        newInterval[0]=newstart;
        newInterval[1]=newend;
        res.push_back(newInterval);
        
        while(i<intervals.size())
            res.push_back(intervals[i++]);
        return res;
    }
    
    
    // 使用了https://leetcode.com/submissions/detail/223283214/ 的解法，不高效，因为要重新排序
    vector<vector<int>> insert1(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
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
};