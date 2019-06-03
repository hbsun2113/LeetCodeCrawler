class Solution {
public:
    
    // 二刷，acwing和剑指offer有此题
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),1);
        if(nums.empty()) return res;
        int left=nums[0];
        for(int i=1;i<nums.size();i++){
            res[i]*=left;
            left*=nums[i];
        }        
        int right=nums.back();
        for(int i=nums.size()-2;i>=0;i--){
            res[i]*=right;
            right*=nums[i];
        }
        return res;
    }
    
    
    //不是自己做出来的，是参考了其他人的答案
    //https://leetcode.com/problems/product-of-array-except-self/discuss/65622/Simple-Java-solution-in-O(n)-without-extra-space
    vector<int> productExceptSelf1(vector<int>& nums) {
        
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