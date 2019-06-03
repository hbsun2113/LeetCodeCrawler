class Solution {
public:
    
    // https://www.acwing.com/solution/LeetCode/content/385/
    int totalHammingDistance(vector<int>& nums) {
        int res=0;
        for(int i=0;i<31;i++){ // 注意第32位是符号位，不算
            int ones=0;
            for(auto &n:nums){
                if(n&1) ones++;
                n>>=1;
            }
            res+=ones*(nums.size()-ones);
        }
        return res;
    }
    
    
    
    
    // http://www.cnblogs.com/grandyang/p/6208062.html
    // 有点找规律的意思：针对每一位 统计nums中在该位为1 的个数，记为one， 则该位贡献的HammingDistance为 one*zero。
    int totalHammingDistance1(vector<int>& nums) {
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