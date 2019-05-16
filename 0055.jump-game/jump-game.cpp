class Solution {
public:
    // 三刷，做出来了
    // 注意：如果当前节点可以到达，则它之前所有的节点都是可以的到达的。
    bool canJump(vector<int>& nums) {
        int maxd=0;
        for(int i=0;i<nums.size();i++){
            if(maxd<i) return false;
            maxd=max(maxd,i+nums[i]);
        }
        return true;
        
    }
};