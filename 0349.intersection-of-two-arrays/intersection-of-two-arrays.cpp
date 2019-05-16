class Solution {
public:
    //O(n)这应该是最快的
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> us(nums1.begin(),nums1.end());
        for(const auto n:nums2){
            if(us.erase(n)) result.emplace_back(n);
        }
        return result;
    }
    
    
    
    
    
    //没有使用二分法，暴力求解
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int index1=0,index2=0;
        while(index1<nums1.size() && index2<nums2.size()){
            if(nums1[index1]==nums2[index2]){
                if(result.empty() || nums1[index1]!=result.back()){
                    result.emplace_back(nums1[index1]);
                }
                index1++,index2++;
                continue;
            }
            else if(nums1[index1]<nums2[index2]) index1++;
            else index2++;
        }
        return result;
    }
};