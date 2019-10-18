class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        // if(nums.size()<3) return 0;
        int res1=0;
        for(int i=0;i<nums.size();i+=2){
            int left=INT_MAX;
            int right=INT_MAX;
            if(i-1>=0) left=nums[i-1];
            if(i+1<nums.size()) right=nums[i+1];
            int target=min(left,right)-1;
            res1+=max(0,nums[i]-target);
        }
        
        int res2=0;
        for(int i=1;i<nums.size();i+=2){
            int left=INT_MAX;
            int right=INT_MAX;
            if(i-1>=0) left=nums[i-1];
            if(i+1<nums.size()) right=nums[i+1];
            int target=min(left,right)-1;
            res2+=max(0,nums[i]-target);
        }
        
        return min(res1,res2);
    }
};