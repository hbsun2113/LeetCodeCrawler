class Solution {
public:
    
    //1:这个解法使用了O(n)的space。O(n)的时间
    void rotate1(vector<int>& nums, int k) {
        k=k%nums.size();
        vector<int> tmp;
        for(int i=nums.size()-1;i>=0;i--){
            int target=i+k;
            if(target>=nums.size()){
                tmp.push_back(nums[i]);
            }
            else{
                nums[target]=nums[i];
            }
        }
        for(int i=0;i<tmp.size();i++) nums[i]=tmp[tmp.size()-i-1];
    }
    
    
    
    //这个解法我怎么就没想到！！！
    void rotate(vector<int>& nums, int k) {
        k %=nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
    
};