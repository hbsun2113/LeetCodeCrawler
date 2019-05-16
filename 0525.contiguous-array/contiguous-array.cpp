class Solution {
public:
    // 二刷，还是前序和解。我统计的是1的个数和0的个数的差值，如果在两个位置处这个差值相等，说明中间这段0和1的个数是相等的。
    int findMaxLength(vector<int>& nums) {
        int o=0,z=0;
        unordered_map<int,int> um;
        um[0]=-1; // 为了应对0和1个数相等的情况。
        int res=0;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            if(n==0) z++;
            else o++;
            if(um.find(o-z)!=um.end()){
                res=max(res,i-um[o-z]);
            }
            else
                um[o-z]=i;
        }
        return res;
    }
    
    // 这个是把0当作-1，然后去找子序和为0的最大长度。前序和相等的两个端点中间的子序和为0。
    int findMaxLength1(vector<int>& nums) {
        unordered_map<int,int> um;
        um[0]=0;
        int sum=0;
        int result=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) sum--;
            else sum++;
            if(um.find(sum)!=um.end()) result=max(result,i+1-um[sum]); //注意是不包含左边界的
            else um[sum]=i+1;
        }
        return result;
    }
};