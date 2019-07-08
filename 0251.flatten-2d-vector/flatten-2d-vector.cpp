class Vector2D {
public:
    // https://www.cnblogs.com/grandyang/p/5209621.html 可能这个更好写一点吧。
    Vector2D(vector<vector<int>>& v) {
        x=v.begin();
        y=v.end();
        while(x!=y && x->size()==0) x++;
        if(x==y) return;
        z=x->begin();
    }
    
    int next() {
        hasNext(); // 先要把z调整到合适的位置上去
        return *z++;
    }
    
    bool hasNext() {
        while(x!=y && z==x->end()){
            x++;
            if(x==y) break;
            z=x->begin();
        }
        if(x==y) return false;
        return true;
    }
    
    // 迭代器做，节省空间
    vector<vector<int>>::iterator x, y;
    vector<int>::iterator z;
    
    // 如果有这两个变量，就是先转化为一维数组。这样没有意思
    vector<int> vec;
    int i;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */