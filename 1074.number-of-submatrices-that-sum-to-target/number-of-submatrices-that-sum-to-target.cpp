class Solution {
public:
    // https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/discuss/83599/Accepted-C++-codes-with-explanation-and-references
     // 模板题
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int res=0;
        int row=matrix.size();
        int col=matrix[0].size();
        for(int l=0;l<col;l++){
            vector<int> tmp(row,0);
            for(int r=l;r<col;r++){
                
                for(int i=0;i<row;i++) tmp[i]+=matrix[i][r];
                
                unordered_map<int,int> um;  // 注意这里要使用map而不是set
                um[0]=1;
                int pre_sum=0;
                for(int i=0;i<row;i++){
                    pre_sum+=tmp[i];
                    if(um.find(pre_sum-target)!=um.end()) res+=um[pre_sum-target];
                    um[pre_sum]++;
                }
                
            }
        }
        return res;
       
    }
};