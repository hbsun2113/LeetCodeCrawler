/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 这道题目不难，主要是没有审题仔细，注意从上往下，一定是单调递增的！
    // 人家写的https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/discuss/74468/Easy-Java-DFS-is-there-better-time-complexity-solution
    int maxv=0;
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        dfs(root,root->val,0);
        return maxv;
    }
    
    // 自己写的，不优雅
    int longestConsecutive1(TreeNode* root) {
        if(!root) return maxv;
        maxv=max(maxv,1);
        dfs(root->left,root->val+1,1);
        dfs(root->right,root->val+1,1);
        return maxv;
    }
    
    void dfs(TreeNode* root, int target, int dep){
        if(!root) return ;
        if(root->val==target) dep++;
        else dep=1;
        maxv=max(maxv,dep);
        dfs(root->left,root->val+1,dep);
        dfs(root->right,root->val+1,dep);
    }
};