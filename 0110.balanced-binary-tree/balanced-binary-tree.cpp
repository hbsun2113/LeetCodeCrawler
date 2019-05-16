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
    bool isBalanced(TreeNode* root) {
        bool flag=true;
        if(!root) return true;
        balance(root,flag);
        return flag;
    }
    
    int balance(TreeNode* root,bool &flag){
        if(!flag) return false;
        if(!root) return 0;
        int llength=balance(root->left,flag);
        int rlength=balance(root->right,flag);
        if(abs(llength-rlength)>1) 
        {
            flag=false;
            return 0;
        }else{
            return max(llength,rlength)+1;
        }
        
    }
};