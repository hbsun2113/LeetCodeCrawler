class Solution {
public:
    
    //成熟的算法只需要记忆：https://leetcode.com/problems/next-permutation/discuss/13867/C++-from-Wikipedia
    void nextPermutation(vector<int>& nums) {
        if(is_sorted(nums.rbegin(),nums.rend())){
            sort(nums.begin(),nums.end());
            return ;
        }
        
        int right;
        int j=0;
        while(j+1<nums.size()){
            if(nums[j]<nums[j+1]) right=j;
            j++;
        }
        // cout<<right<<endl;
        
        for(int i=nums.size()-1;i>right;i--){
            if(nums[i]>nums[right]){
                swap(nums[i],nums[right]);
                sort(nums.begin()+right+1,nums.end());
                break;
            }
        }
    }
    
    
    
    void nextPermutation1(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};