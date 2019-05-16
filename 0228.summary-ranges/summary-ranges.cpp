class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size()==0) return res;
        int i=1;
        long long prev=nums[0];
        while(i<nums.size()){
            while(i<nums.size() && (long long)nums[i]-nums[i-1]==1) i++;
            if(i==nums.size()) continue;
            res.push_back(com(prev,nums[i-1]));
            prev=nums[i];
            i++;
        }
        res.push_back(com(prev,nums.back()));
        return res;
        
    }
    
    string com(long long l,long long r){
        if(l==r) return to_string(l);
        else return to_string(l)+"->"+to_string(r);
    }
};