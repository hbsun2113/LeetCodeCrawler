class Solution {
public:
    // 二刷，自己做出来的
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> vec(26,0);
        int max_count=INT_MIN;
        for(const auto &t:tasks){
            vec[t-'A']++;
            max_count=max(max_count,vec[t-'A']);
        }
        int max_num=0;
        for(const auto &v:vec){
            if(v==max_count) max_num++;
        }
        // 要么有空格，有么无空格，取最大值
        // 有空格情况，只需关注数量最多的元素：(max_count-1)*(n+1)+max_num
        // 无空格情况：tasks.size()
        return max((max_count-1)*(n+1)+max_num,(int)tasks.size());
    }
    
    
    
    //一刷，不是自己做出来的，https://leetcode.com/problems/task-scheduler/discuss/104496/concise-Java-Solution-O(N)-time-O(26)-space。想法其实比较简单，建议下回自己做一下吧。
    
    int leastInterval1(vector<char>& tasks, int n) {
        vector<int> times(26);
        
        for(auto &c:tasks)
            times[c-'A']+=1;
        
        sort(times.begin(),times.end()); //此时频率最高的元素一定是排在c[25]
        
        int index=25;
        while(index>=0 && times[index]==times[25]) index--; //看看有多少个“最高频元素”。
        
        return max((int)tasks.size(),(n+1)*(times[25]-1)+25-index);//注意frame可能还不够容纳整个tasks的长度呢，这时候肯定是要以tasks.size()为准了。
        
    }
};