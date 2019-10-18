class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int res=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i+2<n && 3*nums[i]<target;i++){
            int l=i+1,r=n-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]<target){
                    res+=r-(l+1)+1;
                    l++;
                } 
                else r--;
            }
            
            
        }
        return res;
    }
};