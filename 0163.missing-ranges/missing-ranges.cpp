typedef long long ll;
class Solution {
public:
    // ????????leetcode??????????????
    // ???????????pre???
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        ll pre=0ll+lower-1;
        for(int i=0;i<nums.size();i++){
            if(pre==nums[i]) continue; // ??
            if(nums[i]!=0ll+pre+1) res.push_back(build(0ll+pre+1,0ll+nums[i]-1));
            pre=nums[i];
        }
        if(upper!=pre) res.push_back(build(pre+1,upper));
        return res;
    }
    
    string build(ll a, ll b){
        if(a==b) return to_string(a);
        else return to_string(a)+"->"+to_string(b);
    }
};