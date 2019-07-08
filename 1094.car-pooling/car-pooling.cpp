class Solution {
public:
    
    // 这个比我自己的解法好在：只对特定的点(上车与下车时维护人数)，进行计算
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> vec;
        for(const auto &v:trips){
            int a=v[0],b=v[1],c=v[2];
            vec.push_back({b,a});
            vec.push_back({c,-a});
        }
        
        sort(vec.begin(),vec.end());
        int p=0;
        
        for(const auto &v:vec){
            p+=v.second;
            if(p>capacity) return false;
        }
        
        return true;
    }
    
    // 原来大神们都是这么写的呀
    bool carPooling2(vector<vector<int>>& trips, int capacity) {
        map<int, int> locs;
        for (const vector<int>& t : trips) {
            locs[t[1]] += t[0];
            locs[t[2]] -= t[0];
        }
        
        int have = 0;
        for (auto p : locs) {
            have += p.second;
            if (have > capacity) return false;
        }
        
        return true;
    }
    
    
    
    
    
    
    
    
    
    // 自己写的，太暴力了：把每个时间点的人数都求出来了，然后看看是否有所超出。
    bool carPooling1(vector<vector<int>>& trips, int capacity) {
        vector<int> vec(1010,0);
        int maxv=0;
        for(auto &v:trips){
            int c=v[0];
            int a=v[1];
            int b=v[2];
            for(int i=a;i<b;i++){
                vec[i]+=c;
                maxv=max(maxv,vec[i]);
            }
        }
        cout<<capacity<<" "<<maxv<<endl;
        return capacity>=maxv;
    }
};