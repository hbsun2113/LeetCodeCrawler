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
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return res;
        queue<TreeNode*> q;
        q.emplace(root);
        while(!q.empty()){
            vector<int> tmp;
            int size=q.size();
            while(--size>=0){
                TreeNode* n=q.front();
                q.pop();
                tmp.emplace_back(n->val);
                if(n->left) q.emplace(n->left);
                if(n->right) q.emplace(n->right);
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};