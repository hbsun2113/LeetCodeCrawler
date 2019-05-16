class Solution {
public:
    // https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image
    // 顺时针旋转90，先行之间反转，然后沿着对角线交换。
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(),matrix.end());
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    
    // 逆时针旋转90，现针对每一个行进行行内反转，然后沿着对角线交换。
    void rotate1(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(auto &m:matrix)
            reverse(m.begin(),m.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};