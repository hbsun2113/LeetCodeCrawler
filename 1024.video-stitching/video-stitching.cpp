class Solution {
public:
    // 这是contest130的压轴题。
    // 要想全覆盖，则肯定是集合之间有交集。
    // 因此我们先按照头排序，然后针对每一个区间，基于它前面的合适区间得到自己的最优解。
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> dp(clips.size(),INT_MAX);
        auto cmp=[](vector<int> &a, vector<int> &b){
            return a[0]<b[0];
        };
        sort(clips.begin(),clips.end(),cmp);
        if(clips[0][0]!=0) return -1;
        for(int i=0;i<clips.size();i++){
            if(clips[i][0]==0) 
                dp[i]=1;
        }
        for(int i=0;i<clips.size();i++){
            for(int j=0;j<i;j++){
                if(dp[j]!=INT_MAX && clips[j][1]>=clips[i][0]){
                    dp[i]=min(dp[i],dp[j]+1);
                }
            }
        }
        int res=INT_MAX;
        for(int i=0;i<clips.size();i++){ 
            if(clips[i][1]>=T) // 只遍历这些集合来得到全局最优解
                res=min(res,dp[i]);
        }
        if(res==INT_MAX) return -1;
        return res;
    }
};