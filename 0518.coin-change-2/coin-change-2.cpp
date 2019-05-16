class Solution {
public:
    //tmp[i][j]代表前i个物品组成j的个数
    //tmp[i][j]=未使用i的组合个数+使用了i的组合个数
    // https://leetcode.com/problems/coin-change-2/discuss/99212/Knapsack-problem-Java-solution-with-thinking-process-O(nm)-Time-and-O(m)-Space
    int change(int amount, vector<int>& coins) {
        int count=coins.size();
        vector<vector<int>> tmp(count+1,vector<int>(amount+1,0));
        tmp[0][0]=1;
        for(int i=1;i<=count;i++){
            tmp[i][0]=1;
            for(int j=1;j<=amount;j++){ //当j<coins[i-1]时，tmp[i][j]=tmp[i-1][j]而不是0.
                int unsed_i=tmp[i-1][j];
                int used_i=j >= coins[i - 1] ? tmp[i][j - coins[i - 1]] : 0;
                 tmp[i][j]=unsed_i+used_i;
            }
        }
        return tmp[count][amount];
    }
};