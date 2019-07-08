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
    // 参照了https://leetcode.com/problems/delete-node-in-a-bst/discuss/93296/Recursive-Easy-to-Understand-Java-Solution里的最高赞comment
    // 流程：1. 首先递归找到目标节点
    // 2.1 如果该节点既没有左儿子有没有右儿子，直接返回nullptr就行
    // 2.2 如果该节点缺失了其中一个儿子，只要返回另一个儿子就行了
    // 2.3 如果两个儿子都在，我们实施这样的一种策略安排它的左子树，递归找到右子树最小的节点t，然后把左子树作为t的左子树。返回右子树即可。
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val>key) root->left=deleteNode(root->left,key);
        else if(root->val<key) root->right=deleteNode(root->right,key);
        else{
            if(!root->left && !root->right) return nullptr;
            if(!root->left) return root->right;
            if(!root->right) return root->left;
            auto t=root->right;
            while(t->left) t=t->left;
            t->left=root->left;
            return root->right;
        }
        return root;
    }
};