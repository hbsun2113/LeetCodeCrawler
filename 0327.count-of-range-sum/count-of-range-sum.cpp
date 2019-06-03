class Solution {
public:
    // 模板题目：https://leetcode.com/problems/reverse-pairs/discuss/97268/General-principles-behind-problems-similar-to-%22Reverse-Pairs%22
    // https://leetcode.com/problems/count-of-range-sum/discuss/77990/Share-my-solution
    int res=0;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> presum;
        presum.push_back(0);
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            presum.push_back(sum);
        }
        merge(presum,0,presum.size()-1,lower,upper);
        return res;   
    }
    
    void merge(vector<long long>& presum, int l, int r, int lower, int upper){
        if(l>=r) return ;
        int mid=l+r>>1;
        merge(presum,l,mid,lower,upper),merge(presum,mid+1,r,lower,upper);
        
        int i=l,j=mid+1,k=0,p=mid+1,q=mid+1;
        vector<long long> tmp(r-l+1);
        while(i<=mid){
            
            while(p<=r && presum[p]-presum[i]<lower) p++;
            while(q<=r && presum[q]-presum[i]<=upper) q++;
            res+=(q-p);
            
            while(j<=r && presum[j]<=presum[i]) tmp[k++]=presum[j++];
            tmp[k++]=presum[i++];
        }
        while(j<=r) tmp[k++]=presum[j++];
        
        move(tmp.begin(),tmp.end(),presum.begin()+l);
    }
};