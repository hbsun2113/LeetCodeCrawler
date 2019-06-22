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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size()==0) return 0;
        vector<int> vec(999999);
        int res=1;
        for(const auto &inv:intervals){
            int start=inv.start;
            int end=inv.end;
            for(int i=start;i<end;i++){
                vec[i]++;
                res=max(res,vec[i]);
            }
            
        }
        return res;
    }
};