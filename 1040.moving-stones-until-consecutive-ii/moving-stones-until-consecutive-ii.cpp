class Solution {
public:
    // 比赛压轴题目contest135，没有做出来
    // https://leetcode.com/problems/moving-stones-until-consecutive-ii/discuss/286707/JavaC++Python-Sliding-Window
    // https://www.bilibili.com/video/av51556138
    // https://leetcode.com/problems/moving-stones-until-consecutive-ii/discuss/286886/No-code-just-chinese-explanation
    // 最大值：以把石头都移到最右侧为例，先把A[0]移动到A[1]的后面(首先把A[1]变为左边界，因此先+1)，然后左边界每次向右移动一格。
    vector<int> numMovesStonesII(vector<int>& stones) {
        
        sort(stones.begin(),stones.end());
        
        int i=0, n=stones.size();
        int minr=INT_MAX;
        for(int j=0;j<n;j++){
            while(stones[j]-stones[i]>=n) i++; // 可以塞不下，但不能有空隙
            if(j-i+1==n-1 && stones[j]-stones[i]+1==n-1){ // 注意我这里和原贴不一样，我这里更好理解
                minr=min(minr,2); 
                cout<<"1: "<<i<<" "<<j<<" "<<minr<<endl;
            }   
            else{
                minr=min(minr,n-(j-i+1)); // 正常情况
                cout<<"2: "<<i<<" "<<j<<" "<<minr<<endl;
            } 
                
        }
        int maxr=max(1+(stones[n-2]-1)-(stones[0]+n-1)+1, 1+(stones[n-1]-n+1)-(stones[1]+1)+1);
        
        vector<int> res{minr,maxr};
        return res;
    }
    
    
    
//     int bigh(vector<int> vis){
//         sort(vis.begin(),vis.end());
//         int ori_l=vis[0];
//         int res_l=0;
//         for(int i=1;i<vis.size()-1;i++){
//             if(vis[i+1]-vis[i]>1){
//                 vis[0]=vis[i]+1; 
//                 res_l=1+bigh(vis);
//             }
//         }
//         for(int i=vis.size()-1;i>1;i--){
//             if(vis[i]-vis[i-1]>1){
//                 vis[0]=vis[i]-1;
//                 res_l=max(res_l,1+bigh(vis));
//             }
//         }
        
//         vis[0]=ori_l;
        
//         int res_r=0;
//         for(int i=0;i<vis.size()-1;i++){
//             if(vis[i+1]-vis[i]>1){
//                 vis[vis.size()-1]=vis[i]+1;
//                 res_r=1+bigh(vis);
//             }
//         }
//         for(int i=vis.size()-2;i>=1;i--){
//             if(vis[i]-vis[i-1]>1){
//                 vis[vis.size()-1]=vis[i]-1;
//                 res_r=max(res_r,1+bigh(vis));
//             }
//         }
//         // cout<<res_l<<" "<<res_r<<endl;
//         return max(res_l,res_r);
//     }
};