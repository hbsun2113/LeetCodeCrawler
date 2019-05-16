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
    bool isSymmetric(TreeNode* root){
        stack<TreeNode*> s1,s2;
        auto t1=root,t2=root;
        while(t1 || !s1.empty()){
            while(t1 && t2){
                s1.push(t1);
                t1=t1->left;
                s2.push(t2);
                t2=t2->right;
            }
            if(t1 || t2) return false;
            
            t1=s1.top();
            s1.pop();
            t2=s2.top();
            s2.pop();
            if(t1->val!=t2->val) return false;
            
            t1=t1->right;
            t2=t2->left;
        }
        return true;
    }
    
};