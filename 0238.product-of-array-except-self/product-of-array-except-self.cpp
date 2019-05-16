class Solution {
public:
    //不是自己做出来的，是参考了其他人的答案
    //https://leetcode.com/problems/product-of-array-except-self/discuss/65622/Simple-Java-solution-in-O(n)-without-extra-space
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> result(nums.size(),1);
        
        //遍历后，得到左面节点的乘积
        for(int i=1;i<nums.size();i++){
            result[i]=result[i-1]*nums[i-1];
        }
        
        //遍历后，得到右面节点的乘积
        int right=1;
        for(int i=nums.size()-1;i>=0;i--){
            result[i]*=right;
            right*=nums[i];
        }        
        
        
        return result;
    }
};