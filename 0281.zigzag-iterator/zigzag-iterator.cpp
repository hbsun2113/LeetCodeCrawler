class ZigzagIterator {
public:
    // ????https://leetcode.com/problems/zigzag-iterator/discuss/71835/C++-with-queue-(compatible-with-k-vectors)
    // ?????????https://leetcode.com/submissions/detail/264979672/
    queue<pair<vector<int>::iterator,vector<int>::iterator>> q;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(!v1.empty()) q.push({v1.begin(),v1.end()});
        if(!v2.empty()) q.push({v2.begin(),v2.end()});
    }

    int next() {
        auto it=q.front().first;
        auto end=q.front().second;
        q.pop();
        if(it+1!=end) q.push({it+1,end});
        return *it;
    }

    bool hasNext() {
         return !q.empty();   
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */