class Solution {
public:
    // 二刷，试了一下双指针，对应的是follow up1。
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> res;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                res.push_back(nums1[i]);
                i++,j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            } 
        }
        return res;
    }
    
    
    //本应该用双指针做(https://leetcode.com/problems/intersection-of-two-arrays-ii/discuss/82263/C++-hash-table-solution-and-sort-+-two-pointers-solution-with-time-and-space-complexity)，但是我没有。
    vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> um1;
        vector<int> result;
        for(const auto &num:nums1) um1[num]++;
        for(const auto &num:nums2){
            if(um1.find(num)!=um1.end()){
                result.push_back(num);
                um1[num]--;
                if(um1[num]==0) um1.erase(num);
            }
        }
        return result;
        
    }
    
    
    
};