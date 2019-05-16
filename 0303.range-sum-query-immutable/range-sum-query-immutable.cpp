class NumArray {
public:
    NumArray(vector<int> nums) {
        
        int length=nums.size();
        result=vector<vector<int>>(length,vector<int>(length,0));
        
        for(int i=0;i<nums.size();i++){
            int tmp=nums[i];
            result[i][i]=tmp;
            for(int j=i-1;j>=0;j--){
                tmp+=nums[j];
                result[j][i]=tmp;
            }
        }
    }
    
    int sumRange(int i, int j) {
        return result[i][j];
    }
    
    
vector<vector<int>> result;
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */