/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> result;
        if(intervals.size()==1){
            result.push_back(-1);
            return result;
        }
        map<int,int> um; //亮点在于这个um的设计
        for(int i=0;i<intervals.size();i++) um[intervals[i].start]=i;
        for(int i=0;i<intervals.size();i++){
            auto it=um.lower_bound(intervals[i].end);
            if(it==um.end()) result.emplace_back(-1);
            else result.emplace_back(it->second);
        }
        return result;
    }
};