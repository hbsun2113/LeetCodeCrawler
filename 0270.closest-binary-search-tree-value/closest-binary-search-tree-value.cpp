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
    int closestValue(TreeNode* root, double target) {
        if(!root) return target;
        int res=root->val;
        while(root){
            if(root->val>target){
                if(abs(res-target)>(root->val-target)) res=root->val;
                root=root->left;
            }
            else{
                if(abs(res-target)>(target-root->val)) res=root->val;
                root=root->right;
            }
        }
        return res;
    }
};