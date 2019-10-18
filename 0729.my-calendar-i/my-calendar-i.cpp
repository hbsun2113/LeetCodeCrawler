class MyCalendar {
public:
    // https://leetcode.com/problems/my-calendar-i/discuss/109475/JavaC++-Clean-Code-with-Explanation
    MyCalendar() {
        
    }
    // ??????
    bool book(int start, int end) {
        for(const auto v:vec){
            if(max(start,v.first)<min(end,v.second)) return false;
        }
        vec.push_back({start,end});
        return true;
    }
    vector<pair<int,int>> vec;
    
    // ????????????start?????????????????start???[start,end]??
    bool book1(int start, int end) {
        auto it=m.lower_bound(start);
        if(it!=m.end() && it->first<end) return false; // ????start???[start,end]?
        if(it!=m.begin() && prev(it)->second>start) return false; // ?start????????
        m[start]=end;
        return true;
    }
    
    map<int,int> m;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */