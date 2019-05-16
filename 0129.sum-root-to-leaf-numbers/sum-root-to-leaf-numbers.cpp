/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//参考了看看discuss，自己没有想到！！
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return add(root,0);
    }
    
    
    int add(TreeNode* son,int value){
        if(!son) return 0;
        if(!son->left && !son->right) return son->val+10*value;//处理叶子
        return add(son->left,value*10+son->val)+add(son->right,value*10+son->val);//处理inner节点
    }
};