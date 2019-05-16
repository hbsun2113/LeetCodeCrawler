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
    //完全自己做的 解法。我暂时觉得这是最优方案了，不清楚为什么要使用binary search.
    int gk;
    int kthSmallest(TreeNode* root, int k) {
        gk=k;
        return helper(root);
    }
    
    int helper(TreeNode* root){
        if(!root) return -1;
        if(root->left){
            int result=helper(root->left);
            if(result!=-1) return result;
        }
        gk--;
        //cout<<gk<<endl;
        if(gk==0) return root->val;
        if(root->right){
            int result=helper(root->right);
            if(result!=-1) return result;
        }
        return -1;
    }
    
    
    
};