class Solution {
public:
    //完全自己做的，也没有任何技巧，感觉不是acm题目吧。
    //看了discuss,原来自己只是用了有序这一性质，但是没有用从大到小这一性质，还可以再改进一下。
    int removeDuplicates(vector<int>& nums) {
        int length=nums.size();
        if(length<=2) return length;
        int result=length;
        for(int i=2;i<result;i++){
            if(nums[i]==nums[i-1] && nums[i]==nums[i-2]){
                result--;
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return result;
    }
};