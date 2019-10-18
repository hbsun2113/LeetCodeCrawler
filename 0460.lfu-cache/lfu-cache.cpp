class LFUCache {
public:
    // https://www.cnblogs.com/grandyang/p/6258459.html
    LFUCache(int _capacity) {
        capacity=_capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        int val=m[key].first;
        int &pre_freq=m[key].second; // ???????
        freq[pre_freq].erase(iter[key]);
        if(freq[min_freq].size()==0) min_freq++; // ????????++,?????????+1?
        pre_freq++;
        freq[pre_freq].push_back(key);
        iter[key]=--freq[pre_freq].end(); // ????,??????????????
        return val;
    }
    
    void put(int key, int value) {
        if(capacity<=0) return;
        if(get(key)!=-1){
            m[key].first=value;
            return;
        }
        
        // ??? ??? ?????????
        if(m.size()>=capacity){
            auto min_freq_key=freq[min_freq].front(); // ???????api
            m.erase(min_freq_key);
            iter.erase(min_freq_key);
            freq[min_freq].pop_front(); // ???????api
        }
        
        min_freq=1;
        m[key]={value,1};
        freq[1].push_back(key);
        iter[key]=--freq[1].end();
    }
    
    int capacity; // ???
    
    int min_freq; // ???????
    
    unordered_map<int,pair<int,int>> m;  // key->{val,freq}???????
    
    // frequence->list of the key have the same frequence???????????freq[min_freq]????
    unordered_map<int,list<int>> freq;   

    unordered_map<int,list<int>::iterator> iter; // key->position in the frequence list ?????list???????????list
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */