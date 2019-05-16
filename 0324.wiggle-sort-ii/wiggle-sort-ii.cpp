class Solution {
public:
    
    /*题意是奇数位置小于两侧，偶数位置大于两侧。*/
    //照抄：https://www.cnblogs.com/grandyang/p/5139057.html
    //上面这个解法好像也不是最优的，最优的是https://leetcode.com/problems/wiggle-sort-ii/discuss/77677/O(n)+O(1)-after-median-Virtual-Indexing。可是我没看懂，二刷的话可以看看。
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp(nums);
        //cout<<&(tmp[0])<<" "<<&(nums[0])<<endl;
        sort(tmp.begin(),tmp.end());
        //如果长度是偶数，两段长度相等，没有什么可说的。
        //如果长度是奇数，则奇数位置的个数要大于偶数位置的个数，因此第一段要大于第二段的长度。所以有了nums.size()+1。
        int i=(nums.size()+1)/2-1,j=nums.size()-1; //从末尾取元素，是尽量拉开两段数组的位置。
        //cout<<"i="<<i<<" j="<<j<<endl;
        for(int n=0;n<nums.size();n++){
            nums[n]=n&1?tmp[j--]:tmp[i--];
        }
    }
       /*
        //0,1,2,3 
        //4:1,3
        
        //0,1,2,3,4
        //5:2,4
        */
    
    
    
};