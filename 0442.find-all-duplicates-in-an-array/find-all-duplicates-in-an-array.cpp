class Solution {
public:
/*
0 1 2 3 4 5 6 7
4 3 2 7 8 2 3 1
1 2 3 4     7 8
*/
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            while(nums[nums[i]-1]!=nums[i]){ //给每个元素找到真正的位置，但如果其位置上已经有正确的元素了，就跳过。
                int tmp=nums[i];
                nums[i]=nums[tmp-1];
                nums[tmp-1]=tmp;
            }
        }
        for(int i=0;i<nums.size();i++){ //没在正确位置上的元素都是重复的。
            if(nums[i]!=i+1) result.push_back(nums[i]);
        }
        return result;
    }
};