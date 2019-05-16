class Solution {
//更优秀的解法：https://leetcode.com/problems/sort-colors/discuss/26479
public:
    void sortColors(vector<int>& nums) {
        vector<int> result(nums.size(),1);
        int i=0,j=nums.size()-1;
        for(auto e:nums){
            if(e==0) result[i++]=0;
            else if(e==2) result[j--]=2;
        }
        nums=result;
    }
};

//还是参考了Follow up:
// A rather straight forward solution is a two-pass algorithm using counting sort.
// First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

// Could you come up with an one-pass algorithm using only constant space?

