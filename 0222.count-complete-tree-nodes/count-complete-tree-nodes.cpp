/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
若设二叉树的深度为h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，第 h 层所有的结点都连续集中在最左边，这就是完全二叉树。
*/
class Solution {
public:
    //参考：http://www.cnblogs.com/grandyang/p/4567827.html
    //虽然思路巧妙，但是发现还不如暴力求解快呢。
    int countNodes(TreeNode* root) {
        int lh=0,rh=0;
        TreeNode *rn=root,*ln=root;
        while(ln){
            lh++;
            ln=ln->left;
        }
        while(rn){
            rh++;
            rn=rn->right;
        }
        if(lh==rh) return pow(2,rh)-1; //是完全二叉树，直接使用公式计算结果
        else return 1+countNodes(root->left)+countNodes(root->right); //否则分别计算结果，然后求和
    }
    
    
    
    
    
    int count=0;
    //暴力求解直接过了？？
    int countNodes1(TreeNode* root) {
        helper(root);
        return count;
    }
    
    void helper(TreeNode* root){
        if(!root) return;
        count++;
        if(root->left) helper(root->left);
        if(root->right) helper(root->right);
    }
};