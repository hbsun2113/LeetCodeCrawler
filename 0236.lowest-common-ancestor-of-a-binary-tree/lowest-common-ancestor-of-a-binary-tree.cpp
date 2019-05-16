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
    // 三刷，自己做出来了
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root==p || root==q) return root;
        auto l=lowestCommonAncestor(root->left,p,q);
        auto r=lowestCommonAncestor(root->right,p,q);
        if(l && r) return root;
        else if(l) return l;
        else return r;
    }
    
    //二刷，没有做出来，还是看了第一次的答案，只能说是太巧妙了。
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root==p || root==q) return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left && right) return root;
        if(!left && right) return right;
        if(left && !right) return left;
        return nullptr;
    }
    
    //不是自己做出来的，是看别人的代码了。
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(root==p || root==q) return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q); //左子树中有符合条件的点
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        
        if(left && right) return root;
        if(left && !right) return left;
        if(!left && right) return right;
        return nullptr;
    }
};