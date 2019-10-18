class MajorityChecker {
public:
    // https://leetcode.com/problems/online-majority-element-in-subarray/discuss/356108/C++-Index-Binary-Search
    // ???????????
    // ?????make sense???????????????,??????????????????????
    // ???????????????key,index??value?
    MajorityChecker(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            auto &n=arr[i];
            um[n].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        for(auto &[n,v]:um){
            if(v.size()<threshold) continue;
            auto l=lower_bound(v.begin(),v.end(),left);
            auto r=upper_bound(v.begin(),v.end(),right);
            if(r-l>=threshold) return n;
        }
        return -1;
    }
    
    unordered_map<int,vector<int>> um;
    
    

    
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */