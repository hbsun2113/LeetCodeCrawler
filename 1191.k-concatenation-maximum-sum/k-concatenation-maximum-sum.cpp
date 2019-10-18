class Solution {
public:
    // neal_wu???+https://leetcode.com/problems/k-concatenation-maximum-sum/discuss/382442/ChineseC++-1191.
    const long long MOD=1e9+7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long fullsum=accumulate(arr.begin(),arr.end(),0.000);
        long long best=0;
        long long sum=0;
        for(const auto &n:arr){
            sum+=n;
            if(sum<0) sum=0;
            best=max(best,sum);
        }
        
        long long max_prefix=0;
        sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            max_prefix=max(max_prefix,sum);
        }
        
        long long max_suffix=0;
        sum=0;
        for(int i=arr.size()-1;i>=0;i--){
            sum+=arr[i];
            max_suffix=max(max_suffix,sum);
        }
        
        if(k>1){
            best=max(best,max_prefix+max_suffix);  // fullsum?????0??????????????1. arr???????? 2. ?????????????????
            best=max(best,max_prefix+max_suffix+(k-2)*fullsum); // fullsum??0??????????????????????????????????
        }
        
        return best%MOD;
    }
    
    
};