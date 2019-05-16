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
    //迭代做法2 BFS
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;  // 按层存储
        q.emplace(root);
        int mx=0;
        while(!q.empty()){
            int size=q.size(); //先记录本层有多少个节点
            while(--size>=0){  //while(size-->0){
                TreeNode* n=q.front();
                q.pop();
                if(n->left) q.emplace(n->left);
                if(n->right) q.emplace(n->right);
            }
            mx++;
        }
        return mx;
    }
    
    
    
    //迭代做法1 DFS
    int maxDepth2(TreeNode* root) {
        if(!root) return 0;
        int mx=INT_MIN;
        stack<TreeNode*> sn;
        stack<int> si;
        sn.emplace(root);
        si.emplace(1);
        while(!sn.empty()){
            TreeNode* n=sn.top();
            int len=si.top();
            sn.pop();
            si.pop();
            mx=max(mx,len);
            if(n->left){
                sn.emplace(n->left);
                si.emplace(len+1);
            }
            if(n->right){
                sn.emplace(n->right);
                si.emplace(len+1);
            }
        }
        return mx;
    }
    
    
    
    //递归做法
    int maxDepth1(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int res=max(maxDepth(root->left),maxDepth(root->right))+1;
        return res;
    }
};