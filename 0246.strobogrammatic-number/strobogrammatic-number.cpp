class Solution {
public:
    bool isStrobogrammatic(string nums) {
        if (nums.size() == 1) {
            return nums == "0" || nums == "1" || nums == "8";
        }
        
        int i=0,j=nums.size()-1;
        while(i<=j){
            if(nums[i]=='6' && nums[j]=='9'){
                i++,j--;
            }
            else if(nums[i]=='9' && nums[j]=='6'){
                i++,j--;
            }
            else if(nums[i]=='8' && nums[j]=='8'){
                i++,j--;
            }
            else if(nums[i]=='1' && nums[j]=='1'){
                i++,j--;
            }
            else if(nums[i]=='0' && nums[j]=='0'){
                i++,j--;
            }
            
            else return false;
        }
        return true;
    }
};