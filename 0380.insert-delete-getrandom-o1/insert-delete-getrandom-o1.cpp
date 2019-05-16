class RandomizedSet {
//自己没有做出来，参考了两个资料：
//http://www.cnblogs.com/grandyang/p/5740864.html
//https://leetcode.com/problems/insert-delete-getrandom-o1/discuss/85422/AC-C++-Solution.-Unordered_map-+-Vector
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(um.find(val)!=um.end()) return false;
        nums.emplace_back(val);
        um[val]=nums.size()-1;
        return true;
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(um.find(val)==um.end()) return false;
        
        //使用最后一个元素替换将要被删除的元素。
        int last=nums.back();
        um[last]=um[val];
        nums[um[val]]=last;
        
        nums.pop_back();
        um.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand()%nums.size()];
        
    }
private:
    unordered_map<int,int> um;
    vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */