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
    
    // 先中序遍历子树，然后看看是否有序
    bool isValidBST1(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> s;
        TreeNode* t=root;
        while(t || !s.empty()){
            while(t){
                s.push(t);
                t=t->left;
            }
            
            t=s.top(),s.pop();
            vec.push_back(t->val);
            
            t=t->right;
        }
        auto it=std::unique(vec.begin(), vec.end());
        if(it!=vec.end()) return false;
        return is_sorted(vec.begin(),vec.end());
    }
    
    // 升级版：
    // https://leetcode.com/problems/validate-binary-search-tree/discuss/32112/Learn-one-iterative-inorder-traversal-apply-it-to-multiple-tree-questions-(Java-Solution)
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*>  s;
        TreeNode* t=root;
        TreeNode* pre=nullptr;
        while(!s.empty() || t){
            while(t){
                s.push(t);
                t=t->left;
            }
            
            t=s.top(),s.pop();
            if(pre && pre->val>=t->val) return false;
            pre=t;
            
            t=t->right;
        }
        return true;
    }
    
};