class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(),nums.end());
        int index=0,time=0;
        while(index<nums.size()){
            if(nums[index]!=val){
                nums[time++]=nums[index++];
            }
            else{
                index++;
            }
        }
        return time;
    }
};