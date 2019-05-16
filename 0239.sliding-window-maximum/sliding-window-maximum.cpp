class Solution {
public:
    // 二刷
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q; // 从队尾到队头，单调递增
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(!q.empty() && q.front()+k<=i) q.pop_front(); // 超出有效范围肯定要弹出
            while(!q.empty() && nums[q.back()]<nums[i]) q.pop_back(); // 后进来的比前面的大，那么前面的肯定再无出头之日
            q.push_back(i);
            if(i<k-1) continue;
            res.push_back(nums[q.front()]);
        }
        return res;
    }
    
    
    
    
    
    
    
    
    
    
    // 自己做的，但是花费了比较久的时间。
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        vector<int> vec;
        if(nums.size()==0) return vec;
        deque<int> q; //使用单调队列，注意是要使用双向队列！
        for(int i=0;i<nums.size();i++){
            if(!q.empty() && i-k>=0 && nums[i-k]==q.front()) q.pop_front();  //如果元素离开窗口并且恰好是当前队顶，则要弹出。
            while(!q.empty() && q.back()<nums[i]) q.pop_back(); //要从后面往前去除无用元素，因为插入的时候是从后往前插入的。
            q.push_back(nums[i]);
            if(i<k-1) continue;
            vec.push_back(q.front());
        }
        return vec;
    }
};