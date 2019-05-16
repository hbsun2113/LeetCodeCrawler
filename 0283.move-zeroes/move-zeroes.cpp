class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
                continue;
            }
            nums[i-count]=nums[i];
        }
        
        while(count>0){
            //cout<<"count="<<count<<endl;
            nums[nums.size()-count]=0;
            count--;
        }
    }
};