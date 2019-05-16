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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(same(s,t)) return true;
        /*这段写得太麻烦了，换成下面的形式
        bool flag=false;
        if(s->left) flag=isSubtree(s->left,t);
        if(flag) return true;
        if(s->right) flag=isSubtree(s->right,t);
        if(flag) return true;
        return false;
        */
        if(!s || !t) return false;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
    bool same(TreeNode* l, TreeNode* r){
        if(!l && !r) return true;
        if((l&&!r) || (!l&&r)) return false;
        if(l->val!=r->val) return false;
        return (same(l->left,r->left)&&same(l->right,r->right));
    }
};