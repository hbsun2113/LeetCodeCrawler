class Solution {
public:
    // 四刷做得不好，没有想到合适的数据结构
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size()==0 && k==0) return 1;
        if(nums.size()==0 && k!=0) return 0;
        int sum=nums[0];
        int res=0;
        if(sum==k) res++;
        for(int i=1;i<nums.size();i++){
            sum+=nums[i];
            nums[i]=sum;
            // cout<<i<<" "<<nums[i]<<endl;
            if(nums[i]==k) res++;
            for(int j=0;j<i;j++){
                if(nums[i]-nums[j]==k) res++;
            }
        }
        return res;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //三刷了，怎么还是无法联系到前序和！！
    int subarraySum3(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int sum=0;
        int res=0;
        um[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            res+=um[sum-k];
            um[sum]++; // 这个要放在最后。 否则如果k==0，会出现重复计数的情况下。
        }
        return res;        
    }
    
    
    //二刷没有做出来：https://www.acwing.com/solution/LeetCode/content/432/
    //一句话醍醐灌顶：每个和为k的subarry都对应了一对前序和差为k的点。
    int subarraySum2(vector<int>& nums, int k) {
        unordered_map<int,int> presum;
        presum[0]=1; //这个一定一定要注意！！
        int sum=0,count=0;
        for(const auto &num:nums){
            sum+=num;
            count+=presum[sum-k];
            presum[sum]++;
        }
        return count;
    }
};