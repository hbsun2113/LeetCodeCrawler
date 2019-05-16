class Solution {
public:
    // 二刷，自己做出来了
    // 左边界：右面还有比自己小的、右边界：左面一定还有比自己大的
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int min_value=nums.back();
        int l=nums.size()-1;
        for(int i=l-1;i>=0;i--){
            if(nums[i]<=min_value){
                min_value=nums[i];
            }
            else 
                l=i;
        }
        
        int max_value=nums[0];
        int r=0;
        for(int i=r+1;i<nums.size();i++){
            if(nums[i]>=max_value){
                max_value=nums[i];
            }
            else 
                r=i;
        }
        if(r<=l) return 0;
        cout<<l<<" "<<r<<" "<<r-l+1<<endl;
        return r-l+1;
    }
    
    //这题我看discuss了，不是自己做出来的。
    int findUnsortedSubarray1(vector<int>& nums) {
        int end=-1000,start=-1000; //随便赋值，无所谓。
        int maxv=nums[0],minv=nums[nums.size()-1];
        
        //现在寻找右边界
        for(size_t i=1;i<nums.size();i++){
            maxv=max(maxv,nums[i]);
            if(maxv>nums[i]) end=i;//如果前面有值比我大，那我肯定要挪动位置
        }
        
        //现在寻找左边界
        for(int i=nums.size()-2;i>=0;i--){ //这里还是需要注意的呀，只能是int类型，不能是size_t类型。
            minv=min(minv,nums[i]);
            if(minv<nums[i]) start=i;//如果后面有值比我小，那我肯定要挪动位置
        }
        
        if(end==-1000 && start==-1000) return 0;//如果本身就是排好序的呢？则end和start就不会发生变化。
        return end-start+1;
        
        
        //这道题目正向思维(从左向右找左边界)是不行的:
        //    比如我想找左边界，如果我发现nums[i]比nums[i+1]大，则我记录左边界是i.
        //这样的问题在于：如果nums[i]==nums[i+1]时，是不需要标记左边界的，但可能后面nums[j]<nums[i],其实位置就应该被挪动了。
        //那为什么正确解法使用反向思维就可以呢？
        //因为它是从右向左更新的，这样可以发现最新的需要被改变的位置。
        
        //总结以下：以后发现正向思维行不通，要马上考虑反着怎么想。
        
        
    }
};