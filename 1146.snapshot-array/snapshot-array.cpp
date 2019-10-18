class SnapshotArray {
public:
    // ????contest-148????????????AC?
    SnapshotArray(int length) {}
    
    void set(int index, int val) {
        um[index][snap_id]=val;
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        if(um.find(index)==um.end()) return 0;
        auto &u=um[index]; // ?????????????????
        auto it=u.upper_bound(snap_id);
        if(it==u.begin()) return 0;
        it--;
        return it->second;
    }
    
    int snap_id=0;
    unordered_map<int, map<int,int>> um;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */