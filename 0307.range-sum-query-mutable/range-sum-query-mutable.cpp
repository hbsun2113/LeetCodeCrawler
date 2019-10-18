class NumArray {
public:
    // https://www.youtube.com/watch?v=WbafSgetDDk
    
    NumArray(vector<int>& nums) {
        int n=nums.size();
        vec.resize(n,0); // ??????????
        presum.resize(n+1,0);
        for(int i=0;i<n;i++)
            update(i,nums[i]);
    }

    void update(int i, int val) {  // ??num[i]????val
        int delta=val-vec[i];
        int key=i+1;
        while(key<presum.size()){
            presum[key]+=delta;
            key+=getlowbitnum(key); // +
        }
        vec[i]=val; // ???????????
    }

    int sumRange(int i, int j) { // ?????????????????????
        return query(j)-query(i-1);
    }

    int query(int i){ // ??[0,i]????
        int sum=0;
        int key=i+1;
        while(key>0){
            sum+=presum[key];
            key-=getlowbitnum(key);  // -
        }
        return sum;
    }

    int getlowbitnum(int i){
        return i&~(i-1); // ?????,????????~
    }

    vector<int> vec,presum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */