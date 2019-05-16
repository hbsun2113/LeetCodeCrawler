class Solution {
public:
    
    //参考了https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/28218/My-8ms-C++-solution-(o(logn)-on-average-o(n)-worst-case) ，这个说得很好，但不能算是完全理解
    bool search(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        if(e<0) return false;
        int mid=(s+e)/2;
        while(s<=e){
            cout<<s<<" "<<e<<endl;
            mid=(s+e)/2;
            if(nums[mid]==target) return true;
            
            
            //这是唯一和Search in Rotated Sorted Array不同的地方，要进行单独处理。
            if((nums[s] == nums[mid]) && (nums[e] == nums[mid])){s++,e--;}
            
            
            
            //这次的边界条件比较清晰，需要记住。退出while循环的条件带等号，其余的边界条件是mid都不带等号，left和right需要带等号。
            else if(nums[mid]>=nums[s]){
                if(nums[mid]>target && nums[s]<=target){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else{
                if(nums[mid]<target && nums[e]>=target){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
                    
            }
        }
        cout<<s<<":"<<nums[s]<<":"<<target<<endl;
        if(s>=nums.size()) return false;
        return nums[s]==target;
    }
};