class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return 0;
        
        sort(intervals.begin(),intervals.end());
        int e=intervals[0][1];
        int res=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<e){ 
                res++; // 如果发生了重叠，肯定是要移除一个了，但还没有确定要移除哪一个
                e=min(e,intervals[i][1]); // 尽可能地缩小当前范围，所以要移除尾部大的那个
            }
            else 
                e=intervals[i][1]; // 没有发生重叠，那我们就正常延展尾部
        }
        return res;
        
    }
    // 镜像问题：https://leetcode.com/problems/merge-intervals/description/
};