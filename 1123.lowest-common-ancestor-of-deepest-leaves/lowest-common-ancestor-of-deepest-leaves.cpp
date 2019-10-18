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
    // ??????????????????????
    // ?????????????????????????
    // ???????????????????[A?B?C?D]???[A?D]?????????[A?B?C?D]?????????[A?D]????
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<vector<TreeNode*>> vec; // ???????
        queue<TreeNode*> q;
        q.push(root);
        int i=0;
        while(!q.empty()){
            vec.push_back(vector<TreeNode*>());
             for(int j=q.size()-1;j>=0;j--){
                 auto t=q.front();
                 q.pop();
                 vec[i].push_back(t);
                 if(t->left) q.push(t->left);
                 if(t->right) q.push(t->right);
             }
            i++;
        }
        if(vec.back().size()==1) return vec.back()[0];
        cout<<vec.back().size()<<endl;
        auto p1=vec.back()[0];
        auto p2=vec.back().back();
        return dfs(root,p1,p2);
    }
    
    
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr) return nullptr;
        if(root==p || root==q) return root;
        auto l=dfs(root->left,p,q);
        auto r=dfs(root->right,p,q);
        if(l && r) return root;
        if(l) return l;
        if(r) return r;
        return nullptr;
    }
};