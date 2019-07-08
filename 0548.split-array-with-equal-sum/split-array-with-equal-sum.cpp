class Solution {
public:
    // https://leetcode.com/problems/split-array-with-equal-sum/discuss/101481/Simple-Java-solution-O(n2)
    // 为什么是7，考虑一下极限情况，每段只有一个数字:http://blog.hbsun.top/Fg2COYHNbnXMD_TXhgoVMiraCnlp
    // 思想：使用i、j、k作为三个分割点将整个array分为4段
    // 先规定j的范围，使用j将array分为前后两段，然后在前半段找i，使得i能再将前半段分为相等的两段，如果有合适的就放进set里面。
    // 然后再在后半段中找j，使得j能将后半段分为相等的两段，如果有并且和出现在set里了，那就找到了正确的结果了
    bool splitArray(vector<int>& nums) {
        if(nums.size()<7) return false;
        int n=nums.size();
        vector<int> presum(n);
        presum[0]=nums[0];
        for(int i=1;i<n;i++) presum[i]=presum[i-1]+nums[i];
        
        for(int j=3;j<=n-4;j++){
            unordered_set<int> us;
            for(int i=1;i<=j-2;i++){
                if(presum[i-1]==presum[j-1]-presum[i]) us.emplace(presum[i-1]);
            }
            
            for(int k=j+2;k<=n-2;k++){
                if(presum[k-1]-presum[j]==presum[n-1]-presum[k] && us.find(presum[k-1]-presum[j])!=us.end()) return true; 
            }
        }
        return false;
    }
};