class MyHashMap {
public:
    
    // 这道题目前两次的提交虽然AC了但都是错误的，重新写一下。
    // 拉链法和开放寻址法
    // https://www.acwing.com/solution/LeetCode/content/443/
    const static int N = 20011;
    vector<list<pair<int,int>>> hash;
    
    /** Initialize your data structure here. */
    MyHashMap() {
        hash=vector<list<pair<int,int>>>(N);
    }
    
    list<pair<int,int>>::iterator find(int key){
        int hkey=key%N;
        auto res=hash[key%N].begin();
        while(res!=hash[hkey].end()){
            if(res->first==key) break;
            res++;
        }
        return res;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto res=find(key);
        if(res==hash[key%N].end())
            hash[key%N].emplace_back(key,value);
        else 
            res->second=value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto res=find(key);
        if(res!=hash[key%N].end())
            return res->second;
        else 
            return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto res=find(key);
        if(res!=hash[key%N].end())
            hash[key%N].erase(res);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */