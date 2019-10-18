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
    // https://leetcode.com/problems/binary-tree-upside-down/discuss/49406/Java-recursive-(O(logn)-space)-and-iterative-solutions-(O(1)-space)-with-explanation-and-figure
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* pre=nullptr;
        TreeNode* tmp=nullptr;
        TreeNode* cur=root;
        
        while(cur){
            auto next=cur->left;
            
            cur->left=tmp;
            tmp=cur->right;
            cur->right=pre;
            
            pre=cur;
            cur=next;
        }
        return pre;

    }
    
    
    // ????????????Reverse Linked List??????????
    TreeNode* upsideDownBinaryTree1(TreeNode* root) {
        if(!root) return root;
        if(!root->left) return root;
        auto left=root->left;
        auto right=root->right;
        root->left=nullptr;
        root->right=nullptr;
        auto res=upsideDownBinaryTree(left);
        left->left=right;
        left->right=root;
        return res;
    }
};