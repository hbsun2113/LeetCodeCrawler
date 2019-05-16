class Solution {
public:
    //这道题完全自己做出来的，粗略想想就应该是这个思路，可能背后还有其他原理吧，我没有深究。
    int arrayPairSum(vector<int>& nums) {
        int result=0;
        if(nums.size()==0) return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i+=2){
            result+=nums[i];
        }
        return result;
    }
};