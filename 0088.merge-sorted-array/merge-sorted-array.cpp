class Solution {
public:
    //没啥说的 比较简单 但不知道为什么这道题目评分很低？
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0){
            nums1=nums2;
            return;
        }
        if(n==0) return;

        int count=0,i=0,j=0,k=0;
        //预处理
        int length1=nums1.size(),length2=nums2.size();
        for(int x=m;x<length1;x++) nums1.erase(nums1.begin()+nums1.size()-1);
        for(int x=n;x<length2;x++) nums2.erase(nums2.begin()+nums2.size()-1);
        // for(auto & num:nums1) cout<<"a:"<<num<<endl;
        // for(auto & num:nums2) cout<<"b:"<<num<<endl;
        
        while(i<m+n && j<n){//将nums2中 小于nums1中最大值 的所有元素插入进去。
            if(nums1[i]>nums2[j]){
                nums1.insert(nums1.begin()+i,nums2[j++]);
            }
            i++;
        }
        int ii=i;
        i=nums1.size();
        while(nums1[i]<=nums2[j] && j<n){//此处循环是避免nums2中还有剩余元素。
            nums1.insert(nums1.begin()+i,nums2[j++]);
            i=nums1.size();
        }
        
    }
};