class Solution {
public:
    // http://www.cnblogs.com/grandyang/p/6208062.html
    // 有点找规律的意思：针对每一位 统计nums中在该位为1 的个数，记为one， 则该位贡献的HammingDistance为 one*zero。
    int totalHammingDistance(vector<int>& nums) {
        int res=0;
        int size=nums.size();
        for(int i=31;i>=0;i--){
            int one=0;
            for(const auto &n:nums){
                one+=((n>>i)&1);
            }
            res+=one*(size-one);
        }
        return res;
    }
};