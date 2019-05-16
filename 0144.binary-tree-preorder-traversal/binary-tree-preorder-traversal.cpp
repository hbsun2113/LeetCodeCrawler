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
    //参考了https://leetcode.com/problems/binary-tree-preorder-traversal/discuss/45266/Accepted-iterative-solution-in-Java-using-stack.
    // vector<int> preorderTraversal(TreeNode* root) {
    //     stack<TreeNode*> right;
    //     TreeNode* cur=root;
    //     vector<int> result;
    //     if(!root) return result;
    //     while(cur){
    //         result.push_back(cur->val);  //当前节点可以直接被压进去
    //         if(cur->right) right.push(cur->right); //保留右儿子
    //         cur=cur->left;//当前节点处理完，优先处理左儿子
    //         if(!cur && !right.empty()){
    //             cur=right.top();
    //             right.pop();
    //         }
    //     }
    //     return result;
    // }
    
    
    //解法二，自己写的，注意先压右儿子
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* cur=root;
        vector<int> result;
        if(!root) return result;
        s.push(cur);
        while(!s.empty()){
            cur=s.top();
            s.pop();
            result.push_back(cur->val);
            if(cur->right) s.push(cur->right);
            if(cur->left) s.push(cur->left);
        }
        return result;
    }
};