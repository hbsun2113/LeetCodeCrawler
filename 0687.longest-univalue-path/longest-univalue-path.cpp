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
    int res=1;
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return res-1;
    }
    
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int ans=1; // 本节点为转折点能拿到的最大长度
        auto l=dfs(root->left);
        auto r=dfs(root->right);
        if(root->left && root->left->val==root->val) ans+=l;
        if(root->right && root->right->val==root->val) ans+=r;
        res=max(res,ans);
        int x=1,y=1;
        if(root->left && root->left->val==root->val) x=max(x,l+1);
        if(root->right && root->right->val==root->val) y=max(y,r+1);
        return max(x,y); // 本节点为非转折点，能返回的最大长度
    }
    
    
};