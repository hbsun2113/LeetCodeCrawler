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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.emplace(root);
        int res=0;
        while(!q.empty()){
            res++;
            int size=q.size();
            while(--size>=0){
                TreeNode* tmp=q.front();
                q.pop();
                if(!tmp->left && !tmp->right) return res;
                if(tmp->left) q.emplace(tmp->left);
                if(tmp->right) q.emplace(tmp->right);
            }
        }
        return INT_MIN;
    }
};