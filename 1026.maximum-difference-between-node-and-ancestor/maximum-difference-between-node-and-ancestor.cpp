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
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return res;
    }
    
    pair<int,int> dfs(TreeNode* root){
        if(!root) return make_pair<int,int>(INT_MAX,INT_MIN);
        if(!root->left && !root->right) return make_pair(root->val,root->val);
        auto l=dfs(root->left);
        auto r=dfs(root->right);
        int v=root->val;
        if(l.first!=INT_MAX) res=max(res,abs(v-l.first));
        if(l.second!=INT_MIN) res=max(res,abs(v-l.second));
        if(r.first!=INT_MAX) res=max(res,abs(v-r.first));
        if(r.second!=INT_MIN) res=max(res,abs(v-r.second));
        int minv=INT_MAX;
        int maxv=INT_MIN;
        minv=min(minv,l.first);
        minv=min(minv,r.first);
        minv=min(minv,v);
        maxv=max(maxv,l.second);
        maxv=max(maxv,r.second);
        maxv=max(maxv,v);
        return make_pair(minv,maxv);
    }
};