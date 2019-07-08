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
    // 看了它大致的思路，然后自己写了一遍
    // 重点是维护两个变量inc和dec，分别代表该节点属于递增序列时的最大长度、该节点属于递减序列时的最大长度
    // 它俩既可以由左儿子更新，又可以由右儿子更新
    // https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/discuss/101519/Neat-Java-Solution-Single-pass-O(n)
    int maxv=0;
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return maxv;
    }
    
    pair<int,int> dfs(TreeNode* root){
        if(!root) return {0,0};
        int inc=1,dec=1; // 自己是属于递增序列还是递减序列
        
        if(root->left){
            auto t=dfs(root->left);
            if(root->val==root->left->val+1) inc=t.first+1;        
            if(root->val==root->left->val-1) dec=t.second+1;
        }
        
        if(root->right){
            auto t=dfs(root->right);
            if(root->val==root->right->val+1) inc=max(inc,t.first+1);
            if(root->val==root->right->val-1) dec=max(dec,t.second+1);
        }
        
        maxv=max(maxv,inc+dec-1);  // 注意这行，要这么更新
        
        return {inc,dec};
    }
};