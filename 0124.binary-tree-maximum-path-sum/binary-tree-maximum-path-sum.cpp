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
    int res=INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        helper(root);
        return res;
    }

    int helper(TreeNode* root){
        if(!root) return 0;
        /*if(!root->left && !root->right){
            res=max(res,root->val);
            return root->val;
        }*/
        int left=max(0,helper(root->left));
        int right=max(0,helper(root->right));
        res=max(res,left+right+root->val);
        return root->val+max(left,right);
    }
    
    
    
    
    /*
    //自己做的
    int res=0;
    
    int maxPathSum(TreeNode* root) {
        if(root) res=root->val;
        helper(root);
        return res;
    }
    
    //返回的是以本节点为根(但不是转折点)的最大和，左右只能选一个或者都不选
    int helper(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right){
            res=max(res,root->val);
            return root->val;
        }
        int left=helper(root->left);
        int right=helper(root->right);
        int tmp=root->val;
        if(left>0) tmp+=left;
        if(right>0) tmp+=right;
        cout<<root->val<<" "<<tmp<<endl;
        res=max(res,tmp);  //同时更新以本节点为根(是转折点)时能拿到的最大和
        if(left<0 && right<0) return root->val;
        return max(left,right)+root->val;
    }*/
};