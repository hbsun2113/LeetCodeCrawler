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
    
    //hbsun:完全自己做的,直接在本子上画个树的结构，做一下中序遍历和后续遍历就可以了。 
    //总体思路就是先在postorder中找到当前的根节点，然后将inorder划分为两个子集(分别是左子树的inorder和右子树的inorder)，然后将postorder划分为两个子集(分别是左子树的postorder和右子树的postorder)，然后递归处理就可以了。
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) { 
        if(inorder.size()==0) return NULL;//如果为空，自然返回空。
        int root_value=postorder[postorder.size()-1];
        TreeNode *root=new TreeNode(root_value);
        if(inorder.size()==1) return root;//如果当前只有一个节点了，直接返回它作为根节点就可以了。
        vector<int> in_l;
        vector<int> in_r;
        bool isleft=true;
        for(int i=0;i<inorder.size();i++){
            if(isleft){
                if(inorder[i]!=root_value){
                    in_l.push_back(inorder[i]);
                }
                else{
                    isleft=false;
                }
            }
            else{
                in_r.push_back(inorder[i]);
            }
        }
        vector<int> po_l;
        vector<int> po_r;
        for(int i=0;i<in_l.size();i++){
            po_l.push_back(postorder[i]);
        }
        for(int i=in_l.size();i<postorder.size()-1;i++){
            po_r.push_back(postorder[i]);
        }
        
        // cout<<"root="<<root->val<<endl;
        // for(int i=0;i<in_l.size();i++){
        //     cout<<in_l[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<in_r.size();i++){
        //     cout<<in_r[i]<<" ";
        // }
        // cout<<endl;
        
        root->left=buildTree(in_l,po_l);
        root->right=buildTree(in_r,po_r);
        return root;
        
        
        
    }
};