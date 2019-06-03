class Solution {
public:
    // 最快的解法，但是不能理解if(nums[start] > target) return false;是如何工作的。算了，还是用DP解吧。
    bool canPartition2(vector<int>& nums) {
        if(nums.empty()) return true;
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        sort(nums.begin(),nums.end(), greater<int>()); // 注意一定要 从大到小 排列! 这样可以避免很多不必要的处理过程
        return dfs(nums,0,sum/2);
    }
    
    bool dfs(vector<int>& nums, int start, int target){
        if(start>=nums.size()) return false;
        if(nums[start]==target){
            cout<<start<<" "<<target<<endl;
            return true;
        }
        if(nums[start] > target) return false;
        return dfs(nums,start+1,target-nums[start]) || dfs(nums,start+1,target);
    }
    
    
    
    
    
    
    
    // DP
    bool canPartition1(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        sum>>=1;
        cout<<sum<<endl;
        //flag[i][j]代表前i个数的组合可以得到j。
        vector<vector<int>> flag(nums.size()+1,vector<int>(sum+1));
        flag[0][0]=1;//前0个数自然可以得到0。
        
        for(int i=1;i<=nums.size();i++) flag[i][0]=1;//所有数都不选，自然是可以为0的
        //for(int i=1;i<=sum;i++) flag[0][i]=0;//前0个数肯定得不到i。
        
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=sum;j++){
                flag[i][j]=flag[i-1][j];
                //二刷心得：注意一定是dp[i-1][j-nums[i-1]]；不可以是dp[i][j-nums[i-1]]，这个存在重复利用nums[i-1]。
                if(j-nums[i-1]>=0) flag[i][j]=((flag[i-1][j]) || (flag[i-1][j-nums[i-1]]));           
            }
        }
        return flag[nums.size()][sum];
    }
    // 二刷DP
    bool canPartition3(vector<int>& nums) {
        if(nums.empty()) return true;
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        sum>>=1;
        vector<vector<bool>> dp(nums.size()+1,vector<bool>(sum+1,false));
        for(int i=0;i<nums.size()+1;i++) dp[i][0]=true;
        for(int i=1;i<=nums.size();i++){ 
            for(int j=1;j<=sum;j++){
                
                if(j<nums[i-1]) dp[i][j]=dp[i-1][j];
                
                //注意一定是dp[i-1][j-nums[i-1]]；不可以是dp[i][j-nums[i-1]]，这个存在重复利用nums[i-1]。
                else dp[i][j] = (dp[i-1][j] || dp[i-1][j-nums[i-1]]); 
                
            }
        }
        return dp[nums.size()][sum];
    }
    // 三刷DP，滚动数组
    // https://www.cnblogs.com/grandyang/p/5951422.html
    bool canPartition(vector<int>& nums) {
        if(nums.empty()) return true;
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        sum>>=1;
        vector<bool> dp(sum+1,false); //dp[i]表示原数组是否可以取出若干个数字，其和为i
        dp[0]=true;
        
        for(const auto &n:nums)
            for(int j=sum;j>=n;j--)
                dp[j] = dp[j] || dp[j-n];
                    
        return dp[sum];
    }
    
    
    // bit op
    // https://www.cnblogs.com/grandyang/p/5951422.html
    /*
    bits的第i位为1的话表示此数组里面存在组合使得该组合的和为i。
    此处采用归纳法简单的分析下算法：
    1.假设n之前的子列里面存在1~m,k~L……之间和的组合
    2.填加了数字n之后，将会存在(1+n)~(m+n),(k+n)~(L+n)……之间和的组合（只要在上面的组合里面添加当前的元素n即可），在标记bits里面相当于将bits向左边移动n 位，即bits << n
    3.故目前为止，存在1~m,k~L……以及(1+n)~(m+n),(k+n)~(L+n)……之间和的组合
    4.故bits |= bits << n
    */
    bool canPartition100(vector<int>& nums) {
        if(nums.empty()) return true;
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        bitset<10001> bits(1); // 声明一个位数组，一共10001位，初始化为最低位为1
        for(const auto &n:nums) bits|=(bits<<n);
        return bits[sum>>1];
    }
};