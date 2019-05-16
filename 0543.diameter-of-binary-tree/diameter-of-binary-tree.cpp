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
    // 三刷，快速AC
    int diameterOfBinaryTree(TreeNode* root){
        if(!root) return 0;
        res=1;
        dfs(root);
        return res-1;
    }
    
    int dfs(TreeNode* root){
        if(!root) return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        res=max(res,l+r+1);
        return max(l,r)+1;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //二刷竟然觉得难，做了很久，AC的思路感觉也不太好，应该是做麻烦了。
    int res;
    int diameterOfBinaryTree2(TreeNode* root) {
        res=0;
        helper(root);
        return res;
    }
    
    int helper(TreeNode* root) {  //返回的是本节点所能拥有的最长路径的长度，但不是转折点
        if(!root) return 0;
        if(!root->left && !root->right) return 0;
        int count=0; //标记是否有两个儿子。
        if(!root->left || !root->right) count=1;
        int left=helper(root->left);
        int right=helper(root->right);
        res=max(res,left+right+2-count); //查看以本节点为转折点，所能拥有的最长路径。
        cout<<root->val<<" "<<left<<" "<<right<<endl;
        return max(left,right)+1;   
    }
    
    
    
    
    
    
    
    //一刷，水题。
    int result=-1;
    
    int diameterOfBinaryTree1(TreeNode* root) {
        if(!root) return 0;
        part(root);
        return result-1;
    }
    
    int part(TreeNode* root){  //返回的是最多节点数目。
        if(!root) return 0;
        int left=part(root->left);
        int right=part(root->right);
        int length=left+right+1;
        //cout<<root->val<<" "<<length<<endl;
        result=max(result,length);
        return 1+max(left,right);
    }
    
    
    
};