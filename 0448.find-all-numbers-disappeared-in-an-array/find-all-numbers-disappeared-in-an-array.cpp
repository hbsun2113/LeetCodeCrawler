class Solution {
public:
    // https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/discuss/92956/Java-accepted-simple-solution
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int val=abs(nums[i])-1;
            nums[val]=-abs(nums[val]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) res.push_back(i+1);
        }
        return res;
    }
    
    // 二刷
    vector<int> findDisappearedNumbers2(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=nums[nums[i]-1]){ //nums[i]是一定可以找到自己的位置的，如果被"另一个自己"占了，那就没关系了
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        // for(int i=0;i<nums.size();i++)
        //     cout<<i+1<<":"<<nums[i]<<endl;
        for(int i=0;i<nums.size();i++){
            if(i+1!=nums[i]) res.push_back(i+1);
        }
        return res;
    }
    
    
    //也不算水题了，但是是自己做的。
    vector<int> findDisappearedNumbers1(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int value=nums[i];
            if(value!=nums[value-1]){
                nums[i]=nums[value-1];
                nums[value-1]=value;
                i--;
            }
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1) result.push_back(i+1);
        }
        
        return result;
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //思路比较简单，各找各妈，然后没有对上位置的就是有问题的。
};