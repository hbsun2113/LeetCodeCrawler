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
    vector<TreeNode*> res;
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> us(to_delete.begin(),to_delete.end());
        add(root,us);
        TreeNode *t=new TreeNode(INT_MIN);
        t->left=root;
        dfs(t,us);
        return res;
    }
    
    void dfs(TreeNode* root, unordered_set<int> &us){
        // cout<<root->val<<endl;
        if(!root) return ;
        dfs(root->left,us);
        dfs(root->right,us);
        
        auto l=root->left;
        auto r=root->right;
        if(l && us.find(l->val)!=us.end()){
            add(l->left,us);
            add(l->right,us);
            root->left=nullptr;
        }
        if(r && us.find(r->val)!=us.end()){
            add(r->left,us);
            add(r->right,us);
            root->right=nullptr;
        }
        
    }
    
    void add(TreeNode* root,unordered_set<int> &us){
        if(!root) return;
        if(us.find(root->val)!=us.end()) return;
        res.push_back(root);
        
    }
};