class Solution {
public:
    //https://leetcode.com/problems/third-maximum-number/discuss/90209/Short-easy-C++-using-set
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(const auto &n:nums){
            s.insert(n);
            if(s.size()>3) s.erase(s.begin()); //擦除无用元素保证了是 n*log(3)
        }
        //http://www.cplusplus.com/reference/set/set/rbegin/
        //http://www.cplusplus.com/reference/set/set/insert/
        return s.size()==3? *(s.begin()):*(s.rbegin());
        
        
    }
};