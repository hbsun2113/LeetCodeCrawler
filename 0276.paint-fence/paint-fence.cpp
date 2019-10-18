class Solution {
public:
    // https://leetcode.com/problems/paint-fence/discuss/71152/Dynamic-programming-C++-O(n)-time-O(1)-space-0ms
    // https://leetcode.com/problems/paint-fence/discuss/71156/O(n)-time-java-solution-O(1)-space
    int numWays(int n, int k) {
        if(n==0) return 0;
        vector<int> same(n+1,0),diff(n+1,0);
        same[1]=0;
        diff[1]=k;
        for(int i=2;i<=n;i++){
            same[i]=diff[i-1];
            diff[i]=(k-1)*(same[i-1]+diff[i-1]); // ?????????? ????
        }
        return same.back()+diff.back();
    }
};