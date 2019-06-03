class MedianFinder {
public:
    /** initialize your data structure here. */
    //感觉自己被虐惨了，看看人家的代码：http://www.cnblogs.com/grandyang/p/4896673.html
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        a.push(num);
        b.push(a.top());
        a.pop();
        if(a.size()<b.size()){
            a.push(b.top());
            b.pop();
        }
    
    }
    
    double findMedian() {
        if(a.size()>b.size()) return a.top();
        else return (a.top()+b.top())/2.0;
    }
    
    
    priority_queue<int> a; // 大堆：从大到小 取出。存放前半部分数据
    priority_queue<int,vector<int>,greater<int>> b; // 小堆，从小到大 取出。存放后半部分数据
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */