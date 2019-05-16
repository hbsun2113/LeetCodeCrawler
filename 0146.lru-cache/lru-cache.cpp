class LRUCache {
    //不难，只是之前不知道双向链表的用法
    //https://leetcode.com/problems/lru-cache/discuss/45912/Clean-Short-Standard-C++-solution-NOT-writing-C-in-C++-like-all-other-lengthy-ones
    //中英文还是不过关啊：
    //http://www.cplusplus.com/reference/list/list/splice/
    //https://blog.csdn.net/bichenggui/article/details/4674900
public:
    LRUCache(int capacity) {
        c=capacity;
    }
    
    int get(int key) {
        auto it=um.find(key);
        if(it==um.end()) return -1;
        l.splice(l.begin(),l,it->second);
        return it->second->second;
    }
    
    //http://www.cnblogs.com/grandyang/p/4587511.html
    void put(int key, int value) {
        if(get(key)!=-1){
            um[key]->second=value;
            return ;
        }
        if(l.size()==c){
            um.erase(l.back().first);
            l.pop_back();
        }
        l.emplace_front(make_pair(key,value));
        um[key]=l.begin();
    }
    
    
    int c;
    list<pair<int,int>> l; //key->val 维持顺序+存储数据
    unordered_map<int,list<pair<int,int>>::iterator> um;  //key->iterator 用于查询
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */