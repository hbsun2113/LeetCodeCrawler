class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mv=0;
        for(int i=0;i<nums.size();i++){
            if(mv<i) return false;
            mv=max(mv,i+nums[i]);
        }
        return true;
    }
};