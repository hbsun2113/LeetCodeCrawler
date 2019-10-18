class Solution {
public:
    // ???https://www.cnblogs.com/grandyang/p/6146986.html
    // ???https://leetcode.com/problems/convex-polygon/discuss/95590/C++-5-liner-O(N)-checking-convexity-with-cross-product-of-adjacent-vectors-(detailed-explanation)
    // ???????????????????A1??????????A2,A3???(A2-A1)???(A3-A1)?????????
    bool isConvex(vector<vector<int>>& points) {
        long long pre=0,n=points.size();
        for(int i=0;i<n;i++){
            long long dx1=points[(i+1)%n][0]-points[i][0];
            long long dy1=points[(i+1)%n][1]-points[i][1];
            long long dx2=points[(i+2)%n][0]-points[i][0];
            long long dy2=points[(i+2)%n][1]-points[i][1];
            long long cur=dx1*dy2-dx2*dy1;
            if(cur!=0){
                if(cur*pre<0) return false;
                else pre=cur;
            }
        }
        return true;
    }
};