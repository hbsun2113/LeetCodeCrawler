/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
 *
 * algorithms
 * Medium (52.34%)
 * Total Accepted:    33.4K
 * Total Submissions: 63.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty integer array, find the minimum number of moves required
 * to make all array elements equal, where a move is incrementing a selected
 * element by 1 or decrementing a selected element by 1.
 * 
 * You may assume the array's length is at most 10,000.
 * 
 * Example:
 * 
 * Input:
 * [1,2,3]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * Only two moves are needed (remember each move increments or decrements one
 * element):
 * 
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 * 
 * 
 */
class Solution {
public:
    // https://www.acwing.com/activity/content/problem/content/165/1/
    int minMoves2(vector<int>& nums) {
        int len=nums.size();
        nth_element(nums.begin(),nums.begin()+nums.size()/2,nums.end()); // 将中位数置于它应该在的位置
        int res=0;
        for(const auto &n:nums){
            res+=abs(n-nums[nums.size()/2]);
        }
        return res;
    }

    // 自己做的。先排序，针对每一个数，看看它左面需要补充多少，再看看右面需要削弱多少，两个相加就是结果。
    int minMoves23(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long res=INT_MAX;
        int len=nums.size();
        for(const auto &n:nums){
            auto it1=lower_bound(nums.begin(),nums.end(),n);
            int len1=distance(nums.begin(),it1);
            long long tmp1=(long long)len1*n-accumulate(nums.begin(),it1,0);
            auto it2=upper_bound(it1,nums.end(),n);
            int len2=distance(it2,nums.end());
            long long tmp2=accumulate(it2,nums.end(),0)-(long long)len2*n;
            cout<<tmp1<<" "<<tmp2<<endl;
            res=min(res,tmp1+tmp2);
        }
        return res;
    }
};

