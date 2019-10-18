class MyCalendarTwo {
public:
    // https://www.cnblogs.com/grandyang/p/7968035.html
    MyCalendarTwo() {
        
    }
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        
        int cnt=0;
        for(const auto &n:m){
            cnt+=n.second;
            if(cnt>=3){
                m[start]--;
                m[end]++;
                return false;
            }
        }
        
        return true;
    }
    
    map<int,int> m;
    
    
    
    pair<int,int> cal_overlap(const pair<int,int> &a, const pair<int,int> &b){
        return {max(a.first,b.first),min(a.second,b.second)};
    }
    
    bool book1(int start, int end) {
        pair<int,int> tmp={start,end};
        for(const auto v2:vec2){
            auto t=cal_overlap(tmp,v2);
            if(t.first<t.second) return false;
        }
        
        for(const auto v1:vec1){
            auto t=cal_overlap({start,end},v1);
            if(t.first<t.second) vec2.push_back(t); // ??????????if
        }
        
        vec1.push_back(tmp);
        
        return true;
    }
    
    
    vector<pair<int,int>> vec1,vec2;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */