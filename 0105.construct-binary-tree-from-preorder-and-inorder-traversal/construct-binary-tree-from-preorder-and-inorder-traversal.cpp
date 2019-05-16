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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return nullptr;
        int n=preorder[0];
        TreeNode *root=new TreeNode(n);
        vector<int> pre_left;
        vector<int> pre_right;
        vector<int> in_left;
        vector<int> in_right;
        int index=0;
        while(inorder[index]!=n){
            in_left.push_back(inorder[index++]);
        }
        index++;
        while(index<inorder.size()){
            in_right.push_back(inorder[index++]);
        }
        for(int i=0;i<in_left.size();i++){
            pre_left.push_back(preorder[i+1]);
        }
        for(int i=1+in_left.size();i<preorder.size();i++){
            pre_right.push_back(preorder[i]);
        }
        root->left=buildTree(pre_left,in_left);
        root->right=buildTree(pre_right,in_right);
        return root;
    }
};