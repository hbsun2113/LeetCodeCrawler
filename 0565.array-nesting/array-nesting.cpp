class Solution {
public:
    //完全自己做的，暴力搜索。
    int arrayNesting1(vector<int>& nums) {
        int result=0;
        if(nums.size()==0) return result;
        vector<bool> flags(nums.size(),false);
        vector<int> record(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            result=max(result,length(nums,flags,1,i,record));
        }
    
        return result;
    }
    
    
    //record是用来保存中间结果的，如果没有这个，就会超时。
    int length(vector<int>& nums,vector<bool> & flags,int len, int index,vector<int>& record){
        if(flags[index]) return len-1;
        flags[index]=true;
        int result;
        if(record[nums[index]]) result=record[nums[index]];
        else result=length(nums,flags,len+1,nums[index],record);
        flags[index]=false;//这行有没有其实是无所谓的。
        record[index]=max(record[index],result);
        return result;
    }
    
    
    
    //https://leetcode.com/problems/array-nesting/discuss/102432/C++-Java-Clean-Code-O(N)
    //更简单的解法：思路很简单，其实就是求最大环的长度。要知道环和环之间是不重叠的，因此一旦visit过，就不必再访问了。
    int arrayNesting(vector<int>& nums) {
        size_t maxsize = 0;
        for (int i = 0; i < nums.size(); i++) {
            size_t size = 0;
            for (int k = i; nums[k] >= 0; size++) {
                int ak = nums[k];
                nums[k] = -1; // mark a[k] as visited;
                k = ak;
            }
            maxsize = max(maxsize, size);
        }

        return maxsize;
    }
};