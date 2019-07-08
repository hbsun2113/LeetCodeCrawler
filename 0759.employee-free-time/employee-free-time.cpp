/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
public:
    
    // 这个染色法不可行，只能过小数据。 因为10^8太耗内存：https://leetcode.com/submissions/detail/240227321/
    // 这道题目二维vector和一维vector是一样的，没有任何区别
    // https://www.cnblogs.com/grandyang/p/8552586.html
    vector<Interval*> employeeFreeTime(vector<vector<Interval*>>& schedule) {
        vector<Interval*> vec;
        for(const auto &s:schedule)
            for(const auto &v:s)
                vec.push_back(v);
        
        auto cmp=[](Interval* a, Interval* b){return a->start<b->start;};
        sort(vec.begin(),vec.end(),cmp);
        
        vector<Interval*> res;
        if(vec.size()==0) return res;
        
        int start=vec[0]->start;
        int end=vec[0]->end;
        for(int i=1;i<vec.size();i++){
            if(vec[i]->start>end){
                res.push_back(new Interval(end, vec[i]->start));
                start=vec[i]->start;
                end=vec[i]->end;
            } 
            else end=max(end,vec[i]->end);
        }
        // 和56. Merge Intervals不同，不需要处理尾元素，因为是求差集
        
        
        return res;
    }
    
    
    // https://www.cnblogs.com/grandyang/p/8552586.html
    vector<Interval*> employeeFreeTime1(vector<vector<Interval*>>& schedule) {
        map<int,int> um;
        for(const auto &s:schedule)
            for(const auto &v:s){
                um[v->start]++;
                um[v->end]--;
            }
        
        vector<Interval*> res;
        int cnt=0;
        for(const auto &u:um){
            cnt+=u.second;
            // cout<<u.first<<" "<<u.second<<" "<<cnt<<endl; 看一下这行就知道为什么要res.back()->end==INT_MIN
            if(!cnt) res.emplace_back(new Interval(u.first, INT_MIN));
            if(cnt>0 && !res.empty() && res.back()->end==INT_MIN) res.back()->end=u.first;
        }
        res.pop_back();
        return res;
    }
};