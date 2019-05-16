class Solution {
public:
    // 很不好想，还是先记住吧
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res(nums.size());
        int size=0;
        for(const auto& n:nums){
            int i=-1,j=size;
            while(i+1!=j){
                int mid=(i+j)/2;
                if(res[mid]<n) i=mid;
                else j=mid;
            }
            res[j]=n;
            if(j==size) size++;
        }
        return size;
    }
    
    
    int lengthOfLIS4(vector<int>& nums) {
        vector<int> tail(nums.size());
        int size=0;
        for(const auto &n:nums){
            int i=-1,j=size;
            while(i+1!=j){
                int mid=i+(j-i)/2;
                if(n>tail[mid]) i=mid;
                else j=mid;
            }
            tail[j]=n;
            if(j==size) size++;
        }
        return size;
    }
    
    
    
    
    //三刷，这个解法自己感觉想不粗来：https://leetcode.com/problems/longest-increasing-subsequence/discuss/74824/JavaPython-Binary-search-O(nlogn)-time-with-explanation
    int lengthOfLIS3(vector<int>& nums) {
        vector<int> tail(nums.size());
        int size=0;
        for(const auto& n:nums){
            int l=-1,r=size;
            while(l+1<r){
                int mid=l+(r-l)/2;
                if(tail[mid]<n) l=mid;
                else r=mid;
            }
            tail[r]=n;
            if(r==size) size++;
        }
        return size;
    }
    
    
    
    
    //自己做的 O(n2) 
    int lengthOfLIS1(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int result=0;
        vector<int> len(nums.size());
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    len[i]=max(len[j]+1,len[i]);
                }
            }
            result=max(result,len[i]);
        }        
        return result+1;
    }
    
    
    // O(n log n)这个解法过于精妙，我没有理解。
    //https://segmentfault.com/a/1190000003819886 和 https://leetcode.com/problems/longest-increasing-subsequence/discuss/74824/JavaPython-Binary-search-O(nlogn)-time-with-explanation
    int lengthOfLIS2(vector<int>& nums) {
        vector<int> tail(nums.size());
        int size=0;
        for(auto & n:nums){
            int i=0,j=size;
            while(i!=j){
                int mid=i+(j-i)/2;
                if(n>tail[mid]) i=mid+1;
                else j=mid;
            }
            tail[i]=n;
            if(i==size) size++;
        }
        return size;
    }
    
};