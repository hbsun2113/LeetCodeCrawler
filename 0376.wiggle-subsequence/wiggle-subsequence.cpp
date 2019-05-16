class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty()) return 0;
        int len=nums.size();
        vector<int> up(len,1),down(len,1);  // 分别定义当当前位置为上升时最大wiggle sequence的长度，下降时最大长度。
        for(int i=1;i<len;i++){
            if(nums[i]>nums[i-1]){
                up[i]=down[i-1]+1; //如果当前位置上升，则更新的是up，并且承接的是前一个节点的down
                down[i]=down[i-1];
            }
            else if(nums[i]<nums[i-1]){
                down[i]=up[i-1]+1;
                up[i]=up[i-1];
            }
            else{
                down[i]=down[i-1];
                up[i]=up[i-1];
            }
        }
        return max(down.back(),up.back());
    }
};