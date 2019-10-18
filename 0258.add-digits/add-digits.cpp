class Solution {
public:
    // https://leetcode.com/problems/add-digits/discuss/68580/Accepted-C++-O(1)-time-O(1)-space-1-Line-Solution-with-Detail-Explanations
    // ?????
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};