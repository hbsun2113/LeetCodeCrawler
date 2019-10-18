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
    
    // https://leetcode.com/problems/binary-tree-coloring-game/discuss/350570/JavaC++Python-Simple-recursion-and-Follow-Up?orderBy=most_votes
    // ????????????????
    // y???????x?????????????????(??seek???left?right)
    int left=0;
    int right=0;
    int val;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        val=x;
        seek(root);
        cout<<left<<" "<<right<<endl;
        int maxv=max(max(left,right),n-left-right-1);
        if(maxv>n/2) return true;
        else return false;
    }
    
    
    int seek(TreeNode* root){
        if(!root) return 0;
        if(root->val==val){
            left=seek(root->left);
            right=seek(root->right);
            return left+right+1;
        } 
        else{
            int l=seek(root->left);
            int r=seek(root->right);
            return l+r+1;
        }
    }
    
};