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
    // ????????
    // https://leetcode.com/problems/inorder-successor-in-bst/discuss/72653/Share-my-Java-recursive-solution
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root) return nullptr;
        if(root->val<=p->val) return inorderSuccessor(root->right,p);
        else {
            auto res=inorderSuccessor(root->left,p);
            if(res!=nullptr) return res;
            else return root;
        }
        
        
    }
    
    
    
    // ?????????????????
    TreeNode* inorderSuccessor1(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> q;
        bool flag=false;
        while(!q.empty() || root){
            while(root){
                q.push(root);
                root=root->left;
            }
            
            root=q.top();
            // cout<<root->val<<endl;
            q.pop();
            if(root==p) flag=true;
            else if(flag) return root;
            
            root=root->right;
        }
        
        return nullptr;
    }
};