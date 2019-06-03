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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return res;
        dfs(root,"");
        return res;
    }
    
    void dfs(TreeNode* root, string tmp){
        tmp+=to_string(root->val)+"->";
        if(!root->left && !root->right){
            tmp.pop_back();
            tmp.pop_back();
            res.push_back(tmp);
            return ;
        }
        
        if(root->left) dfs(root->left,tmp);
        if(root->right) dfs(root->right,tmp);
        
    }
};