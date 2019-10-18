class Solution {
public:
    int candy(vector<int>& nums) {
        int n=nums.size();
        vector<int> vec(n,1);
        
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]) vec[i]=vec[i-1]+1;
        }
        
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]) vec[i]=max(vec[i],vec[i+1]+1);
        }
        
        return accumulate(vec.begin(),vec.end(),0);
    }
};