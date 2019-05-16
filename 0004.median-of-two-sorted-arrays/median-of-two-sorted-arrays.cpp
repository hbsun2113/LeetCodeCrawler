class Solution {
public:
    
    // 三刷，这道题目感觉挺难的，没有做出来
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int l=(m+n+1)/2, r=(m+n+2)/2;
        return (bh(nums1,nums2,0,0,l)+bh(nums1,nums2,0,0,r))/2.0;
    }
    
    double bh(vector<int>& nums1, vector<int>& nums2, int i, int j, int k){
        if(i>=nums1.size()) return nums2[j+k-1];
        if(j>=nums2.size()) return nums1[i+k-1];
        if(k==1) return min(nums1[i],nums2[j]);// 否则下文中 k/2-1 可能小于0
        
        int n1=INT_MAX,n2=INT_MAX;
        if(i+k/2-1<nums1.size()) n1=nums1[i+k/2-1];
        if(j+k/2-1<nums2.size()) n2=nums2[j+k/2-1];

        if(n1<n2) return bh(nums1,nums2,i+k/2,j,k-k/2);
        else return bh(nums1,nums2,i,j+k/2,k-k/2);
    }
    
    
    
    
    
    
    
    
    
    
    
    // 二刷，自己又没有做出来。看的是一刷的答案。
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        // sort(nums1.begin(),nums1.end());
        // sort(nums2.begin(),nums2.end());
        int m=nums1.size();
        int n=nums2.size();
        //中位数是(nums[left]+nums[right])/2,这样寻找中位数就转化为在两个数组中找第K个数字了。
        int left=(m+n+1)/2; 
        int right=(m+n+2)/2;
        // cout<<left<<" "<<right<<endl;
        // cout<<helper(nums1,nums2,0,0,left)<<" "<<helper(nums1,nums2,0,0,right)<<endl;
        return (helper(nums1,nums2,0,0,left)+helper(nums1,nums2,0,0,right))/2.0;
    }
    
    //i标记的是nums1的起始位置 
    //j标记的是nums2的起始位置
    //k是要在nums1和nums2中找到第k个数
    int helper(vector<int>& nums1, vector<int>& nums2, int i, int j, int k){  
        //各种边界条件
        if(i>=nums1.size()) return nums2[j+k-1];
        if(j>=nums2.size()) return nums1[i+k-1];
        if(k==1) return min(nums1[i],nums2[j]);
        
        // 使用二分法优化。每次砍掉k/2个数的搜索空间
        // 分别在nums1和nums2中找到第k/2个数，如果tmp1<tmp2,说明第nums1中前k/2个数都是无效的，反之亦然。
        // 如果nums1中剩余的数量都不足k/2了，而我们每次都可以砍掉k/2个数字，则我们此次砍掉的是nums2中前k/2个数字，所以赋值为tmp1为max。
        int tmp1=(i+k/2-1<nums1.size())?nums1[i+k/2-1]:INT_MAX; 
        int tmp2=(j+k/2-1<nums2.size())?nums2[j+k/2-1]:INT_MAX;
        if(tmp1<tmp2) return helper(nums1,nums2,i+k/2,j,k-k/2);
        else return helper(nums1,nums2,i,j+k/2,k-k/2);
    }
    
    
    //没做出来，参照了http://www.cnblogs.com/grandyang/p/4465932.html。
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int left=(m+n+1)/2;
        int right=(m+n+2)/2;
        return (findKthNum(nums1,nums2,0,0,left)+findKthNum(nums1,nums2,0,0,right))/2.0;
    }
    
    //在两个数组中找第k个元素。使用二分法，递归。
    int findKthNum(vector<int>& nums1, vector<int>& nums2, int i,int j, int k){ 
        if(i>=nums1.size()) return nums2[j+k-1];
        if(j>=nums2.size()) return nums1[i+k-1];
        if(k==1) return min(nums1[i],nums2[j]); //因为下文有k/2，所以对于k==1要特殊处理。
        int tmp1=(i+k/2-1<nums1.size())?nums1[i+k/2-1]:INT_MAX;
        int tmp2=(j+k/2-1<nums2.size())?nums2[j+k/2-1]:INT_MAX;
        if(tmp1<tmp2) return findKthNum(nums1,nums2,i+k/2,j,k-k/2);
        if(tmp1>=tmp2) return findKthNum(nums1,nums2,i,j+k/2,k-k/2);
    }
};