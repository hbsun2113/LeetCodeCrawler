class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        um[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto n:um){
            if(um.find(value-n.first)!=um.end()){
                if(n.first!=value-n.first) return true;
                if(n.first==value-n.first && um[n.first]>1) return true;
            }
        }
        return false;
    }
    
    unordered_map<int,int> um;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */