class TimeMap {
public:
//自己写的，写麻烦了    
    /** Initialize your data structure here. */
//     TimeMap() {
        
//     }
    
//     void set(string key, string value, int timestamp) {
//         if(um.find(key)==um.end()) 
//             um[key]=vector<pair<int,string>>();
//         auto &vec=um[key];
//         vec.emplace_back(make_pair(timestamp,value));
//     }
    
//     string get(string key, int timestamp) {
//         if(um.find(key)==um.end()) return string("");
//         auto &vec=um[key];
//         if(vec[0].first>timestamp) return string("");
//         int l=-1,r=vec.size();
//         while(l+1!=r){
//             int mid=l+(r-l)/2;
//             auto &ele=vec[mid];
//             if(ele.first<timestamp) l=mid;
//             else r=mid;
//         }
//         cout<<vec.size()<<" "<<r<<endl;
//         if(r==vec.size() || vec[r].first!=timestamp) return vec[r-1].second;
//         return vec[r].second;
//     }
    
    
//     unordered_map<string,vector<pair<int,string>>> um;
    
    
    //参照https://leetcode.com/problems/time-based-key-value-store/discuss/226664/C++-3-lines-hash-map-+-map 写的
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        um[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto it=um[key].upper_bound(timestamp);
        return it==um[key].begin()?"":prev(it)->second;
    }
    
    
    unordered_map<string,map<int,string>> um;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */