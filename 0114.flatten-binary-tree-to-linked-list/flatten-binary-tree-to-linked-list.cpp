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
    // 自己写的，有点麻烦
    // 更简洁的做法，但不太好想：https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/36977/My-short-post-order-traversal-Java-solution-for-share
    void flatten(TreeNode* root) {
        if(!root) return;
        helper(root);
        // vis(root);
    }
    
    //debug用
    void vis(TreeNode* root){
        if(!root) return ;
        cout<<root->val<<" ";
        vis(root->left);
        vis(root->right);
    }
    
    TreeNode* helper(TreeNode* root){
        if(!root) return nullptr;
        if(!root->left && !root->right) return root;
        auto ltail=helper(root->left);
        auto rtail=helper(root->right);
        if(ltail){
            ltail->right=root->right;
            root->right=root->left;
        }
        root->left=nullptr;
        if(rtail) return rtail;
        else return ltail;
    }
  

    
};