class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target) return i;
            else{
                if(nums[i]>target){
                    nums.insert(nums.begin()+i,target);
                    return i;
                }
            }
        }
        nums.push_back(target);
        return nums.size()-1;
    }
};