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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if(!root) return result;
        vector<int> part;
        part.push_back(root->val);
        if(root->val==sum && (!root->left) && (!root->right)) result.push_back(part);
        judge(root->left,sum-root->val,part,result);
        judge(root->right,sum-root->val,part,result);
        return result;
    }
    
    
    void judge(TreeNode* root, int sum, vector<int> part, vector<vector<int>> &result){
        if(!root) return ;
        part.push_back(root->val);
        if(root->val==sum && (!root->left) && (!root->right)) result.push_back(part);
        judge(root->left,sum-root->val,part,result);
        judge(root->right,sum-root->val,part,result);
    }
};