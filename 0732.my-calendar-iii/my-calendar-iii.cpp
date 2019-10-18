class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int res=0;
        int cnt=0;
        for(const auto &n:m){
            cnt+=n.second;
            res=max(res,cnt);
        }
        return res;
    }
    
    map<int,int> m;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */