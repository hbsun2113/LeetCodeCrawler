class Solution {
public:
    int maxSumSubmatrix1(vector<vector<int>>& matrix, int k) {
    if (matrix.empty()) return 0;
    int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
    for (int l = 0; l < col; ++l) {
        vector<int> sums(row, 0);
        for (int r = l; r < col; ++r) {
            for (int i = 0; i < row; ++i) {
                sums[i] += matrix[i][r];
            }
            
            // Find the max subarray no more than K 
            set<int> accuSet;
            accuSet.insert(0);
            int curSum = 0, curMax = INT_MIN;
            for (int sum : sums) {
                curSum += sum;
                set<int>::iterator it = accuSet.lower_bound(curSum - k);
                if (it != accuSet.end()) curMax = std::max(curMax, curSum - *it);
                accuSet.insert(curSum);
            }
            res = std::max(res, curMax);
        }
    }
    return res;
}
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int res=INT_MIN;
        int row=matrix.size();
        if(row==0) return 0;
        int col=matrix[0].size();
        for(int l=0;l<col;l++){
            vector<int> tmp(row,0);
            for(int r=l;r<col;r++){
                
                for(int i=0;i<row;i++) tmp[i]+=matrix[i][r];
                
                set<int> us;// 由于后面要使用lower_bound，所以要求有序
                us.emplace(0);
                int pre_sum=0;
                for(int i=0;i<row;i++){
                    pre_sum+=tmp[i];
                    auto it=lower_bound(us.begin(),us.end(),pre_sum-k);
                    // auto it=us.lower_bound(pre_sum-k);
                    if(it!=us.end()) res=max(res,pre_sum-*it);
                    us.emplace(pre_sum);
                }
                
            }
        }
        return res;
    }
};