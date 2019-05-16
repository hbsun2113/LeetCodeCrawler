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
    //还是要注意是根节点到“叶子节点”的距离！
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(root->val==sum && (!root->left) && (!root->right)) return true;
        return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
    }
};