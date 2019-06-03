class Solution {
public:
    // https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/discuss/303814/ChineseC%2B%2B-1072./283882
    // 此题虽然是改变col，但其实看的是row
    // 假设我们现在拥有了最优答案matrix A，假设A[i]这一行是符合条件的(即所有值相等)，我们会发现其他满足条件的行A[j]在初始状态时和和A[i]的pattern是一样的，即如果A[i][0]==A[j][0],则A[i][1]==A[j][0];如果A[i][0]!=A[j][0],则A[i][1]!=A[j][0]
/*  
0 0 0      1 1 0
0 0 1  ->  1 1 1 
1 1 0      0 0 0 
第二行和第三行在最优状态下是一致的，它们在初始状态下pattern是一样的
所以我们只要在初始状态下，找到哪些行有相同pattern就行了
*/    
    int maxEqualRowsAfterFlips1(vector<vector<int>>& matrix) {
        int row=matrix.size();
        if(row==0) return 0;
        int col=matrix[0].size();
        int res=0;
        for(int i=0;i<row;i++){
            int tmp=0;
            for(int j=i;j<row;j++){
                if(issamepattern(matrix[i],matrix[j])) tmp++;
            }
            res=max(res,tmp);
        }
        return res;
    }
    
    bool issamepattern(vector<int> &a, vector<int> &b){
        int len=a.size();
        if(a[0]==b[0]){
            for(int i=0;i<len;i++){
                if(a[i]!=b[i]) return false;
            }
            return true;
        }
        else {
            for(int i=0;i<len;i++){
                if(a[i]==b[i]) return false;
            }
            return true;
        }
    }
    
    
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> h;
        int max = 0;
        for (auto & row : matrix) {
            string str, str2;
            for (int x : row) {
                str.push_back('0' + x); // 尽可能1
                str2.push_back('1' - x); // 尽可能0
            }
            h[str] += 1;
            h[str2] += 1;
            if (h[str] > max)
                max = h[str];
            if (h[str2] > max)
                max = h[str];
        }
        return max;
    }
};