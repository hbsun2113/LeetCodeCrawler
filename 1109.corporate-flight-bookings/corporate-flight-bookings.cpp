class Solution {
public:
    // https://leetcode.com/problems/corporate-flight-bookings/discuss/
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n);
        for(const auto &v:bookings){
            res[v[0]-1]+=v[2];  // 注意序号是从1开始的
            if(v[1]<n) res[v[1]]-=v[2];
        }
        
        for(int i=1;i<n;i++) res[i]+=res[i-1];
        
        return res;
    }
    
    // 比赛时Contest 144  自己的代码
    vector<int> corpFlightBookings1(vector<vector<int>>& bookings, int n) {
        vector<int> res(n);
        map<int,int> m;
        int cur=0;
        for(const auto &v:bookings){
            int x=v[0],y=v[1],z=v[2];
            m[x]+=z;
            m[y+1]-=z;
        }
        
        // for(const auto &i:m){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        
        auto it=m.begin();
        int s=it->first;
        cur=it->second;
        it++;
        int t;
        while(it!=m.end()){
            t=it->first;
            cout<<s<<" "<<t<<" "<<cur<<endl;
            for(int i=s;i<t;i++) res[i-1]=cur;
            cur+=it->second;
            s=t;
            it++;
        }
        
        
        return res;
    }
};