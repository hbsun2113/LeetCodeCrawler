class Solution {
public:
    int count;
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> result(target+1);
        result[0]=1;
        for(int i=1;i<=target;i++){
            for(const auto &num:nums){
                if(num<=i){
                    result[i]+=result[i-num];
                }
            }
        }
        return result[target];
            
    }
    
    
};