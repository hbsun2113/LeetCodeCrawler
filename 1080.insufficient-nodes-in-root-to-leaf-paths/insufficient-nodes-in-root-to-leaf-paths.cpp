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
    // 这个题目描述得很不好，所以大家都踩它
    
    // 此题目没有描述清楚，它要求删除中间节点，不是去删除叶子节点。
    // 即如果叶子节点的sum<limit,也不会删除该叶子节点。
    TreeNode* sufficientSubset(TreeNode* root, long long limit) {
        TreeNode* res=root;
        return dfs(root,limit,0);
    }
    
    
    TreeNode* dfs(TreeNode* root, long long limit, long long curr){
        if(!root) return nullptr;
        if((!root->left) && (!root->right) && (0ll+curr+root->val<limit)) return nullptr;

        auto flag= (root->left) || (root->right); // 先标志一下是否是叶子节点
        root->left=dfs(root->left,limit,0ll+curr+root->val);
        root->right=dfs(root->right,limit,0ll+curr+root->val);
      
        if((!root->left) && (!root->right) && flag) return nullptr; // 如果之前是有孩子的(说明是中间节点)，但现在没有了，就把它也删除。如果之前就是叶子节点，无论sum是否小于limit都不删除。

        return root;
    }
};