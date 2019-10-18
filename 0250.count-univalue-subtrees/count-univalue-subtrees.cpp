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
    int res=0;
    int countUnivalSubtrees(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return res;
    }
    
    bool dfs(TreeNode* root){
        if(!root || (!root->left && !root->right)){
            res++;
            return true;
        }
        
        if(root->left && root->right){
            auto l=dfs(root->left);
            auto r=dfs(root->right);
            if(!l || !r) return false;
            if(root->left->val!=root->val || root->right->val!=root->val) return false;
            res++;
            return true;
        }
        
        if(root->left){
            auto l=dfs(root->left);
            if(l && root->left->val==root->val){
                res++;
                return true;
            } 
            return false;
        }
        
        if(root->right){
            auto r=dfs(root->right);
            if(r && root->right->val==root->val){
                res++;
                return true;
            } 
            return false;
        }
        
        return true;
    }
};