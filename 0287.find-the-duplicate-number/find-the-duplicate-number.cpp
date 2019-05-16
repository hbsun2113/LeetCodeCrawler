class Solution {
public:
    // 和一刷初始化条件不一样，但感觉一刷的初始化更好些
    int findDuplicate(vector<int>& nums) {
        int low=nums[0],high=nums[nums[0]];
        // int low=0,high=nums[0]; //这个不对：low没有跳，high跳了一下。此时high不是low的2倍
        while(low!=high){
            low=nums[low];
            high=nums[nums[high]];
        }
        low=0;
        while(low!=high){
            low=nums[low];
            high=nums[high];
        }
        return low;
    }
    
    //虽然自己没有做出来，但是理解了
    //https://leetcode.com/problems/find-the-duplicate-number/discuss/72846/My-easy-understood-solution-with-O(n)-time-and-O(1)-space-without-modifying-the-array.-With-clear-explanation.
    //的做法。就是将数组里的值当作指针，然后发现这是个带环路的链表，现在只要找到链表的入口就可以了(链表的入口被指了两次，自然就是重复的值了)。
    //解法很精妙啊。另外一个不重要的点就是，即使一个值重复了多次(>2)，其实也没有关系，只要进入到第一个环就可以了。
    int findDuplicate1(vector<int>& nums) {
        int fast=0,slow=0;
        while(1){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(fast==slow) break;
        }
        slow=0;
        while(fast!=slow){
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
};