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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        while(!q1.empty() || !q2.empty()){
            vector<int> part;
            if(!q1.empty()){
                while(!q1.empty()){
                    TreeNode* tmp=q1.front();
                    q1.pop();
                    part.push_back(tmp->val);
                    if(tmp->left) q2.push(tmp->left);
                    if(tmp->right) q2.push(tmp->right);
                }
                result.push_back(part);
                part.clear();
            }
            
            else if(!q2.empty()){
                while(!q2.empty()){
                    TreeNode* tmp=q2.front();
                    q2.pop();
                    part.push_back(tmp->val);
                    if(tmp->left) q1.push(tmp->left);
                    if(tmp->right) q1.push(tmp->right);
                }
                result.push_back(part);
                part.clear();
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};