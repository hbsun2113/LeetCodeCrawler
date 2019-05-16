class Solution {
public:
    //画个图好像就出来了 大水题。
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int index=0,value=nums[0],time=1;
        while(index<nums.size()){
            if(nums[index]!=value){
                value=nums[index];
                nums[time++]=nums[index++];
            }
            else{
                index++;
            }
        }
        return time;
    }
};